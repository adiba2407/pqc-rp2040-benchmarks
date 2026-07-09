/*
 * bench_slhdsa.c — SLH-DSA benchmark
 */

#include "bench_harness.h"
#include "slh_dsa.h"
#include "randombytes.h"

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

static const uint8_t test_message[] =
    "This is a test message for SLH-DSA benchmarking.";

static const size_t test_message_len =
    sizeof(test_message) - 1;

int main(void)
{
    bench_init();
    bench_csv_header();

    printf("SLH-DSA benchmark starting...\n");

    /* Select parameter set */
const slh_param_t *params[] = {
    &slh_dsa_sha2_128s,
    &slh_dsa_sha2_192s,
    &slh_dsa_sha2_256s
};

const int security[] = {128, 192, 256};

for (int i = 0; i < 3; i++)
{
    const slh_param_t *prm = params[i];
    int sec = security[i];

    size_t pk_len = slh_pk_sz(prm);
    size_t sk_len = slh_sk_sz(prm);
    size_t sig_len = slh_sig_sz(prm);

    uint8_t pk[pk_len];
    uint8_t sk[sk_len];
    uint8_t sig[sig_len];

    size_t produced_sig_len = 0;

    printf("Testing parameter set: %s\n", slh_alg_id(prm));

    /* ==========================================
       KEY GENERATION BENCHMARK
       ========================================== */

    BENCH_RUN("SLH-DSA", "keygen", sec, {

        if (slh_keygen(sk, pk, randombytes, prm) != 0)
        {
            printf("Key generation failed!\n");
        }

    });

    printf("Finished KeyGen benchmark\n");

    /* Generate one key pair for signing */
    if (slh_keygen(sk, pk, randombytes, prm) != 0)
    {
        printf("Key generation failed!\n");
        return 1;
    }

    printf("Generated key pair\n");

    /* ==========================================
       SIGNATURE GENERATION BENCHMARK
       ========================================== */

    printf("Starting Sign benchmark\n");

    BENCH_RUN("SLH-DSA", "sign", sec, {

        produced_sig_len = slh_sign(
            sig,
            test_message,
            test_message_len,
            NULL,
            0,
            sk,
            NULL,
            prm
        );

        if (produced_sig_len == 0)
        {
            printf("Signature generation failed!\n");
        }

    });

    /* Generate ONE valid signature for verification */
    produced_sig_len = slh_sign(
        sig,
        test_message,
        test_message_len,
        NULL,
        0,
        sk,
        NULL,
        prm
    );

    if (produced_sig_len == 0)
    {
        printf("Signature generation failed!\n");
        return 1;
    }

    printf("Signature generated (%u bytes)\n",
           (unsigned int)produced_sig_len);

    /* ==========================================
       SIGNATURE VERIFICATION BENCHMARK
       ========================================== */

    printf("Starting Verify benchmark\n");

    BENCH_RUN("SLH-DSA", "verify", sec, {

        int result = slh_verify(
            test_message,
            test_message_len,
            sig,
            produced_sig_len,
            NULL,
            0,
            pk,
            prm
        );

        if (result != 1)
        {
            printf("Signature verification failed!\n");
        }

    });

    printf("Finished %s\n\n", slh_alg_id(prm));

    printf("========================================\n");

}

    while (true)
    {
        sleep_ms(1000);
    }

    return 0;
}