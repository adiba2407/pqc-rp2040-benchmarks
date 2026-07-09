# PQC Benchmarking on Raspberry Pi Pico (RP2040)

This repository contains the source code and benchmark results for the implementation and evaluation of the NIST-standardized post-quantum cryptographic algorithms on the Raspberry Pi Pico (RP2040).

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

## Algorithms

### FIPS 203 (ML-KEM)
Benchmark operations:
- Key Generation
- Encapsulation
- Decapsulation

### FIPS 204 (ML-DSA)
Benchmark operations:
- Key Generation
- Signature Generation
- Signature Verification

## Performance Metrics

The benchmark results include:

- Mean execution time
- Minimum execution time
- Maximum execution time
- Standard deviation
- Coefficient of variation (CV)

## License

This repository is provided for research and educational purposes.
