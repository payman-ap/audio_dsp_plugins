#include <stdlib.h>
#include <lv2.h>

#define PLUGIN_URI "http://example.org/stereo-sum"

typedef struct {
    const float* in_left;
    const float* in_right;
    float* out_left;
    float* out_right;
} StereoSum;

static LV2_Handle instantiate(
    const LV2_Descriptor* descriptor,
    double rate,
    const char* bundle_path,
    const LV2_Feature* const* features)
{
    return calloc(1, sizeof(StereoSum));
}

static void connect_port(LV2_Handle instance, uint32_t port, void* data) {
    StereoSum* self = (StereoSum*)instance;
    switch (port) {
        case 0: self->in_left = data; break;
        case 1: self->in_right = data; break;
        case 2: self->out_left = data; break;
        case 3: self->out_right = data; break;
    }
}

static void run(LV2_Handle instance, uint32_t n_samples) {
    StereoSum* self = (StereoSum*)instance;
    for (uint32_t i = 0; i < n_samples; ++i) {
        float mono = self->in_left[i] + self->in_right[i];
        self->out_left[i]  = mono;
        self->out_right[i] = mono;
    }
}

static void cleanup(LV2_Handle instance) {
    free(instance);
}

static const LV2_Descriptor descriptor = {
    PLUGIN_URI,
    instantiate,
    connect_port,
    NULL, // activate
    run,
    NULL, // deactivate
    cleanup,
    NULL  // extension_data
};

LV2_SYMBOL_EXPORT const LV2_Descriptor* lv2_descriptor(uint32_t index) {
    return (index == 0) ? &descriptor : NULL;
}
