# PQC Benchmarking on Raspberry Pi Pico (RP2040)

This repository contains the source code and benchmark results for the implementation and evaluation of NIST-standardized post-quantum cryptographic algorithms on the Raspberry Pi Pico (RP2040). It includes benchmarks for both post-quantum key encapsulation and digital signature algorithms across multiple NIST security levels.

## Repository Structure

```
pqc-rp2040-benchmarks/
│
├── FIPS203/
│   ├── source/
│   └── results/
│
├── FIPS204/
│   ├── source/
│   └── results/
│
├── FIPS205/
│   ├── source/
│   └── results/
│
└── README.md
```

## Hardware Platform

- Raspberry Pi Pico (RP2040)
- ARM Cortex-M0+
- 133 MHz CPU
- 264 KB SRAM
- 2 MB Flash

## Software Environment

- Raspberry Pi Pico SDK
- ARM GNU Embedded Toolchain
- CMake
- PQClean Reference Implementations
- SLH-DSA Reference Implementation

## Algorithms

### FIPS 203 (ML-KEM)
Benchmark operations:
- Key Generation
- Encapsulation
- Decapsulation

Supported security levels:
- ML-KEM-512
- ML-KEM-768
- ML-KEM-1024

### FIPS 204 (ML-DSA)
Benchmark operations:
- Key Generation
- Signature Generation
- Signature Verification

Supported security levels:
- ML-DSA-44
- ML-DSA-65
- ML-DSA-87

### FIPS 205 (SLH-DSA)
Benchmark operations:
- Key Generation
- Signature Generation
- Signature Verification

Supported security levels:
- SLH-DSA-SHA2-128s
- SLH-DSA-SHA2-192s
- SLH-DSA-SHA2-256s

## Performance Metrics

The benchmark results include:

- Mean execution time
- Minimum execution time
- Maximum execution time
- Standard deviation
- Coefficient of variation (CV)

These metrics enable performance comparison of NIST post-quantum cryptographic algorithms on resource-constrained embedded platforms.

## License

This repository is provided for research and educational purposes.
