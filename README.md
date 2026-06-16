# SPARROW Public SDK

Welcome to the public distribution point for Project SPARROW—a high-assurance, decentralized mesh networking protocol layer designed for quantum-resistant operations.

This repository serves as the deployment target for pre-compiled cryptographic library assets, allowing external target integration and linking into sovereign environments such as NTOS (New Testament Organal System).

## Distributed Artifacts

### 1. `lib/libmesh_sparrow.a`
* **Target Architecture:** `aarch64-linux-android`
* **Cryptographic Primitive:** ML-DSA-65 (Module-Lattice-Based Digital Signature Standard, FIPS 204 Compliant).
* **Purpose:** Linkage into bare-metal systems, low-overhead environments, and embedded security runtimes requiring post-quantum transport security.

## Integration Paradigm
To utilize this pre-compiled asset within your external build system, map your linker flags to include the library search path, the static asset, and the required system math library (`-lm`):

```bash
clang -O2 \
  -I./include \
  examples/node_connect.c \
  -L./lib \
  -lmesh_sparrow \
  -lm \
  -o node_connect
