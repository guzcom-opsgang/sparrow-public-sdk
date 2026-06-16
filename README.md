# SPARROW Public SDK

Welcome to the public distribution point for Project SPARROW—a high-assurance, decentralized mesh networking protocol layer designed for quantum-resistant operations.

This repository serves as the deployment target for pre-compiled cryptographic library assets, allowing external target integration and linking into sovereign environments such as NTOS (New Testament Organal System).

## Distributed Artifacts

### 1. `libmesh_sparrow.a`
* **Target Architecture:** `aarch64-linux-android`
* **Cryptographic Primitive:** ML-DSA-65 (Module-Lattice-Based Digital Signature Standard, FIPS 204 Compliant).
* **Purpose:** Linkage into bare-metal systems, low-overhead environments, and embedded security runtimes requiring post-quantum transport security.

## Integration Paradigm
To utilize this pre-compiled asset within your external build system, map your linker flags to look for the static library entry point:

```bash
-L native=/path/to/sdk/ -l mesh_sparrow
```
