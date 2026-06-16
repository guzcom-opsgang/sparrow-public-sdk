#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../include/sparrow.h"

int main(void) {
    printf("[SPARROW] Initializing high-assurance node interface...\n");

    // Allocate memory for the node context structure
    SparrowNodeContext node_ctx;
    memset(&node_ctx, 0, sizeof(SparrowNodeContext));

    // 1. Initialize the engine state machine
    int32_t init_status = sparrow_node_init(&node_ctx);
    if (init_status != 0) {
        fprintf(stderr, "[ERROR] Critical engine initialization failure: %d\n", init_status);
        return init_status;
    }
    printf("[SUCCESS] Node cryptographic state established.\n");

    // 2. Mocking inbound payload and post-quantum network credentials
    uint8_t mock_pub_key[SPARROW_ML_DSA_65_PUBLIC_KEY_BYTES] = {0};
    uint8_t mock_signature[SPARROW_ML_DSA_65_SIGNATURE_BYTES] = {0};
    uint8_t mock_payload[] = "SYS_BOOT_ATTESTATION_TOKEN";
    size_t payload_len = sizeof(mock_payload) - 1;

    printf("[SPARROW] Executing ML-DSA-65 lattice signature verification...\n");

    // 3. Trigger verification loop against the compiled Rust engine boundary
    int32_t verify_status = sparrow_node_verify_identity(
        mock_pub_key, 
        mock_signature, 
        mock_payload, 
        payload_len
    );

    if (verify_status != 0) {
        printf("[WARN] Security Profile: [ISOLATED] DISSONANCE RECOGNIZED\n");
        sparrow_node_isolate_dissonance();
        return 1;
    }

    printf("[SUCCESS] Transport identity authenticated. Proceeding to trusted link state.\n");
    return 0;
}
