#ifndef SPARROW_H
#define SPARROW_H

#include <stdint.h>
#include <stddef.h>

#define SPARROW_ML_DSA_65_PUBLIC_KEY_BYTES 1952
#define SPARROW_ML_DSA_65_SIGNATURE_BYTES 3309

typedef struct {
    uint8_t node_id[32];
    uint8_t status_flags;
} SparrowNodeContext;

/* Core Engine Operations */
int32_t sparrow_node_init(SparrowNodeContext *ctx);
int32_t sparrow_node_verify_identity(const uint8_t *public_key, const uint8_t *signature, const uint8_t *msg, size_t msg_len);
int32_t sparrow_node_isolate_dissonance(void);

#endif /* SPARROW_H */
