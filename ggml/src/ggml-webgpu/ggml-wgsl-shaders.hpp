// Auto-generated shader embedding

const char* wgsl_add_f32 = R"(enable f16;
struct Params {
    ne: u32,

    // offsets in elements
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    stride_src1_0: u32,
    stride_src1_1: u32,
    stride_src1_2: u32,
    stride_src1_3: u32,

    a_ne0: u32,
    a_ne1: u32,
    a_ne2: u32,

    b_ne0: u32,
    b_ne1: u32,
    b_ne2: u32,
    b_ne3: u32,
};

fn src1_index(_i: u32) -> u32 {
    var i = _i;
    let a_i3 = i / (params.a_ne2 * params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne2 * params.a_ne1 * params.a_ne0);
    let a_i2 = i / (params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne1 * params.a_ne0);
    let a_i1 = i / params.a_ne0;
    let a_i0 = i % params.a_ne0;

    // handle repetition of b
    // index loops back to the beginning and repeats after elements are exhausted = modulo
    let b_i0 = a_i0 % params.b_ne0;
    let b_i1 = a_i1 % params.b_ne1;
    let b_i2 = a_i2 % params.b_ne2;
    let b_i3 = a_i3 % params.b_ne3;

    // compute index for position in b's flat array
    return b_i0 * params.stride_src1_0 +
           b_i1 * params.stride_src1_1 +
           b_i2 * params.stride_src1_2 +
           b_i3 * params.stride_src1_3;
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f32>;

fn update(dst_i: u32, src0_i: u32, src1_i: u32) {
    dst[dst_i] = src0[src0_i] + src1[src1_i];
}

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(3)
var<uniform> params: Params;



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x < params.ne) {
        update(params.offset_dst + gid.x, params.offset_src0 + gid.x, params.offset_src1 + src1_index(gid.x));
    }
})";

const char* wgsl_add_f16 = R"(enable f16;
struct Params {
    ne: u32,

    // offsets in elements
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    stride_src1_0: u32,
    stride_src1_1: u32,
    stride_src1_2: u32,
    stride_src1_3: u32,

    a_ne0: u32,
    a_ne1: u32,
    a_ne2: u32,

    b_ne0: u32,
    b_ne1: u32,
    b_ne2: u32,
    b_ne3: u32,
};

fn src1_index(_i: u32) -> u32 {
    var i = _i;
    let a_i3 = i / (params.a_ne2 * params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne2 * params.a_ne1 * params.a_ne0);
    let a_i2 = i / (params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne1 * params.a_ne0);
    let a_i1 = i / params.a_ne0;
    let a_i0 = i % params.a_ne0;

    // handle repetition of b
    // index loops back to the beginning and repeats after elements are exhausted = modulo
    let b_i0 = a_i0 % params.b_ne0;
    let b_i1 = a_i1 % params.b_ne1;
    let b_i2 = a_i2 % params.b_ne2;
    let b_i3 = a_i3 % params.b_ne3;

    // compute index for position in b's flat array
    return b_i0 * params.stride_src1_0 +
           b_i1 * params.stride_src1_1 +
           b_i2 * params.stride_src1_2 +
           b_i3 * params.stride_src1_3;
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f16>;

fn update(dst_i: u32, src0_i: u32, src1_i: u32) {
    dst[dst_i] = src0[src0_i] + src1[src1_i];
}

@group(0) @binding(2)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(3)
var<uniform> params: Params;



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x < params.ne) {
        update(params.offset_dst + gid.x, params.offset_src0 + gid.x, params.offset_src1 + src1_index(gid.x));
    }
})";

const char* wgsl_add_f32_inplace = R"(enable f16;
struct Params {
    ne: u32,

    // offsets in elements
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    stride_src1_0: u32,
    stride_src1_1: u32,
    stride_src1_2: u32,
    stride_src1_3: u32,

    a_ne0: u32,
    a_ne1: u32,
    a_ne2: u32,

    b_ne0: u32,
    b_ne1: u32,
    b_ne2: u32,
    b_ne3: u32,
};

fn src1_index(_i: u32) -> u32 {
    var i = _i;
    let a_i3 = i / (params.a_ne2 * params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne2 * params.a_ne1 * params.a_ne0);
    let a_i2 = i / (params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne1 * params.a_ne0);
    let a_i1 = i / params.a_ne0;
    let a_i0 = i % params.a_ne0;

    // handle repetition of b
    // index loops back to the beginning and repeats after elements are exhausted = modulo
    let b_i0 = a_i0 % params.b_ne0;
    let b_i1 = a_i1 % params.b_ne1;
    let b_i2 = a_i2 % params.b_ne2;
    let b_i3 = a_i3 % params.b_ne3;

    // compute index for position in b's flat array
    return b_i0 * params.stride_src1_0 +
           b_i1 * params.stride_src1_1 +
           b_i2 * params.stride_src1_2 +
           b_i3 * params.stride_src1_3;
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f32>;

fn update(dst_i: u32, src0_i: u32, src1_i: u32) {
    src0[dst_i] = src0[src0_i] + src1[src1_i];
}

@group(0) @binding(2)
var<uniform> params: Params;



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x < params.ne) {
        update(params.offset_dst + gid.x, params.offset_src0 + gid.x, params.offset_src1 + src1_index(gid.x));
    }
})";

const char* wgsl_add_f16_inplace = R"(enable f16;
struct Params {
    ne: u32,

    // offsets in elements
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    stride_src1_0: u32,
    stride_src1_1: u32,
    stride_src1_2: u32,
    stride_src1_3: u32,

    a_ne0: u32,
    a_ne1: u32,
    a_ne2: u32,

    b_ne0: u32,
    b_ne1: u32,
    b_ne2: u32,
    b_ne3: u32,
};

fn src1_index(_i: u32) -> u32 {
    var i = _i;
    let a_i3 = i / (params.a_ne2 * params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne2 * params.a_ne1 * params.a_ne0);
    let a_i2 = i / (params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne1 * params.a_ne0);
    let a_i1 = i / params.a_ne0;
    let a_i0 = i % params.a_ne0;

    // handle repetition of b
    // index loops back to the beginning and repeats after elements are exhausted = modulo
    let b_i0 = a_i0 % params.b_ne0;
    let b_i1 = a_i1 % params.b_ne1;
    let b_i2 = a_i2 % params.b_ne2;
    let b_i3 = a_i3 % params.b_ne3;

    // compute index for position in b's flat array
    return b_i0 * params.stride_src1_0 +
           b_i1 * params.stride_src1_1 +
           b_i2 * params.stride_src1_2 +
           b_i3 * params.stride_src1_3;
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f16>;

fn update(dst_i: u32, src0_i: u32, src1_i: u32) {
    src0[dst_i] = src0[src0_i] + src1[src1_i];
}

@group(0) @binding(2)
var<uniform> params: Params;



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x < params.ne) {
        update(params.offset_dst + gid.x, params.offset_src0 + gid.x, params.offset_src1 + src1_index(gid.x));
    }
})";

const char* wgsl_mul_f32 = R"(enable f16;
struct Params {
    ne: u32,

    // offsets in elements
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    stride_src1_0: u32,
    stride_src1_1: u32,
    stride_src1_2: u32,
    stride_src1_3: u32,

    a_ne0: u32,
    a_ne1: u32,
    a_ne2: u32,

    b_ne0: u32,
    b_ne1: u32,
    b_ne2: u32,
    b_ne3: u32,
};

fn src1_index(_i: u32) -> u32 {
    var i = _i;
    let a_i3 = i / (params.a_ne2 * params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne2 * params.a_ne1 * params.a_ne0);
    let a_i2 = i / (params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne1 * params.a_ne0);
    let a_i1 = i / params.a_ne0;
    let a_i0 = i % params.a_ne0;

    // handle repetition of b
    // index loops back to the beginning and repeats after elements are exhausted = modulo
    let b_i0 = a_i0 % params.b_ne0;
    let b_i1 = a_i1 % params.b_ne1;
    let b_i2 = a_i2 % params.b_ne2;
    let b_i3 = a_i3 % params.b_ne3;

    // compute index for position in b's flat array
    return b_i0 * params.stride_src1_0 +
           b_i1 * params.stride_src1_1 +
           b_i2 * params.stride_src1_2 +
           b_i3 * params.stride_src1_3;
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f32>;

fn update(dst_i: u32, src0_i: u32, src1_i: u32) {
    dst[dst_i] = src0[src0_i] * src1[src1_i];
}

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(3)
var<uniform> params: Params;



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x < params.ne) {
        update(params.offset_dst + gid.x, params.offset_src0 + gid.x, params.offset_src1 + src1_index(gid.x));
    }
})";

const char* wgsl_mul_f16 = R"(enable f16;
struct Params {
    ne: u32,

    // offsets in elements
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    stride_src1_0: u32,
    stride_src1_1: u32,
    stride_src1_2: u32,
    stride_src1_3: u32,

    a_ne0: u32,
    a_ne1: u32,
    a_ne2: u32,

    b_ne0: u32,
    b_ne1: u32,
    b_ne2: u32,
    b_ne3: u32,
};

fn src1_index(_i: u32) -> u32 {
    var i = _i;
    let a_i3 = i / (params.a_ne2 * params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne2 * params.a_ne1 * params.a_ne0);
    let a_i2 = i / (params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne1 * params.a_ne0);
    let a_i1 = i / params.a_ne0;
    let a_i0 = i % params.a_ne0;

    // handle repetition of b
    // index loops back to the beginning and repeats after elements are exhausted = modulo
    let b_i0 = a_i0 % params.b_ne0;
    let b_i1 = a_i1 % params.b_ne1;
    let b_i2 = a_i2 % params.b_ne2;
    let b_i3 = a_i3 % params.b_ne3;

    // compute index for position in b's flat array
    return b_i0 * params.stride_src1_0 +
           b_i1 * params.stride_src1_1 +
           b_i2 * params.stride_src1_2 +
           b_i3 * params.stride_src1_3;
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f16>;

fn update(dst_i: u32, src0_i: u32, src1_i: u32) {
    dst[dst_i] = src0[src0_i] * src1[src1_i];
}

@group(0) @binding(2)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(3)
var<uniform> params: Params;



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x < params.ne) {
        update(params.offset_dst + gid.x, params.offset_src0 + gid.x, params.offset_src1 + src1_index(gid.x));
    }
})";

const char* wgsl_mul_f32_inplace = R"(enable f16;
struct Params {
    ne: u32,

    // offsets in elements
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    stride_src1_0: u32,
    stride_src1_1: u32,
    stride_src1_2: u32,
    stride_src1_3: u32,

    a_ne0: u32,
    a_ne1: u32,
    a_ne2: u32,

    b_ne0: u32,
    b_ne1: u32,
    b_ne2: u32,
    b_ne3: u32,
};

fn src1_index(_i: u32) -> u32 {
    var i = _i;
    let a_i3 = i / (params.a_ne2 * params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne2 * params.a_ne1 * params.a_ne0);
    let a_i2 = i / (params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne1 * params.a_ne0);
    let a_i1 = i / params.a_ne0;
    let a_i0 = i % params.a_ne0;

    // handle repetition of b
    // index loops back to the beginning and repeats after elements are exhausted = modulo
    let b_i0 = a_i0 % params.b_ne0;
    let b_i1 = a_i1 % params.b_ne1;
    let b_i2 = a_i2 % params.b_ne2;
    let b_i3 = a_i3 % params.b_ne3;

    // compute index for position in b's flat array
    return b_i0 * params.stride_src1_0 +
           b_i1 * params.stride_src1_1 +
           b_i2 * params.stride_src1_2 +
           b_i3 * params.stride_src1_3;
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f32>;

fn update(dst_i: u32, src0_i: u32, src1_i: u32) {
    src0[dst_i] = src0[src0_i] * src1[src1_i];
}

@group(0) @binding(2)
var<uniform> params: Params;



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x < params.ne) {
        update(params.offset_dst + gid.x, params.offset_src0 + gid.x, params.offset_src1 + src1_index(gid.x));
    }
})";

const char* wgsl_mul_f16_inplace = R"(enable f16;
struct Params {
    ne: u32,

    // offsets in elements
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    stride_src1_0: u32,
    stride_src1_1: u32,
    stride_src1_2: u32,
    stride_src1_3: u32,

    a_ne0: u32,
    a_ne1: u32,
    a_ne2: u32,

    b_ne0: u32,
    b_ne1: u32,
    b_ne2: u32,
    b_ne3: u32,
};

fn src1_index(_i: u32) -> u32 {
    var i = _i;
    let a_i3 = i / (params.a_ne2 * params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne2 * params.a_ne1 * params.a_ne0);
    let a_i2 = i / (params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne1 * params.a_ne0);
    let a_i1 = i / params.a_ne0;
    let a_i0 = i % params.a_ne0;

    // handle repetition of b
    // index loops back to the beginning and repeats after elements are exhausted = modulo
    let b_i0 = a_i0 % params.b_ne0;
    let b_i1 = a_i1 % params.b_ne1;
    let b_i2 = a_i2 % params.b_ne2;
    let b_i3 = a_i3 % params.b_ne3;

    // compute index for position in b's flat array
    return b_i0 * params.stride_src1_0 +
           b_i1 * params.stride_src1_1 +
           b_i2 * params.stride_src1_2 +
           b_i3 * params.stride_src1_3;
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f16>;

fn update(dst_i: u32, src0_i: u32, src1_i: u32) {
    src0[dst_i] = src0[src0_i] * src1[src1_i];
}

@group(0) @binding(2)
var<uniform> params: Params;



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x < params.ne) {
        update(params.offset_dst + gid.x, params.offset_src0 + gid.x, params.offset_src1 + src1_index(gid.x));
    }
})";

const char* wgsl_sub_f32 = R"(enable f16;
struct Params {
    ne: u32,

    // offsets in elements
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    stride_src1_0: u32,
    stride_src1_1: u32,
    stride_src1_2: u32,
    stride_src1_3: u32,

    a_ne0: u32,
    a_ne1: u32,
    a_ne2: u32,

    b_ne0: u32,
    b_ne1: u32,
    b_ne2: u32,
    b_ne3: u32,
};

fn src1_index(_i: u32) -> u32 {
    var i = _i;
    let a_i3 = i / (params.a_ne2 * params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne2 * params.a_ne1 * params.a_ne0);
    let a_i2 = i / (params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne1 * params.a_ne0);
    let a_i1 = i / params.a_ne0;
    let a_i0 = i % params.a_ne0;

    // handle repetition of b
    // index loops back to the beginning and repeats after elements are exhausted = modulo
    let b_i0 = a_i0 % params.b_ne0;
    let b_i1 = a_i1 % params.b_ne1;
    let b_i2 = a_i2 % params.b_ne2;
    let b_i3 = a_i3 % params.b_ne3;

    // compute index for position in b's flat array
    return b_i0 * params.stride_src1_0 +
           b_i1 * params.stride_src1_1 +
           b_i2 * params.stride_src1_2 +
           b_i3 * params.stride_src1_3;
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f32>;

fn update(dst_i: u32, src0_i: u32, src1_i: u32) {
    dst[dst_i] = src0[src0_i] - src1[src1_i];
}

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(3)
var<uniform> params: Params;



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x < params.ne) {
        update(params.offset_dst + gid.x, params.offset_src0 + gid.x, params.offset_src1 + src1_index(gid.x));
    }
})";

const char* wgsl_sub_f16 = R"(enable f16;
struct Params {
    ne: u32,

    // offsets in elements
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    stride_src1_0: u32,
    stride_src1_1: u32,
    stride_src1_2: u32,
    stride_src1_3: u32,

    a_ne0: u32,
    a_ne1: u32,
    a_ne2: u32,

    b_ne0: u32,
    b_ne1: u32,
    b_ne2: u32,
    b_ne3: u32,
};

fn src1_index(_i: u32) -> u32 {
    var i = _i;
    let a_i3 = i / (params.a_ne2 * params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne2 * params.a_ne1 * params.a_ne0);
    let a_i2 = i / (params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne1 * params.a_ne0);
    let a_i1 = i / params.a_ne0;
    let a_i0 = i % params.a_ne0;

    // handle repetition of b
    // index loops back to the beginning and repeats after elements are exhausted = modulo
    let b_i0 = a_i0 % params.b_ne0;
    let b_i1 = a_i1 % params.b_ne1;
    let b_i2 = a_i2 % params.b_ne2;
    let b_i3 = a_i3 % params.b_ne3;

    // compute index for position in b's flat array
    return b_i0 * params.stride_src1_0 +
           b_i1 * params.stride_src1_1 +
           b_i2 * params.stride_src1_2 +
           b_i3 * params.stride_src1_3;
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f16>;

fn update(dst_i: u32, src0_i: u32, src1_i: u32) {
    dst[dst_i] = src0[src0_i] - src1[src1_i];
}

@group(0) @binding(2)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(3)
var<uniform> params: Params;



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x < params.ne) {
        update(params.offset_dst + gid.x, params.offset_src0 + gid.x, params.offset_src1 + src1_index(gid.x));
    }
})";

const char* wgsl_sub_f32_inplace = R"(enable f16;
struct Params {
    ne: u32,

    // offsets in elements
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    stride_src1_0: u32,
    stride_src1_1: u32,
    stride_src1_2: u32,
    stride_src1_3: u32,

    a_ne0: u32,
    a_ne1: u32,
    a_ne2: u32,

    b_ne0: u32,
    b_ne1: u32,
    b_ne2: u32,
    b_ne3: u32,
};

fn src1_index(_i: u32) -> u32 {
    var i = _i;
    let a_i3 = i / (params.a_ne2 * params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne2 * params.a_ne1 * params.a_ne0);
    let a_i2 = i / (params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne1 * params.a_ne0);
    let a_i1 = i / params.a_ne0;
    let a_i0 = i % params.a_ne0;

    // handle repetition of b
    // index loops back to the beginning and repeats after elements are exhausted = modulo
    let b_i0 = a_i0 % params.b_ne0;
    let b_i1 = a_i1 % params.b_ne1;
    let b_i2 = a_i2 % params.b_ne2;
    let b_i3 = a_i3 % params.b_ne3;

    // compute index for position in b's flat array
    return b_i0 * params.stride_src1_0 +
           b_i1 * params.stride_src1_1 +
           b_i2 * params.stride_src1_2 +
           b_i3 * params.stride_src1_3;
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f32>;

fn update(dst_i: u32, src0_i: u32, src1_i: u32) {
    src0[dst_i] = src0[src0_i] - src1[src1_i];
}

@group(0) @binding(2)
var<uniform> params: Params;



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x < params.ne) {
        update(params.offset_dst + gid.x, params.offset_src0 + gid.x, params.offset_src1 + src1_index(gid.x));
    }
})";

const char* wgsl_sub_f16_inplace = R"(enable f16;
struct Params {
    ne: u32,

    // offsets in elements
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    stride_src1_0: u32,
    stride_src1_1: u32,
    stride_src1_2: u32,
    stride_src1_3: u32,

    a_ne0: u32,
    a_ne1: u32,
    a_ne2: u32,

    b_ne0: u32,
    b_ne1: u32,
    b_ne2: u32,
    b_ne3: u32,
};

fn src1_index(_i: u32) -> u32 {
    var i = _i;
    let a_i3 = i / (params.a_ne2 * params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne2 * params.a_ne1 * params.a_ne0);
    let a_i2 = i / (params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne1 * params.a_ne0);
    let a_i1 = i / params.a_ne0;
    let a_i0 = i % params.a_ne0;

    // handle repetition of b
    // index loops back to the beginning and repeats after elements are exhausted = modulo
    let b_i0 = a_i0 % params.b_ne0;
    let b_i1 = a_i1 % params.b_ne1;
    let b_i2 = a_i2 % params.b_ne2;
    let b_i3 = a_i3 % params.b_ne3;

    // compute index for position in b's flat array
    return b_i0 * params.stride_src1_0 +
           b_i1 * params.stride_src1_1 +
           b_i2 * params.stride_src1_2 +
           b_i3 * params.stride_src1_3;
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f16>;

fn update(dst_i: u32, src0_i: u32, src1_i: u32) {
    src0[dst_i] = src0[src0_i] - src1[src1_i];
}

@group(0) @binding(2)
var<uniform> params: Params;



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x < params.ne) {
        update(params.offset_dst + gid.x, params.offset_src0 + gid.x, params.offset_src1 + src1_index(gid.x));
    }
})";

const char* wgsl_div_f32 = R"(enable f16;
struct Params {
    ne: u32,

    // offsets in elements
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    stride_src1_0: u32,
    stride_src1_1: u32,
    stride_src1_2: u32,
    stride_src1_3: u32,

    a_ne0: u32,
    a_ne1: u32,
    a_ne2: u32,

    b_ne0: u32,
    b_ne1: u32,
    b_ne2: u32,
    b_ne3: u32,
};

fn src1_index(_i: u32) -> u32 {
    var i = _i;
    let a_i3 = i / (params.a_ne2 * params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne2 * params.a_ne1 * params.a_ne0);
    let a_i2 = i / (params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne1 * params.a_ne0);
    let a_i1 = i / params.a_ne0;
    let a_i0 = i % params.a_ne0;

    // handle repetition of b
    // index loops back to the beginning and repeats after elements are exhausted = modulo
    let b_i0 = a_i0 % params.b_ne0;
    let b_i1 = a_i1 % params.b_ne1;
    let b_i2 = a_i2 % params.b_ne2;
    let b_i3 = a_i3 % params.b_ne3;

    // compute index for position in b's flat array
    return b_i0 * params.stride_src1_0 +
           b_i1 * params.stride_src1_1 +
           b_i2 * params.stride_src1_2 +
           b_i3 * params.stride_src1_3;
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f32>;

fn update(dst_i: u32, src0_i: u32, src1_i: u32) {
    dst[dst_i] = src0[src0_i] / src1[src1_i];
}

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(3)
var<uniform> params: Params;



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x < params.ne) {
        update(params.offset_dst + gid.x, params.offset_src0 + gid.x, params.offset_src1 + src1_index(gid.x));
    }
})";

const char* wgsl_div_f16 = R"(enable f16;
struct Params {
    ne: u32,

    // offsets in elements
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    stride_src1_0: u32,
    stride_src1_1: u32,
    stride_src1_2: u32,
    stride_src1_3: u32,

    a_ne0: u32,
    a_ne1: u32,
    a_ne2: u32,

    b_ne0: u32,
    b_ne1: u32,
    b_ne2: u32,
    b_ne3: u32,
};

fn src1_index(_i: u32) -> u32 {
    var i = _i;
    let a_i3 = i / (params.a_ne2 * params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne2 * params.a_ne1 * params.a_ne0);
    let a_i2 = i / (params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne1 * params.a_ne0);
    let a_i1 = i / params.a_ne0;
    let a_i0 = i % params.a_ne0;

    // handle repetition of b
    // index loops back to the beginning and repeats after elements are exhausted = modulo
    let b_i0 = a_i0 % params.b_ne0;
    let b_i1 = a_i1 % params.b_ne1;
    let b_i2 = a_i2 % params.b_ne2;
    let b_i3 = a_i3 % params.b_ne3;

    // compute index for position in b's flat array
    return b_i0 * params.stride_src1_0 +
           b_i1 * params.stride_src1_1 +
           b_i2 * params.stride_src1_2 +
           b_i3 * params.stride_src1_3;
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f16>;

fn update(dst_i: u32, src0_i: u32, src1_i: u32) {
    dst[dst_i] = src0[src0_i] / src1[src1_i];
}

@group(0) @binding(2)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(3)
var<uniform> params: Params;



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x < params.ne) {
        update(params.offset_dst + gid.x, params.offset_src0 + gid.x, params.offset_src1 + src1_index(gid.x));
    }
})";

const char* wgsl_div_f32_inplace = R"(enable f16;
struct Params {
    ne: u32,

    // offsets in elements
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    stride_src1_0: u32,
    stride_src1_1: u32,
    stride_src1_2: u32,
    stride_src1_3: u32,

    a_ne0: u32,
    a_ne1: u32,
    a_ne2: u32,

    b_ne0: u32,
    b_ne1: u32,
    b_ne2: u32,
    b_ne3: u32,
};

fn src1_index(_i: u32) -> u32 {
    var i = _i;
    let a_i3 = i / (params.a_ne2 * params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne2 * params.a_ne1 * params.a_ne0);
    let a_i2 = i / (params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne1 * params.a_ne0);
    let a_i1 = i / params.a_ne0;
    let a_i0 = i % params.a_ne0;

    // handle repetition of b
    // index loops back to the beginning and repeats after elements are exhausted = modulo
    let b_i0 = a_i0 % params.b_ne0;
    let b_i1 = a_i1 % params.b_ne1;
    let b_i2 = a_i2 % params.b_ne2;
    let b_i3 = a_i3 % params.b_ne3;

    // compute index for position in b's flat array
    return b_i0 * params.stride_src1_0 +
           b_i1 * params.stride_src1_1 +
           b_i2 * params.stride_src1_2 +
           b_i3 * params.stride_src1_3;
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f32>;

fn update(dst_i: u32, src0_i: u32, src1_i: u32) {
    src0[dst_i] = src0[src0_i] / src1[src1_i];
}

@group(0) @binding(2)
var<uniform> params: Params;



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x < params.ne) {
        update(params.offset_dst + gid.x, params.offset_src0 + gid.x, params.offset_src1 + src1_index(gid.x));
    }
})";

const char* wgsl_div_f16_inplace = R"(enable f16;
struct Params {
    ne: u32,

    // offsets in elements
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    stride_src1_0: u32,
    stride_src1_1: u32,
    stride_src1_2: u32,
    stride_src1_3: u32,

    a_ne0: u32,
    a_ne1: u32,
    a_ne2: u32,

    b_ne0: u32,
    b_ne1: u32,
    b_ne2: u32,
    b_ne3: u32,
};

fn src1_index(_i: u32) -> u32 {
    var i = _i;
    let a_i3 = i / (params.a_ne2 * params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne2 * params.a_ne1 * params.a_ne0);
    let a_i2 = i / (params.a_ne1 * params.a_ne0);
    i = i % (params.a_ne1 * params.a_ne0);
    let a_i1 = i / params.a_ne0;
    let a_i0 = i % params.a_ne0;

    // handle repetition of b
    // index loops back to the beginning and repeats after elements are exhausted = modulo
    let b_i0 = a_i0 % params.b_ne0;
    let b_i1 = a_i1 % params.b_ne1;
    let b_i2 = a_i2 % params.b_ne2;
    let b_i3 = a_i3 % params.b_ne3;

    // compute index for position in b's flat array
    return b_i0 * params.stride_src1_0 +
           b_i1 * params.stride_src1_1 +
           b_i2 * params.stride_src1_2 +
           b_i3 * params.stride_src1_3;
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f16>;

fn update(dst_i: u32, src0_i: u32, src1_i: u32) {
    src0[dst_i] = src0[src0_i] / src1[src1_i];
}

@group(0) @binding(2)
var<uniform> params: Params;



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x < params.ne) {
        update(params.offset_dst + gid.x, params.offset_src0 + gid.x, params.offset_src1 + src1_index(gid.x));
    }
})";

const char* wgsl_cpy_f32_f32 = R"(enable f16;

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32
};

@group(0) @binding(2)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;

    dst[params.offset_dst + dst_idx] = f32((src[params.offset_src + src_idx]));
})";

const char* wgsl_cpy_f32_f16 = R"(enable f16;

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32
};

@group(0) @binding(2)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;

    dst[params.offset_dst + dst_idx] = f16((src[params.offset_src + src_idx]));
})";

const char* wgsl_cpy_f16_f16 = R"(enable f16;

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32
};

@group(0) @binding(2)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;

    dst[params.offset_dst + dst_idx] = f16((src[params.offset_src + src_idx]));
})";

const char* wgsl_cpy_f16_f32 = R"(enable f16;

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32
};

@group(0) @binding(2)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;

    dst[params.offset_dst + dst_idx] = f32((src[params.offset_src + src_idx]));
})";

const char* wgsl_get_rows_f32_vec = R"(enable f16;

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    dst[(dst_base / 4) + offset] = src[(src_base / 4) + offset];
}



@group(0) @binding(0)
var<storage, read_write> src: array<vec4<f32>>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<vec4<f32>>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/4; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_f32 = R"(enable f16;

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    dst[dst_base + offset] = src[src_base + offset];
}



@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/1; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_f16 = R"(enable f16;

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    dst[dst_base + offset] = f32(src[src_base + offset]);
}



@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/1; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_i32 = R"(enable f16;

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    dst[dst_base + offset] = src[src_base + offset];
}



@group(0) @binding(0)
var<storage, read_write> src: array<i32>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<i32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/1; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_q4_0 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q4_0 {
    d: f16,
    qs: array<f16, 8>
};

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block_q4_0 = src[src_base + offset];
    let d = f32(block_q4_0.d);
    for (var j: u32 = 0; j < 4; j++) {
        let q_packed = bitcast<u32>(vec2(block_q4_0.qs[2 * j], block_q4_0.qs[2 * j + 1]));
        for (var k: u32 = 0; k < 4; k++) {
            let q_byte = get_byte(q_packed, k);
            let q_hi = (f32((q_byte >> 4) & 0xF) - 8.0f) * d;
            let q_lo = (f32(q_byte & 0xF) - 8.0f) * d;
            let dst_offset = dst_base + offset * 32 + j * 4 + k;
            dst[dst_offset] = q_lo;
            dst[dst_offset + 16] = q_hi;
        }
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<q4_0>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/32; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_q4_1 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q4_1 {
    d: f16,
    m: f16,
    qs: array<u32, 4>
};

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block_q4_1 = src[src_base + offset];
    let d = f32(block_q4_1.d);
    let m = f32(block_q4_1.m);
    for (var j: u32 = 0; j < 4; j++) {
        let q_packed = block_q4_1.qs[j];
        for (var k: u32 = 0; k < 4; k++) {
            let q_byte = get_byte(q_packed, k);
            let q_hi = f32((q_byte >> 4) & 0xF) * d + m;
            let q_lo = f32(q_byte & 0xF) * d + m;
            let dst_offset = dst_base + offset * 32 + j * 4 + k;
            dst[dst_offset] = q_lo;
            dst[dst_offset + 16] = q_hi;
        }
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<q4_1>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/32; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_q5_0 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q5_0 {
    d: f16,
    qh: array<f16, 2>,
    qs: array<f16, 8>
};

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block_q5_0 = src[src_base + offset];
    let d = f32(block_q5_0.d);
    let qh_packed = bitcast<u32>(vec2(block_q5_0.qh[0], block_q5_0.qh[1]));
    for (var j: u32 = 0; j < 4; j++) {
        let q_packed = bitcast<u32>(vec2(block_q5_0.qs[2 * j], block_q5_0.qs[2 * j + 1]));
        for (var k: u32 = 0; k < 4; k++) {
            let q_byte = get_byte(q_packed, k);
            let qh_hi = (qh_packed >> (j * 4 + k + 12)) & 0x10;
            let q_hi = (f32(((q_byte >> 4) & 0xF) | qh_hi) - 16.0) * d;
            let qh_lo = ((qh_packed >> (j * 4 + k)) << 4) & 0x10;
            let q_lo = (f32((q_byte & 0xF) | qh_lo) - 16.0) * d;
            let dst_offset = dst_base + offset * 32 + j * 4 + k;
            dst[dst_offset] = q_lo;
            dst[dst_offset + 16] = q_hi;
        }
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<q5_0>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/32; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_q5_1 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q5_1 {
    d: f16,
    m: f16,
    qh: u32,
    qs: array<u32, 4>
};

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block_q5_1 = src[src_base + offset];
    let d = f32(block_q5_1.d);
    let m = f32(block_q5_1.m);
    for (var j: u32 = 0; j < 4; j++) {
        let q_packed = block_q5_1.qs[j];
        for (var k: u32 = 0; k < 4; k++) {
            let q_byte = get_byte(q_packed, k);
            let qh_hi = (block_q5_1.qh >> (j * 4 + k + 12)) & 0x10;
            let q_hi = f32(((q_byte >> 4) & 0xF) | qh_hi) * d + m;
            let qh_lo = ((block_q5_1.qh >> (j * 4 + k)) << 4) & 0x10;
            let q_lo = f32((q_byte & 0xF) | qh_lo) * d + m;
            let dst_offset = dst_base + offset * 32 + j * 4 + k;
            dst[dst_offset] = q_lo;
            dst[dst_offset + 16] = q_hi;
        }
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<q5_1>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/32; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_q8_0 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q8_0 {
    d: f16,
    qs: array<f16, 16>
};

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block_q8_0 = src[src_base + offset];
    let d = f32(block_q8_0.d);
    for (var j: u32 = 0; j < 8; j++) {
        let q_packed = bitcast<u32>(vec2(block_q8_0.qs[2 * j], block_q8_0.qs[2 * j + 1]));
        for (var k: u32 = 0; k < 4; k++) {
            let q_byte = get_byte_i32(q_packed, k);
            let q_val = f32(q_byte) * d;
            let dst_offset = dst_base + offset * 32 + j * 4 + k;
            dst[dst_offset] = q_val;
        }
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<q8_0>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/32; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_q2_k = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q2_k {
    scales: array<u32, 4>,
    qs: array<u32, 16>,
    d: f16,
    dmin: f16
};

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block = src[src_base + offset];
    let d = f32(block.d);
    let m = f32(block.dmin);
    var dst_i = dst_base + offset * 256;
    var is: u32 = 0;
    // 2 halves of the block (128 elements each)
    for (var q_b_idx: u32 = 0; q_b_idx < 64; q_b_idx += 32) {
        // 4 groups (each group has 2 blocks of 16 elements)
        for (var shift: u32 = 0; shift < 8; shift += 2) {
            // 2 blocks
            for (var k: u32 = 0; k < 32; k += 16) {
                let sc = get_byte(block.scales[is / 4], is % 4);
                is++;
                let dl = d * f32(sc & 0xF);
                let ml = m * f32(sc >> 4);
                for (var l: u32 = 0u; l < 16; l++) {
                    let q_idx = q_b_idx + k + l;
                    let q_byte = get_byte(block.qs[q_idx / 4], q_idx % 4);
                    let qs_val = (q_byte >> shift) & 3;
                    dst[dst_i] = (f32(qs_val) * dl - ml);
                    dst_i++;
                }
            }
        }
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<q2_k>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/256; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_q3_k = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q3_k {
    hmask: array<f16, 16>,
    qs: array<f16, 32>,
    scales: array<f16, 6>,
    d: f16
};

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block = src[src_base + offset];
    let d = f32(block.d);

    // extract 6-bit scales, which consist of 4-bits from first 8 bytes of scale,
    // and 2-bits from the last 4 bytes
    let kmask1: u32 = 0x03030303;
    let kmask2: u32 = 0x0f0f0f0f;
    var scale_vals: array<u32, 4>;
    for (var i: u32 = 0; i < 4; i++) {
        scale_vals[i] = bitcast<u32>(vec2(block.scales[2 * i], block.scales[2 * i + 1]));
    }
    var tmp: u32 = scale_vals[2];
    scale_vals[2] = ((scale_vals[0] >> 4) & kmask2) | (((tmp >> 4) & kmask1) << 4);
    scale_vals[3] = ((scale_vals[1] >> 4) & kmask2) | (((tmp >> 6) & kmask1) << 4);
    scale_vals[0] = (scale_vals[0] & kmask2) | ((tmp & kmask1) << 4);
    scale_vals[1] = (scale_vals[1] & kmask2) | (((tmp >> 2) & kmask1) << 4);

    // convert arrays of f16 -> u32
    var hmask_vals: array<u32, 8>;
    for (var i: u32 = 0; i < 8; i++) {
        hmask_vals[i] = bitcast<u32>(vec2(block.hmask[2 * i], block.hmask[2 * i + 1]));
    }
    var qs_vals: array<u32, 16>;
    for (var i: u32 = 0; i < 16; i++) {
        qs_vals[i] = bitcast<u32>(vec2(block.qs[2 * i], block.qs[2 * i + 1]));
    }

    var dst_i = dst_base + offset * 256;
    var is: u32 = 0;
    var m: u32 = 1;
    // 2 halves of the block (128 elements each)
    for (var q_b_idx: u32 = 0; q_b_idx < 64; q_b_idx += 32) {
        // 4 groups (each group has 2 blocks of 16 elements)
        for (var shift: u32 = 0; shift < 8; shift += 2) {
            // 2 blocks
            for (var k: u32 = 0; k < 32; k += 16) {
                let sc = get_byte(scale_vals[is / 4], is % 4);
                is++;
                let dl = d * (f32(sc) - 32.0);
                for (var l: u32 = 0u; l < 16u; l++) {
                    let q_idx = q_b_idx + k + l;
                    let hm_idx = k + l;
                    let q_byte = get_byte(qs_vals[q_idx / 4], q_idx % 4);
                    let hmask_byte = get_byte(hmask_vals[hm_idx / 4], hm_idx % 4);
                    let hm = select(4.0, 0.0, (hmask_byte & m) != 0);
                    let qs_val = (q_byte >> shift) & 3;
                    dst[dst_i] = (f32(qs_val) - hm) * dl;
                    dst_i++;
                }
            }
            m <<= 1;
        }
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<q3_k>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/256; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_q4_k = R"(enable f16;

fn get_scale_min(is: u32, scales: array<u32, 3>) -> vec2<f32> {
    if (is < 4) {
        let sc_byte = get_byte(scales[is / 4], is % 4);
        let min_byte = get_byte(scales[(is + 4) / 4], is % 4);
        return vec2(f32(sc_byte & 63), f32(min_byte & 63));
    } else {
        let sc_min_lo = get_byte(scales[(is + 4) / 4], (is + 4) % 4);
        let sc_hi = get_byte(scales[(is - 4) / 4], (is - 4) % 4);
        let min_hi = get_byte(scales[is / 4], is % 4);
        let sc = (sc_min_lo & 0xF) | ((sc_hi >> 6) << 4);
        let m = (sc_min_lo >> 4) | ((min_hi >> 6) << 4);
        return vec2(f32(sc), f32(m));
    }
}

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q4_k {
    d: f16,
    dmin: f16,
    scales: array<u32, 3>,
    qs: array<u32, 32>
};

// 8 blocks of 32 elements each
fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block = src[src_base + offset];
    let d = f32(block.d);
    let m = f32(block.dmin);
    var dst_i = dst_base + offset * 256;
    var is: u32 = 0;
    // 2 blocks each iteration
    for (var q_b_idx: u32 = 0; q_b_idx < 128; q_b_idx += 32) {
        for (var shift: u32 = 0; shift < 8; shift += 4) {
            let scale_min = get_scale_min(is, block.scales);
            is++;
            let dl = d * scale_min.x;
            let ml = m * scale_min.y;
            for (var l: u32 = 0; l < 32; l++) {
                let q_idx = q_b_idx + l;
                let q_byte = get_byte(block.qs[q_idx / 4], q_idx % 4);
                let qs_val = (q_byte >> shift) & 0xF;
                dst[dst_i] = (f32(qs_val) * dl - ml);
                dst_i++;
            }
        }
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<q4_k>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/256; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_q5_k = R"(enable f16;

fn get_scale_min(is: u32, scales: array<u32, 3>) -> vec2<f32> {
    if (is < 4) {
        let sc_byte = get_byte(scales[is / 4], is % 4);
        let min_byte = get_byte(scales[(is + 4) / 4], is % 4);
        return vec2(f32(sc_byte & 63), f32(min_byte & 63));
    } else {
        let sc_min_lo = get_byte(scales[(is + 4) / 4], (is + 4) % 4);
        let sc_hi = get_byte(scales[(is - 4) / 4], (is - 4) % 4);
        let min_hi = get_byte(scales[is / 4], is % 4);
        let sc = (sc_min_lo & 0xF) | ((sc_hi >> 6) << 4);
        let m = (sc_min_lo >> 4) | ((min_hi >> 6) << 4);
        return vec2(f32(sc), f32(m));
    }
}

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q5_k {
    d: f16,
    dmin: f16,
    scales: array<u32, 3>,
    qh: array<u32, 8>,
    qs: array<u32, 32>
};

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block = src[src_base + offset];
    let d = f32(block.d);
    let m = f32(block.dmin);
    var dst_i = dst_base + offset * 256;
    var is: u32 = 0;
    var u: u32 = 1;
    // 2 blocks each iteration
    for (var q_b_idx: u32 = 0; q_b_idx < 128; q_b_idx += 32) {
        for (var shift: u32 = 0; shift < 8; shift += 4) {
            let scale_min = get_scale_min(is, block.scales);
            is++;
            let dl = d * scale_min.x;
            let ml = m * scale_min.y;
            for (var l: u32 = 0; l < 32; l++) {
                let q_idx = q_b_idx + l;
                let q_byte = get_byte(block.qs[q_idx / 4], q_idx % 4);
                let qh_byte = get_byte(block.qh[l / 4], l % 4);
                let qs_val = (q_byte >> shift) & 0xF;
                let qh_val = select(0.0, 16.0, (qh_byte & u) != 0);
                dst[dst_i] = (f32(qs_val) + qh_val) * dl - ml;
                dst_i++;
            }
            u <<= 1;
        }
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<q5_k>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/256; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_q6_k = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q6_k {
    ql: array<f16, 64>,
    qh: array<f16, 32>,
    scales: array<f16, 8>,
    d: f16
};

// 16 blocks of 16 elements each
fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block = src[src_base + offset];
    let d = f32(block.d);

    // convert arrays of f16 -> u32
    var ql_vals: array<u32, 32>;
    for (var i: u32 = 0; i < 32; i++) {
        ql_vals[i] = bitcast<u32>(vec2(block.ql[2 * i], block.ql[2 * i + 1]));
    }
    var qh_vals: array<u32, 16>;
    for (var i: u32 = 0; i < 16; i++) {
        qh_vals[i] = bitcast<u32>(vec2(block.qh[2 * i], block.qh[2 * i + 1]));
    }
    var scale_vals: array<u32, 4>;
    for (var i: u32 = 0; i < 4; i++) {
        scale_vals[i] = bitcast<u32>(vec2(block.scales[2 * i], block.scales[2 * i + 1]));
    }

    var dst_i = dst_base + offset * 256;
    var qh_b_idx: u32 = 0;
    var sc_b_idx: u32 = 0;
    for (var ql_b_idx: u32 = 0; ql_b_idx < 128; ql_b_idx += 64) {
        for (var l: u32 = 0; l < 32; l++) {
            let ql13_b = get_byte(ql_vals[(ql_b_idx + l) / 4], (ql_b_idx + l) % 4);
            let ql24_b = get_byte(ql_vals[(ql_b_idx + l + 32) / 4], (ql_b_idx + l + 32) % 4);
            let qh_b = get_byte(qh_vals[(qh_b_idx + l) / 4], (qh_b_idx + l) % 4);

            let q1 = f32((ql13_b & 0xF) | ((qh_b & 3) << 4)) - 32.0;
            let q2 = f32((ql24_b & 0xF) | (((qh_b >> 2) & 3) << 4)) - 32.0;
            let q3 = f32((ql13_b >> 4) | (((qh_b >> 4) & 3) << 4)) - 32.0;
            let q4 = f32((ql24_b >> 4) | (((qh_b >> 6) & 3) << 4)) - 32.0;

            let is = l/16;
            let is1 = sc_b_idx + is;
            let sc1 = get_byte_i32(scale_vals[is1 / 4], is1 % 4);
            let is2 = sc_b_idx + is + 2;
            let sc2 = get_byte_i32(scale_vals[is2 / 4], is2 % 4);
            let is3 = sc_b_idx + is + 4;
            let sc3 = get_byte_i32(scale_vals[is3 / 4], is3 % 4);
            let is4 = sc_b_idx + is + 6;
            let sc4 = get_byte_i32(scale_vals[is4 / 4], is4 % 4);

            dst[dst_i + l] = (q1 * f32(sc1)) * d;
            dst[dst_i + l + 32] = (q2 * f32(sc2)) * d;
            dst[dst_i + l + 64] = (q3 * f32(sc3)) * d;
            dst[dst_i + l + 96] = (q4 * f32(sc4)) * d;
        }
        dst_i += 128;
        qh_b_idx += 32;
        sc_b_idx += 8;
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<q6_k>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/256; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_iq2_xxs = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

const kmask_iq2xs : array<u32, 2> = array<u32, 2>(
    0x08040201u, // 1, 2, 4, 8
    0x80402010u  // 16, 32, 64, 128
);

const ksigns_iq2xs: array<u32, 32> = array<u32, 32>(
    0x03828100,0x87060584,0x8b0a0988,0x0f8e8d0c,
    0x93121190,0x17969514,0x1b9a9918,0x9f1e1d9c,
    0xa32221a0,0x27a6a524,0x2baaa928,0xaf2e2dac,
    0x33b2b130,0xb73635b4,0xbb3a39b8,0x3fbebd3c,
    0xc34241c0,0x47c6c544,0x4bcac948,0xcf4e4dcc,
    0x53d2d150,0xd75655d4,0xdb5a59d8,0x5fdedd5c,
    0x63e2e160,0xe76665e4,0xeb6a69e8,0x6feeed6c,
    0xf37271f0,0x77f6f574,0x7bfaf978,0xff7e7dfc
);

const iq2xxs_grid = array<u32, 512>(
    0x08080808, 0x08080808, 0x0808082b, 0x08080808, 0x08081919, 0x08080808, 0x08082b08, 0x08080808,
    0x08082b2b, 0x08080808, 0x08190819, 0x08080808, 0x08191908, 0x08080808, 0x082b0808, 0x08080808,
    0x082b082b, 0x08080808, 0x082b2b08, 0x08080808, 0x082b2b2b, 0x08080808, 0x19080819, 0x08080808,
    0x19081908, 0x08080808, 0x19190808, 0x08080808, 0x19192b08, 0x08080808, 0x192b0819, 0x08080808,
    0x192b1908, 0x08080808, 0x2b080808, 0x08080808, 0x2b08082b, 0x08080808, 0x2b082b2b, 0x08080808,
    0x2b2b082b, 0x08080808, 0x08080819, 0x08080819, 0x08081908, 0x08080819, 0x08190808, 0x08080819,
    0x08191919, 0x08080819, 0x19080808, 0x08080819, 0x2b081908, 0x08080819, 0x2b192b08, 0x08080819,
    0x08080808, 0x0808082b, 0x0808082b, 0x0808082b, 0x082b082b, 0x0808082b, 0x2b08082b, 0x0808082b,
    0x08080819, 0x08081908, 0x08081908, 0x08081908, 0x08190808, 0x08081908, 0x082b0819, 0x08081908,
    0x082b1908, 0x08081908, 0x19080808, 0x08081908, 0x1908082b, 0x08081908, 0x19082b08, 0x08081908,
    0x192b0808, 0x08081908, 0x2b080819, 0x08081908, 0x2b081908, 0x08081908, 0x2b190808, 0x08081908,
    0x2b2b1908, 0x08081908, 0x08080808, 0x08081919, 0x0808082b, 0x08081919, 0x08082b08, 0x08081919,
    0x082b0808, 0x08081919, 0x1908192b, 0x08081919, 0x192b2b19, 0x08081919, 0x2b080808, 0x08081919,
    0x2b190819, 0x08081919, 0x08082b19, 0x0808192b, 0x08190808, 0x0808192b, 0x19080808, 0x0808192b,
    0x2b081908, 0x0808192b, 0x2b2b1908, 0x0808192b, 0x08080808, 0x08082b08, 0x08081919, 0x08082b08,
    0x08082b08, 0x08082b08, 0x08191908, 0x08082b08, 0x082b2b08, 0x08082b08, 0x19080819, 0x08082b08,
    0x19081908, 0x08082b08, 0x19190808, 0x08082b08, 0x1919082b, 0x08082b08, 0x2b082b08, 0x08082b08,
    0x08081908, 0x08082b19, 0x19080808, 0x08082b19, 0x0808082b, 0x08082b2b, 0x08191908, 0x08082b2b,
    0x08080819, 0x08190808, 0x08081908, 0x08190808, 0x08190808, 0x08190808, 0x082b0819, 0x08190808,
    0x19080808, 0x08190808, 0x192b0808, 0x08190808, 0x2b081908, 0x08190808, 0x2b190808, 0x08190808,
    0x2b191919, 0x08190808, 0x08080808, 0x08190819, 0x08082b08, 0x08190819, 0x082b0808, 0x08190819,
    0x19190808, 0x08190819, 0x19192b2b, 0x08190819, 0x2b080808, 0x08190819, 0x082b1908, 0x0819082b,
    0x19081919, 0x0819082b, 0x08080808, 0x08191908, 0x08082b08, 0x08191908, 0x082b0808, 0x08191908,
    0x082b1919, 0x08191908, 0x19082b19, 0x08191908, 0x2b080808, 0x08191908, 0x08192b08, 0x08191919,
    0x192b082b, 0x08191919, 0x08080808, 0x0819192b, 0x0819192b, 0x0819192b, 0x08080819, 0x08192b08,
    0x08081908, 0x08192b08, 0x08190808, 0x08192b08, 0x19080808, 0x08192b08, 0x2b080819, 0x08192b08,
    0x08080808, 0x08192b19, 0x08081919, 0x08192b19, 0x2b2b0808, 0x08192b19, 0x19190819, 0x08192b2b,
    0x08080808, 0x082b0808, 0x0808082b, 0x082b0808, 0x08082b2b, 0x082b0808, 0x19081908, 0x082b0808,
    0x192b0819, 0x082b0808, 0x2b080808, 0x082b0808, 0x2b08082b, 0x082b0808, 0x082b2b19, 0x082b0819,
    0x19082b08, 0x082b0819, 0x08080808, 0x082b082b, 0x0808082b, 0x082b082b, 0x08080819, 0x082b1908,
    0x08081908, 0x082b1908, 0x08190808, 0x082b1908, 0x19080808, 0x082b1908, 0x1919192b, 0x082b1908,
    0x08080808, 0x082b1919, 0x19080819, 0x082b1919, 0x192b1908, 0x082b1919, 0x2b190808, 0x082b192b,
    0x08082b08, 0x082b2b08, 0x082b0808, 0x082b2b08, 0x2b191908, 0x082b2b08, 0x19081908, 0x082b2b2b,
    0x08080819, 0x19080808, 0x08081908, 0x19080808, 0x08190808, 0x19080808, 0x08192b08, 0x19080808,
    0x082b0819, 0x19080808, 0x082b1908, 0x19080808, 0x19080808, 0x19080808, 0x19082b08, 0x19080808,
    0x1919192b, 0x19080808, 0x192b0808, 0x19080808, 0x2b080819, 0x19080808, 0x2b081908, 0x19080808,
    0x2b190808, 0x19080808, 0x08080808, 0x19080819, 0x082b0808, 0x19080819, 0x192b0819, 0x19080819,
    0x2b080808, 0x19080819, 0x2b081919, 0x19080819, 0x08080819, 0x1908082b, 0x08190808, 0x1908082b,
    0x19082b08, 0x1908082b, 0x1919192b, 0x1908082b, 0x192b2b08, 0x1908082b, 0x08080808, 0x19081908,
    0x08082b08, 0x19081908, 0x082b0808, 0x19081908, 0x2b080808, 0x19081908, 0x2b192b19, 0x19081908,
    0x0819082b, 0x19081919, 0x082b1908, 0x19081919, 0x08080808, 0x1908192b, 0x08080819, 0x19082b08,
    0x08081908, 0x19082b08, 0x08190808, 0x19082b08, 0x19080808, 0x19082b08, 0x19081919, 0x19082b08,
    0x08080808, 0x19082b19, 0x19192b08, 0x19082b19, 0x192b0819, 0x19082b19, 0x2b08082b, 0x19082b19,
    0x19081919, 0x19082b2b, 0x2b190808, 0x19082b2b, 0x08080808, 0x19190808, 0x08082b08, 0x19190808,
    0x08190819, 0x19190808, 0x08192b19, 0x19190808, 0x082b0808, 0x19190808, 0x2b080808, 0x19190808,
    0x2b082b08, 0x19190808, 0x08081908, 0x19190819, 0x1908082b, 0x19190819, 0x2b2b1908, 0x19190819,
    0x2b190819, 0x1919082b, 0x2b190808, 0x19191908, 0x2b19082b, 0x19191908, 0x08082b2b, 0x19191919,
    0x08080819, 0x1919192b, 0x19191908, 0x1919192b, 0x08080808, 0x19192b08, 0x08190819, 0x19192b08,
    0x08192b19, 0x19192b08, 0x192b1908, 0x19192b08, 0x19080808, 0x19192b19, 0x08082b08, 0x19192b2b,
    0x08081908, 0x192b0808, 0x08190808, 0x192b0808, 0x19080808, 0x192b0808, 0x192b2b08, 0x192b0808,
    0x08080808, 0x192b0819, 0x19191919, 0x192b0819, 0x08192b08, 0x192b082b, 0x192b0808, 0x192b082b,
    0x08080808, 0x192b1908, 0x08081919, 0x192b1908, 0x08190808, 0x192b1919, 0x0819082b, 0x192b1919,
    0x2b081908, 0x192b1919, 0x1908082b, 0x192b2b08, 0x08080808, 0x2b080808, 0x0808082b, 0x2b080808,
    0x08082b2b, 0x2b080808, 0x19080819, 0x2b080808, 0x2b08082b, 0x2b080808, 0x08081908, 0x2b080819,
    0x08192b08, 0x2b080819, 0x19080808, 0x2b080819, 0x08190819, 0x2b08082b, 0x08080819, 0x2b081908,
    0x08081908, 0x2b081908, 0x08190808, 0x2b081908, 0x08191919, 0x2b081908, 0x19080808, 0x2b081908,
    0x192b0808, 0x2b081908, 0x08080808, 0x2b081919, 0x1908192b, 0x2b081919, 0x2b191908, 0x2b081919,
    0x08082b19, 0x2b08192b, 0x19080808, 0x2b08192b, 0x192b0808, 0x2b08192b, 0x0808082b, 0x2b082b08,
    0x08081908, 0x2b082b19, 0x08190819, 0x2b082b2b, 0x08081908, 0x2b190808, 0x08190808, 0x2b190808,
    0x082b1908, 0x2b190808, 0x19080808, 0x2b190808, 0x2b2b0819, 0x2b190808, 0x0819192b, 0x2b190819,
    0x2b080808, 0x2b190819, 0x19081919, 0x2b19082b, 0x08080808, 0x2b191908, 0x082b082b, 0x2b191908,
    0x19081908, 0x2b191908, 0x19190819, 0x2b191919, 0x2b080819, 0x2b192b08, 0x082b0808, 0x2b192b19,
    0x0808082b, 0x2b2b0808, 0x19190808, 0x2b2b0808, 0x2b081919, 0x2b2b0808, 0x08082b19, 0x2b2b0819,
    0x08080808, 0x2b2b082b, 0x08192b08, 0x2b2b1908, 0x19190808, 0x2b2b2b08, 0x08081908, 0x2b2b2b19
);

struct iq2_xxs {
    d: f16,
    qs: array<f16, 32>
};

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block = src[src_base + offset];
    let d = f32(block.d);
    var dst_i = dst_base + offset * 256;
    for (var ib: u32 = 0; ib < 32; ib += 4) {
        let aux0 = bitcast<u32>(vec2(block.qs[ib], block.qs[ib + 1]));
        let aux1 = bitcast<u32>(vec2(block.qs[ib + 2], block.qs[ib + 3]));
        let db = d * (0.5 + f32(aux1 >> 28)) * 0.25;
        for (var l: u32 = 0; l < 4; l++) {
            let ig = get_byte(aux0, l) * 8;
            let is = (aux1 >> (7 * l)) & 127;
            let signs = get_byte(ksigns_iq2xs[is / 4], is % 4);
            for (var j: u32 = 0; j < 8; j++) {
                let g = get_byte(iq2xxs_grid[(ig + j) / 4], (ig + j) % 4);
                let m = select(1.0, -1.0, (get_byte(kmask_iq2xs[j / 4], j % 4) & signs) != 0);
                dst[dst_i] = db * f32(g) * m;
                dst_i++;
            }
        }
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<iq2_xxs>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/256; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_iq2_xs = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

const kmask_iq2xs : array<u32, 2> = array<u32, 2>(
    0x08040201u, // 1, 2, 4, 8
    0x80402010u  // 16, 32, 64, 128
);

const ksigns_iq2xs: array<u32, 32> = array<u32, 32>(
    0x03828100,0x87060584,0x8b0a0988,0x0f8e8d0c,
    0x93121190,0x17969514,0x1b9a9918,0x9f1e1d9c,
    0xa32221a0,0x27a6a524,0x2baaa928,0xaf2e2dac,
    0x33b2b130,0xb73635b4,0xbb3a39b8,0x3fbebd3c,
    0xc34241c0,0x47c6c544,0x4bcac948,0xcf4e4dcc,
    0x53d2d150,0xd75655d4,0xdb5a59d8,0x5fdedd5c,
    0x63e2e160,0xe76665e4,0xeb6a69e8,0x6feeed6c,
    0xf37271f0,0x77f6f574,0x7bfaf978,0xff7e7dfc
);

const iq2xs_grid = array<u32, 1024>(
    0x08080808, 0x08080808, 0x0808082b, 0x08080808, 0x08081919, 0x08080808, 0x08082b08, 0x08080808,
    0x08082b2b, 0x08080808, 0x08190819, 0x08080808, 0x08191908, 0x08080808, 0x0819192b, 0x08080808,
    0x08192b19, 0x08080808, 0x082b0808, 0x08080808, 0x082b082b, 0x08080808, 0x082b1919, 0x08080808,
    0x082b2b08, 0x08080808, 0x19080819, 0x08080808, 0x19081908, 0x08080808, 0x1908192b, 0x08080808,
    0x19082b19, 0x08080808, 0x19190808, 0x08080808, 0x1919082b, 0x08080808, 0x19191919, 0x08080808,
    0x19192b08, 0x08080808, 0x192b0819, 0x08080808, 0x192b1908, 0x08080808, 0x2b080808, 0x08080808,
    0x2b08082b, 0x08080808, 0x2b081919, 0x08080808, 0x2b082b08, 0x08080808, 0x2b190819, 0x08080808,
    0x2b191908, 0x08080808, 0x2b192b19, 0x08080808, 0x2b2b0808, 0x08080808, 0x08080819, 0x08080819,
    0x08081908, 0x08080819, 0x0808192b, 0x08080819, 0x08082b19, 0x08080819, 0x08190808, 0x08080819,
    0x0819082b, 0x08080819, 0x08191919, 0x08080819, 0x08192b08, 0x08080819, 0x08192b2b, 0x08080819,
    0x082b0819, 0x08080819, 0x082b1908, 0x08080819, 0x19080808, 0x08080819, 0x1908082b, 0x08080819,
    0x19081919, 0x08080819, 0x19082b08, 0x08080819, 0x19190819, 0x08080819, 0x19191908, 0x08080819,
    0x192b0808, 0x08080819, 0x192b2b08, 0x08080819, 0x2b080819, 0x08080819, 0x2b081908, 0x08080819,
    0x2b190808, 0x08080819, 0x08080808, 0x0808082b, 0x0808082b, 0x0808082b, 0x08081919, 0x0808082b,
    0x08082b08, 0x0808082b, 0x08190819, 0x0808082b, 0x08191908, 0x0808082b, 0x082b0808, 0x0808082b,
    0x19080819, 0x0808082b, 0x19081908, 0x0808082b, 0x19190808, 0x0808082b, 0x19191919, 0x0808082b,
    0x2b080808, 0x0808082b, 0x2b082b2b, 0x0808082b, 0x08080819, 0x08081908, 0x08081908, 0x08081908,
    0x0808192b, 0x08081908, 0x08082b19, 0x08081908, 0x08190808, 0x08081908, 0x0819082b, 0x08081908,
    0x08191919, 0x08081908, 0x08192b08, 0x08081908, 0x082b0819, 0x08081908, 0x082b1908, 0x08081908,
    0x19080808, 0x08081908, 0x1908082b, 0x08081908, 0x19081919, 0x08081908, 0x19082b08, 0x08081908,
    0x19190819, 0x08081908, 0x19191908, 0x08081908, 0x1919192b, 0x08081908, 0x192b0808, 0x08081908,
    0x2b080819, 0x08081908, 0x2b081908, 0x08081908, 0x2b190808, 0x08081908, 0x08080808, 0x08081919,
    0x0808082b, 0x08081919, 0x08081919, 0x08081919, 0x08082b08, 0x08081919, 0x08190819, 0x08081919,
    0x08191908, 0x08081919, 0x082b0808, 0x08081919, 0x19080819, 0x08081919, 0x19081908, 0x08081919,
    0x19190808, 0x08081919, 0x192b0819, 0x08081919, 0x2b080808, 0x08081919, 0x08080819, 0x0808192b,
    0x08081908, 0x0808192b, 0x08190808, 0x0808192b, 0x082b192b, 0x0808192b, 0x19080808, 0x0808192b,
    0x1908082b, 0x0808192b, 0x2b081908, 0x0808192b, 0x08080808, 0x08082b08, 0x0808082b, 0x08082b08,
    0x08081919, 0x08082b08, 0x08082b08, 0x08082b08, 0x08082b2b, 0x08082b08, 0x08190819, 0x08082b08,
    0x08191908, 0x08082b08, 0x082b0808, 0x08082b08, 0x082b1919, 0x08082b08, 0x19080819, 0x08082b08,
    0x19081908, 0x08082b08, 0x19190808, 0x08082b08, 0x19192b08, 0x08082b08, 0x2b080808, 0x08082b08,
    0x2b2b0808, 0x08082b08, 0x2b2b2b2b, 0x08082b08, 0x08080819, 0x08082b19, 0x08081908, 0x08082b19,
    0x08190808, 0x08082b19, 0x19080808, 0x08082b19, 0x2b080819, 0x08082b19, 0x2b082b19, 0x08082b19,
    0x08080808, 0x08082b2b, 0x082b0808, 0x08082b2b, 0x082b2b08, 0x08082b2b, 0x2b19192b, 0x08082b2b,
    0x2b2b0808, 0x08082b2b, 0x08080819, 0x08190808, 0x08081908, 0x08190808, 0x0808192b, 0x08190808,
    0x08082b19, 0x08190808, 0x08190808, 0x08190808, 0x0819082b, 0x08190808, 0x08191919, 0x08190808,
    0x08192b08, 0x08190808, 0x082b0819, 0x08190808, 0x082b1908, 0x08190808, 0x19080808, 0x08190808,
    0x1908082b, 0x08190808, 0x19081919, 0x08190808, 0x19082b08, 0x08190808, 0x19190819, 0x08190808,
    0x19191908, 0x08190808, 0x192b0808, 0x08190808, 0x192b2b2b, 0x08190808, 0x2b080819, 0x08190808,
    0x2b081908, 0x08190808, 0x2b190808, 0x08190808, 0x08080808, 0x08190819, 0x0808082b, 0x08190819,
    0x08081919, 0x08190819, 0x08082b08, 0x08190819, 0x08190819, 0x08190819, 0x08191908, 0x08190819,
    0x082b0808, 0x08190819, 0x19080819, 0x08190819, 0x19081908, 0x08190819, 0x19190808, 0x08190819,
    0x2b080808, 0x08190819, 0x2b191908, 0x08190819, 0x2b19192b, 0x08190819, 0x08080819, 0x0819082b,
    0x08081908, 0x0819082b, 0x0808192b, 0x0819082b, 0x08190808, 0x0819082b, 0x19080808, 0x0819082b,
    0x192b0808, 0x0819082b, 0x08080808, 0x08191908, 0x0808082b, 0x08191908, 0x08081919, 0x08191908,
    0x08082b08, 0x08191908, 0x08190819, 0x08191908, 0x08191908, 0x08191908, 0x082b0808, 0x08191908,
    0x19080819, 0x08191908, 0x19081908, 0x08191908, 0x19082b19, 0x08191908, 0x19190808, 0x08191908,
    0x192b1908, 0x08191908, 0x2b080808, 0x08191908, 0x08080819, 0x08191919, 0x08081908, 0x08191919,
    0x08190808, 0x08191919, 0x19080808, 0x08191919, 0x08080808, 0x0819192b, 0x08191908, 0x0819192b,
    0x19082b19, 0x0819192b, 0x08080819, 0x08192b08, 0x08081908, 0x08192b08, 0x08190808, 0x08192b08,
    0x0819082b, 0x08192b08, 0x19080808, 0x08192b08, 0x19191908, 0x08192b08, 0x2b08192b, 0x08192b08,
    0x08080808, 0x08192b19, 0x08081919, 0x08192b19, 0x192b192b, 0x08192b19, 0x19190819, 0x08192b2b,
    0x2b2b2b19, 0x08192b2b, 0x08080808, 0x082b0808, 0x0808082b, 0x082b0808, 0x08081919, 0x082b0808,
    0x08082b08, 0x082b0808, 0x08082b2b, 0x082b0808, 0x08190819, 0x082b0808, 0x08191908, 0x082b0808,
    0x082b0808, 0x082b0808, 0x19080819, 0x082b0808, 0x19081908, 0x082b0808, 0x19190808, 0x082b0808,
    0x2b080808, 0x082b0808, 0x2b2b0808, 0x082b0808, 0x08080819, 0x082b0819, 0x08081908, 0x082b0819,
    0x08190808, 0x082b0819, 0x19080808, 0x082b0819, 0x19082b08, 0x082b0819, 0x192b1919, 0x082b0819,
    0x08080808, 0x082b082b, 0x082b082b, 0x082b082b, 0x2b080808, 0x082b082b, 0x2b2b2b08, 0x082b082b,
    0x08080819, 0x082b1908, 0x08081908, 0x082b1908, 0x08190808, 0x082b1908, 0x082b2b19, 0x082b1908,
    0x19080808, 0x082b1908, 0x08080808, 0x082b1919, 0x19080819, 0x082b1919, 0x1919082b, 0x082b1919,
    0x2b192b19, 0x082b1919, 0x08080819, 0x082b192b, 0x08192b2b, 0x082b192b, 0x2b2b192b, 0x082b192b,
    0x08080808, 0x082b2b08, 0x08082b08, 0x082b2b08, 0x08082b2b, 0x082b2b08, 0x082b0808, 0x082b2b08,
    0x19191919, 0x082b2b08, 0x2b082b08, 0x082b2b08, 0x2b2b082b, 0x082b2b08, 0x192b2b08, 0x082b2b19,
    0x2b190808, 0x082b2b19, 0x08082b08, 0x082b2b2b, 0x082b0808, 0x082b2b2b, 0x2b08082b, 0x082b2b2b,
    0x2b082b08, 0x082b2b2b, 0x2b082b2b, 0x082b2b2b, 0x08080819, 0x19080808, 0x08081908, 0x19080808,
    0x0808192b, 0x19080808, 0x08082b19, 0x19080808, 0x08190808, 0x19080808, 0x0819082b, 0x19080808,
    0x08191919, 0x19080808, 0x08192b08, 0x19080808, 0x082b0819, 0x19080808, 0x082b1908, 0x19080808,
    0x19080808, 0x19080808, 0x1908082b, 0x19080808, 0x19081919, 0x19080808, 0x19082b08, 0x19080808,
    0x19082b2b, 0x19080808, 0x19190819, 0x19080808, 0x19191908, 0x19080808, 0x192b0808, 0x19080808,
    0x192b1919, 0x19080808, 0x2b080819, 0x19080808, 0x2b081908, 0x19080808, 0x2b190808, 0x19080808,
    0x08080808, 0x19080819, 0x0808082b, 0x19080819, 0x08081919, 0x19080819, 0x08082b08, 0x19080819,
    0x08190819, 0x19080819, 0x08191908, 0x19080819, 0x082b0808, 0x19080819, 0x19080819, 0x19080819,
    0x19081908, 0x19080819, 0x19190808, 0x19080819, 0x2b080808, 0x19080819, 0x2b081919, 0x19080819,
    0x2b2b082b, 0x19080819, 0x08080819, 0x1908082b, 0x08081908, 0x1908082b, 0x08190808, 0x1908082b,
    0x0819082b, 0x1908082b, 0x082b2b19, 0x1908082b, 0x19080808, 0x1908082b, 0x08080808, 0x19081908,
    0x0808082b, 0x19081908, 0x08081919, 0x19081908, 0x08082b08, 0x19081908, 0x08190819, 0x19081908,
    0x08191908, 0x19081908, 0x08192b19, 0x19081908, 0x082b0808, 0x19081908, 0x19080819, 0x19081908,
    0x19081908, 0x19081908, 0x19190808, 0x19081908, 0x2b080808, 0x19081908, 0x2b191908, 0x19081908,
    0x08080819, 0x19081919, 0x08081908, 0x19081919, 0x08190808, 0x19081919, 0x082b1908, 0x19081919,
    0x19080808, 0x19081919, 0x2b192b2b, 0x19081919, 0x08080808, 0x1908192b, 0x08082b2b, 0x1908192b,
    0x19081908, 0x1908192b, 0x19190808, 0x1908192b, 0x08080819, 0x19082b08, 0x08081908, 0x19082b08,
    0x08190808, 0x19082b08, 0x19080808, 0x19082b08, 0x19081919, 0x19082b08, 0x19191908, 0x19082b08,
    0x192b082b, 0x19082b08, 0x08080808, 0x19082b19, 0x08190819, 0x19082b19, 0x19081908, 0x19082b19,
    0x19190808, 0x19082b19, 0x192b2b19, 0x19082b19, 0x08081908, 0x19082b2b, 0x08080808, 0x19190808,
    0x0808082b, 0x19190808, 0x08081919, 0x19190808, 0x08082b08, 0x19190808, 0x08190819, 0x19190808,
    0x08191908, 0x19190808, 0x082b0808, 0x19190808, 0x082b2b08, 0x19190808, 0x19080819, 0x19190808,
    0x19081908, 0x19190808, 0x19190808, 0x19190808, 0x2b080808, 0x19190808, 0x08080819, 0x19190819,
    0x08081908, 0x19190819, 0x08190808, 0x19190819, 0x08191919, 0x19190819, 0x19080808, 0x19190819,
    0x1908082b, 0x19190819, 0x08080808, 0x1919082b, 0x19081908, 0x1919082b, 0x2b2b2b2b, 0x1919082b,
    0x08080819, 0x19191908, 0x08081908, 0x19191908, 0x08190808, 0x19191908, 0x082b0819, 0x19191908,
    0x19080808, 0x19191908, 0x192b0808, 0x19191908, 0x2b080819, 0x19191908, 0x2b2b0819, 0x19191908,
    0x08080808, 0x19191919, 0x08082b08, 0x19191919, 0x2b080808, 0x19191919, 0x2b082b08, 0x19191919,
    0x082b0819, 0x1919192b, 0x192b2b08, 0x1919192b, 0x2b2b0819, 0x1919192b, 0x08080808, 0x19192b08,
    0x08191908, 0x19192b08, 0x19080819, 0x19192b08, 0x19190808, 0x19192b08, 0x2b192b19, 0x19192b08,
    0x08192b2b, 0x19192b19, 0x19080808, 0x19192b19, 0x1908082b, 0x19192b19, 0x2b081919, 0x19192b2b,
    0x08080819, 0x192b0808, 0x08081908, 0x192b0808, 0x08190808, 0x192b0808, 0x19080808, 0x192b0808,
    0x19191908, 0x192b0808, 0x192b082b, 0x192b0808, 0x2b08192b, 0x192b0808, 0x2b2b2b19, 0x192b0808,
    0x08080808, 0x192b0819, 0x082b1908, 0x192b082b, 0x19082b2b, 0x192b082b, 0x2b19082b, 0x192b082b,
    0x08080808, 0x192b1908, 0x0819192b, 0x192b1908, 0x08190808, 0x192b1919, 0x19080808, 0x192b1919,
    0x19081919, 0x192b1919, 0x2b2b1908, 0x192b1919, 0x08080819, 0x192b2b08, 0x192b2b2b, 0x192b2b08,
    0x082b1919, 0x192b2b19, 0x0808192b, 0x192b2b2b, 0x19191908, 0x192b2b2b, 0x192b082b, 0x192b2b2b,
    0x08080808, 0x2b080808, 0x0808082b, 0x2b080808, 0x08081919, 0x2b080808, 0x08082b08, 0x2b080808,
    0x08190819, 0x2b080808, 0x08191908, 0x2b080808, 0x082b0808, 0x2b080808, 0x082b2b2b, 0x2b080808,
    0x19080819, 0x2b080808, 0x19081908, 0x2b080808, 0x19190808, 0x2b080808, 0x2b080808, 0x2b080808,
    0x2b08082b, 0x2b080808, 0x2b2b2b08, 0x2b080808, 0x2b2b2b2b, 0x2b080808, 0x08080819, 0x2b080819,
    0x08081908, 0x2b080819, 0x0808192b, 0x2b080819, 0x08190808, 0x2b080819, 0x19080808, 0x2b080819,
    0x19190819, 0x2b080819, 0x19192b19, 0x2b080819, 0x08080808, 0x2b08082b, 0x082b0808, 0x2b08082b,
    0x2b080808, 0x2b08082b, 0x2b08082b, 0x2b08082b, 0x2b2b0808, 0x2b08082b, 0x2b2b2b08, 0x2b08082b,
    0x08080819, 0x2b081908, 0x08081908, 0x2b081908, 0x08190808, 0x2b081908, 0x0819082b, 0x2b081908,
    0x08191919, 0x2b081908, 0x19080808, 0x2b081908, 0x192b0808, 0x2b081908, 0x2b082b19, 0x2b081908,
    0x08080808, 0x2b081919, 0x19081908, 0x2b081919, 0x2b2b1919, 0x2b081919, 0x08192b08, 0x2b08192b,
    0x192b2b2b, 0x2b08192b, 0x08080808, 0x2b082b08, 0x08082b08, 0x2b082b08, 0x082b1919, 0x2b082b08,
    0x19192b2b, 0x2b082b08, 0x2b080808, 0x2b082b08, 0x2b08082b, 0x2b082b08, 0x2b2b2b08, 0x2b082b08,
    0x0808192b, 0x2b082b19, 0x082b082b, 0x2b082b2b, 0x2b080808, 0x2b082b2b, 0x2b082b08, 0x2b082b2b,
    0x2b19192b, 0x2b082b2b, 0x2b2b2b08, 0x2b082b2b, 0x08080819, 0x2b190808, 0x08081908, 0x2b190808,
    0x08190808, 0x2b190808, 0x19080808, 0x2b190808, 0x1919192b, 0x2b190808, 0x2b081908, 0x2b190808,
    0x08080808, 0x2b190819, 0x082b082b, 0x2b190819, 0x192b1908, 0x2b190819, 0x1919192b, 0x2b19082b,
    0x2b082b19, 0x2b19082b, 0x08080808, 0x2b191908, 0x08081919, 0x2b191908, 0x19081908, 0x2b191908,
    0x19190808, 0x2b191908, 0x19192b08, 0x2b191908, 0x082b2b19, 0x2b191919, 0x2b190808, 0x2b191919,
    0x2b19082b, 0x2b191919, 0x19080819, 0x2b19192b, 0x19190819, 0x2b192b08, 0x2b2b192b, 0x2b192b08,
    0x19082b19, 0x2b192b19, 0x08191919, 0x2b192b2b, 0x192b0808, 0x2b192b2b, 0x08080808, 0x2b2b0808,
    0x0808082b, 0x2b2b0808, 0x08082b08, 0x2b2b0808, 0x08082b2b, 0x2b2b0808, 0x082b0808, 0x2b2b0808,
    0x082b2b2b, 0x2b2b0808, 0x2b2b0808, 0x2b2b0808, 0x19190819, 0x2b2b0819, 0x19192b19, 0x2b2b0819,
    0x2b2b192b, 0x2b2b0819, 0x08080808, 0x2b2b082b, 0x0808082b, 0x2b2b082b, 0x08082b08, 0x2b2b082b,
    0x082b2b2b, 0x2b2b082b, 0x2b080808, 0x2b2b082b, 0x2b2b0808, 0x2b2b082b, 0x19080808, 0x2b2b1908,
    0x2b191919, 0x2b2b1908, 0x192b1919, 0x2b2b192b, 0x2b192b08, 0x2b2b192b, 0x08082b2b, 0x2b2b2b08,
    0x082b0808, 0x2b2b2b08, 0x082b082b, 0x2b2b2b08, 0x082b2b08, 0x2b2b2b08, 0x2b2b0808, 0x2b2b2b08,
    0x2b2b2b08, 0x2b2b2b08, 0x08081908, 0x2b2b2b19, 0x2b081908, 0x2b2b2b19, 0x2b08192b, 0x2b2b2b19,
    0x082b2b08, 0x2b2b2b2b, 0x082b2b2b, 0x2b2b2b2b, 0x2b190819, 0x2b2b2b2b, 0x2b2b2b2b, 0x2b2b2b2b
);

struct iq2_xs {
    d: f16,
    qs: array<f16, 32>,
    scales: array<f16, 4>
};

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block = src[src_base + offset];
    let d = f32(block.d);
    var dst_i = dst_base + offset * 256;
    var scale_vals = array<u32, 2>(
        bitcast<u32>(vec2(block.scales[0], block.scales[1])),
        bitcast<u32>(vec2(block.scales[2], block.scales[3]))
    );
    for (var ib: u32 = 0; ib < 32; ib += 4) {
        let s = get_byte(scale_vals[ib / 16], (ib % 16) / 4);
        let db = array<f32, 2>(
            d * (0.5 + f32(s & 0xF)) * 0.25,
            d * (0.5 + f32(s >> 4)) * 0.25
        );
        for (var l: u32 = 0; l < 4; l++) {
            let qs_val = bitcast<u32>(vec2(block.qs[ib + l], 0.0));
            let ig = (qs_val & 511) * 8;
            let is = qs_val >> 9;
            let signs = get_byte(ksigns_iq2xs[is / 4], is % 4);
            let dl = db[l/2];
            for (var j: u32 = 0; j < 8; j++) {
                let g = get_byte(iq2xs_grid[(ig + j) / 4], (ig + j) % 4);
                let m = select(1.0, -1.0, (get_byte(kmask_iq2xs[j / 4], j % 4) & signs) != 0);
                dst[dst_i] = dl * f32(g) * m;
                dst_i++;
            }
        }
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<iq2_xs>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/256; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_iq2_s = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

const kmask_iq2xs : array<u32, 2> = array<u32, 2>(
    0x08040201u, // 1, 2, 4, 8
    0x80402010u  // 16, 32, 64, 128
);

const ksigns_iq2xs: array<u32, 32> = array<u32, 32>(
    0x03828100,0x87060584,0x8b0a0988,0x0f8e8d0c,
    0x93121190,0x17969514,0x1b9a9918,0x9f1e1d9c,
    0xa32221a0,0x27a6a524,0x2baaa928,0xaf2e2dac,
    0x33b2b130,0xb73635b4,0xbb3a39b8,0x3fbebd3c,
    0xc34241c0,0x47c6c544,0x4bcac948,0xcf4e4dcc,
    0x53d2d150,0xd75655d4,0xdb5a59d8,0x5fdedd5c,
    0x63e2e160,0xe76665e4,0xeb6a69e8,0x6feeed6c,
    0xf37271f0,0x77f6f574,0x7bfaf978,0xff7e7dfc
);

const iq2s_grid = array<u32, 2048>(
    0x08080808, 0x08080808, 0x0808082b, 0x08080808, 0x08081919, 0x08080808, 0x08082b08, 0x08080808,
    0x08082b2b, 0x08080808, 0x08190819, 0x08080808, 0x08191908, 0x08080808, 0x0819192b, 0x08080808,
    0x08192b19, 0x08080808, 0x082b0808, 0x08080808, 0x082b082b, 0x08080808, 0x082b1919, 0x08080808,
    0x082b2b08, 0x08080808, 0x19080819, 0x08080808, 0x19081908, 0x08080808, 0x1908192b, 0x08080808,
    0x19082b19, 0x08080808, 0x19190808, 0x08080808, 0x1919082b, 0x08080808, 0x19191919, 0x08080808,
    0x19192b08, 0x08080808, 0x192b0819, 0x08080808, 0x192b1908, 0x08080808, 0x192b192b, 0x08080808,
    0x192b2b19, 0x08080808, 0x2b080808, 0x08080808, 0x2b08082b, 0x08080808, 0x2b081919, 0x08080808,
    0x2b082b08, 0x08080808, 0x2b190819, 0x08080808, 0x2b191908, 0x08080808, 0x2b2b0808, 0x08080808,
    0x2b2b1919, 0x08080808, 0x2b2b2b2b, 0x08080808, 0x08080819, 0x08080819, 0x08081908, 0x08080819,
    0x0808192b, 0x08080819, 0x08082b19, 0x08080819, 0x08190808, 0x08080819, 0x0819082b, 0x08080819,
    0x08191919, 0x08080819, 0x08192b08, 0x08080819, 0x082b0819, 0x08080819, 0x082b1908, 0x08080819,
    0x19080808, 0x08080819, 0x1908082b, 0x08080819, 0x19081919, 0x08080819, 0x19082b08, 0x08080819,
    0x19190819, 0x08080819, 0x19191908, 0x08080819, 0x1919192b, 0x08080819, 0x19192b19, 0x08080819,
    0x192b0808, 0x08080819, 0x192b1919, 0x08080819, 0x192b2b08, 0x08080819, 0x2b080819, 0x08080819,
    0x2b081908, 0x08080819, 0x2b190808, 0x08080819, 0x2b19082b, 0x08080819, 0x2b191919, 0x08080819,
    0x2b2b0819, 0x08080819, 0x2b2b1908, 0x08080819, 0x08080808, 0x0808082b, 0x0808082b, 0x0808082b,
    0x08081919, 0x0808082b, 0x08082b08, 0x0808082b, 0x08190819, 0x0808082b, 0x08191908, 0x0808082b,
    0x082b0808, 0x0808082b, 0x082b2b2b, 0x0808082b, 0x19080819, 0x0808082b, 0x19081908, 0x0808082b,
    0x1908192b, 0x0808082b, 0x19082b19, 0x0808082b, 0x19190808, 0x0808082b, 0x19191919, 0x0808082b,
    0x2b080808, 0x0808082b, 0x2b081919, 0x0808082b, 0x2b082b2b, 0x0808082b, 0x2b191908, 0x0808082b,
    0x2b2b082b, 0x0808082b, 0x08080819, 0x08081908, 0x08081908, 0x08081908, 0x0808192b, 0x08081908,
    0x08082b19, 0x08081908, 0x08190808, 0x08081908, 0x0819082b, 0x08081908, 0x08191919, 0x08081908,
    0x08192b08, 0x08081908, 0x082b0819, 0x08081908, 0x082b1908, 0x08081908, 0x082b192b, 0x08081908,
    0x082b2b19, 0x08081908, 0x19080808, 0x08081908, 0x1908082b, 0x08081908, 0x19081919, 0x08081908,
    0x19082b08, 0x08081908, 0x19082b2b, 0x08081908, 0x19190819, 0x08081908, 0x19191908, 0x08081908,
    0x1919192b, 0x08081908, 0x19192b19, 0x08081908, 0x192b0808, 0x08081908, 0x192b082b, 0x08081908,
    0x192b1919, 0x08081908, 0x2b080819, 0x08081908, 0x2b081908, 0x08081908, 0x2b08192b, 0x08081908,
    0x2b082b19, 0x08081908, 0x2b190808, 0x08081908, 0x2b191919, 0x08081908, 0x2b192b08, 0x08081908,
    0x2b2b0819, 0x08081908, 0x2b2b1908, 0x08081908, 0x08080808, 0x08081919, 0x0808082b, 0x08081919,
    0x08081919, 0x08081919, 0x08082b08, 0x08081919, 0x08082b2b, 0x08081919, 0x08190819, 0x08081919,
    0x08191908, 0x08081919, 0x0819192b, 0x08081919, 0x08192b19, 0x08081919, 0x082b0808, 0x08081919,
    0x082b1919, 0x08081919, 0x082b2b08, 0x08081919, 0x19080819, 0x08081919, 0x19081908, 0x08081919,
    0x1908192b, 0x08081919, 0x19082b19, 0x08081919, 0x19190808, 0x08081919, 0x1919082b, 0x08081919,
    0x19191919, 0x08081919, 0x19192b08, 0x08081919, 0x192b0819, 0x08081919, 0x192b1908, 0x08081919,
    0x2b080808, 0x08081919, 0x2b08082b, 0x08081919, 0x2b081919, 0x08081919, 0x2b082b08, 0x08081919,
    0x2b190819, 0x08081919, 0x2b191908, 0x08081919, 0x2b2b0808, 0x08081919, 0x08080819, 0x0808192b,
    0x08081908, 0x0808192b, 0x0808192b, 0x0808192b, 0x08082b19, 0x0808192b, 0x08190808, 0x0808192b,
    0x08191919, 0x0808192b, 0x19080808, 0x0808192b, 0x19081919, 0x0808192b, 0x19082b08, 0x0808192b,
    0x19190819, 0x0808192b, 0x19191908, 0x0808192b, 0x192b0808, 0x0808192b, 0x2b080819, 0x0808192b,
    0x2b081908, 0x0808192b, 0x2b190808, 0x0808192b, 0x08080808, 0x08082b08, 0x0808082b, 0x08082b08,
    0x08081919, 0x08082b08, 0x08082b08, 0x08082b08, 0x08190819, 0x08082b08, 0x08191908, 0x08082b08,
    0x0819192b, 0x08082b08, 0x08192b19, 0x08082b08, 0x082b0808, 0x08082b08, 0x082b1919, 0x08082b08,
    0x082b2b2b, 0x08082b08, 0x19080819, 0x08082b08, 0x19081908, 0x08082b08, 0x1908192b, 0x08082b08,
    0x19082b19, 0x08082b08, 0x19190808, 0x08082b08, 0x1919082b, 0x08082b08, 0x19191919, 0x08082b08,
    0x19192b08, 0x08082b08, 0x192b0819, 0x08082b08, 0x192b1908, 0x08082b08, 0x2b080808, 0x08082b08,
    0x2b081919, 0x08082b08, 0x2b191908, 0x08082b08, 0x2b2b2b2b, 0x08082b08, 0x08080819, 0x08082b19,
    0x08081908, 0x08082b19, 0x08190808, 0x08082b19, 0x0819082b, 0x08082b19, 0x08191919, 0x08082b19,
    0x08192b08, 0x08082b19, 0x082b0819, 0x08082b19, 0x19080808, 0x08082b19, 0x19081919, 0x08082b19,
    0x19082b08, 0x08082b19, 0x19190819, 0x08082b19, 0x19191908, 0x08082b19, 0x192b0808, 0x08082b19,
    0x2b080819, 0x08082b19, 0x2b190808, 0x08082b19, 0x08080808, 0x08082b2b, 0x08190819, 0x08082b2b,
    0x08191908, 0x08082b2b, 0x082b082b, 0x08082b2b, 0x082b2b08, 0x08082b2b, 0x082b2b2b, 0x08082b2b,
    0x19190808, 0x08082b2b, 0x2b192b19, 0x08082b2b, 0x08080819, 0x08190808, 0x08081908, 0x08190808,
    0x0808192b, 0x08190808, 0x08082b19, 0x08190808, 0x08190808, 0x08190808, 0x0819082b, 0x08190808,
    0x08191919, 0x08190808, 0x08192b08, 0x08190808, 0x082b0819, 0x08190808, 0x082b1908, 0x08190808,
    0x082b192b, 0x08190808, 0x19080808, 0x08190808, 0x1908082b, 0x08190808, 0x19081919, 0x08190808,
    0x19082b08, 0x08190808, 0x19190819, 0x08190808, 0x19191908, 0x08190808, 0x1919192b, 0x08190808,
    0x19192b19, 0x08190808, 0x192b0808, 0x08190808, 0x192b082b, 0x08190808, 0x192b1919, 0x08190808,
    0x192b2b08, 0x08190808, 0x2b080819, 0x08190808, 0x2b081908, 0x08190808, 0x2b08192b, 0x08190808,
    0x2b190808, 0x08190808, 0x2b191919, 0x08190808, 0x2b192b08, 0x08190808, 0x2b2b0819, 0x08190808,
    0x2b2b1908, 0x08190808, 0x08080808, 0x08190819, 0x0808082b, 0x08190819, 0x08081919, 0x08190819,
    0x08082b08, 0x08190819, 0x08082b2b, 0x08190819, 0x08190819, 0x08190819, 0x08191908, 0x08190819,
    0x0819192b, 0x08190819, 0x08192b19, 0x08190819, 0x082b0808, 0x08190819, 0x082b082b, 0x08190819,
    0x082b1919, 0x08190819, 0x082b2b08, 0x08190819, 0x19080819, 0x08190819, 0x19081908, 0x08190819,
    0x1908192b, 0x08190819, 0x19082b19, 0x08190819, 0x19190808, 0x08190819, 0x1919082b, 0x08190819,
    0x19191919, 0x08190819, 0x19192b08, 0x08190819, 0x192b0819, 0x08190819, 0x192b1908, 0x08190819,
    0x2b080808, 0x08190819, 0x2b08082b, 0x08190819, 0x2b081919, 0x08190819, 0x2b082b08, 0x08190819,
    0x2b190819, 0x08190819, 0x2b191908, 0x08190819, 0x08080819, 0x0819082b, 0x08081908, 0x0819082b,
    0x08082b19, 0x0819082b, 0x08190808, 0x0819082b, 0x08191919, 0x0819082b, 0x082b0819, 0x0819082b,
    0x082b1908, 0x0819082b, 0x19080808, 0x0819082b, 0x19081919, 0x0819082b, 0x19190819, 0x0819082b,
    0x19191908, 0x0819082b, 0x2b080819, 0x0819082b, 0x2b081908, 0x0819082b, 0x2b190808, 0x0819082b,
    0x08080808, 0x08191908, 0x0808082b, 0x08191908, 0x08081919, 0x08191908, 0x08082b08, 0x08191908,
    0x08190819, 0x08191908, 0x08191908, 0x08191908, 0x0819192b, 0x08191908, 0x08192b19, 0x08191908,
    0x082b0808, 0x08191908, 0x082b1919, 0x08191908, 0x082b2b08, 0x08191908, 0x19080819, 0x08191908,
    0x19081908, 0x08191908, 0x1908192b, 0x08191908, 0x19082b19, 0x08191908, 0x19190808, 0x08191908,
    0x1919082b, 0x08191908, 0x19191919, 0x08191908, 0x19192b08, 0x08191908, 0x192b0819, 0x08191908,
    0x192b1908, 0x08191908, 0x2b080808, 0x08191908, 0x2b08082b, 0x08191908, 0x2b081919, 0x08191908,
    0x2b082b08, 0x08191908, 0x2b190819, 0x08191908, 0x2b191908, 0x08191908, 0x2b2b0808, 0x08191908,
    0x08080819, 0x08191919, 0x08081908, 0x08191919, 0x0808192b, 0x08191919, 0x08082b19, 0x08191919,
    0x08190808, 0x08191919, 0x0819082b, 0x08191919, 0x08191919, 0x08191919, 0x08192b08, 0x08191919,
    0x082b0819, 0x08191919, 0x082b1908, 0x08191919, 0x19080808, 0x08191919, 0x1908082b, 0x08191919,
    0x19081919, 0x08191919, 0x19082b08, 0x08191919, 0x19190819, 0x08191919, 0x19191908, 0x08191919,
    0x192b0808, 0x08191919, 0x2b080819, 0x08191919, 0x2b081908, 0x08191919, 0x2b190808, 0x08191919,
    0x08080808, 0x0819192b, 0x08081919, 0x0819192b, 0x08082b08, 0x0819192b, 0x08190819, 0x0819192b,
    0x08191908, 0x0819192b, 0x082b0808, 0x0819192b, 0x19080819, 0x0819192b, 0x19081908, 0x0819192b,
    0x19190808, 0x0819192b, 0x2b080808, 0x0819192b, 0x2b2b2b2b, 0x0819192b, 0x08080819, 0x08192b08,
    0x08081908, 0x08192b08, 0x0808192b, 0x08192b08, 0x08082b19, 0x08192b08, 0x08190808, 0x08192b08,
    0x08191919, 0x08192b08, 0x08192b08, 0x08192b08, 0x082b0819, 0x08192b08, 0x19080808, 0x08192b08,
    0x1908082b, 0x08192b08, 0x19081919, 0x08192b08, 0x19082b08, 0x08192b08, 0x19190819, 0x08192b08,
    0x19191908, 0x08192b08, 0x192b0808, 0x08192b08, 0x2b080819, 0x08192b08, 0x2b081908, 0x08192b08,
    0x08080808, 0x08192b19, 0x0808082b, 0x08192b19, 0x08081919, 0x08192b19, 0x08082b08, 0x08192b19,
    0x08190819, 0x08192b19, 0x08191908, 0x08192b19, 0x082b0808, 0x08192b19, 0x19080819, 0x08192b19,
    0x19081908, 0x08192b19, 0x19190808, 0x08192b19, 0x192b2b19, 0x08192b19, 0x2b2b082b, 0x08192b19,
    0x08081908, 0x08192b2b, 0x08190808, 0x08192b2b, 0x19080808, 0x08192b2b, 0x1919192b, 0x08192b2b,
    0x08080808, 0x082b0808, 0x0808082b, 0x082b0808, 0x08081919, 0x082b0808, 0x08082b08, 0x082b0808,
    0x08190819, 0x082b0808, 0x08191908, 0x082b0808, 0x0819192b, 0x082b0808, 0x08192b19, 0x082b0808,
    0x082b0808, 0x082b0808, 0x082b1919, 0x082b0808, 0x082b2b2b, 0x082b0808, 0x19080819, 0x082b0808,
    0x19081908, 0x082b0808, 0x19190808, 0x082b0808, 0x1919082b, 0x082b0808, 0x19191919, 0x082b0808,
    0x192b1908, 0x082b0808, 0x2b080808, 0x082b0808, 0x2b082b2b, 0x082b0808, 0x2b191908, 0x082b0808,
    0x2b2b2b2b, 0x082b0808, 0x08080819, 0x082b0819, 0x08081908, 0x082b0819, 0x08190808, 0x082b0819,
    0x0819082b, 0x082b0819, 0x08191919, 0x082b0819, 0x082b0819, 0x082b0819, 0x19080808, 0x082b0819,
    0x1908082b, 0x082b0819, 0x19081919, 0x082b0819, 0x19190819, 0x082b0819, 0x19191908, 0x082b0819,
    0x192b0808, 0x082b0819, 0x2b080819, 0x082b0819, 0x2b081908, 0x082b0819, 0x2b190808, 0x082b0819,
    0x08080808, 0x082b082b, 0x08082b2b, 0x082b082b, 0x082b082b, 0x082b082b, 0x082b2b08, 0x082b082b,
    0x082b2b2b, 0x082b082b, 0x19081908, 0x082b082b, 0x19190808, 0x082b082b, 0x2b082b08, 0x082b082b,
    0x2b082b2b, 0x082b082b, 0x2b2b2b08, 0x082b082b, 0x08080819, 0x082b1908, 0x08081908, 0x082b1908,
    0x0808192b, 0x082b1908, 0x08082b19, 0x082b1908, 0x08190808, 0x082b1908, 0x08191919, 0x082b1908,
    0x08192b08, 0x082b1908, 0x082b0819, 0x082b1908, 0x082b1908, 0x082b1908, 0x19080808, 0x082b1908,
    0x1908082b, 0x082b1908, 0x19081919, 0x082b1908, 0x19082b08, 0x082b1908, 0x19190819, 0x082b1908,
    0x19191908, 0x082b1908, 0x192b0808, 0x082b1908, 0x2b080819, 0x082b1908, 0x2b081908, 0x082b1908,
    0x2b190808, 0x082b1908, 0x08080808, 0x082b1919, 0x08081919, 0x082b1919, 0x08082b08, 0x082b1919,
    0x08190819, 0x082b1919, 0x08191908, 0x082b1919, 0x082b0808, 0x082b1919, 0x19080819, 0x082b1919,
    0x19081908, 0x082b1919, 0x19190808, 0x082b1919, 0x192b192b, 0x082b1919, 0x2b080808, 0x082b1919,
    0x08080819, 0x082b192b, 0x08081908, 0x082b192b, 0x08190808, 0x082b192b, 0x19080808, 0x082b192b,
    0x19192b19, 0x082b192b, 0x08080808, 0x082b2b08, 0x08081919, 0x082b2b08, 0x08190819, 0x082b2b08,
    0x08191908, 0x082b2b08, 0x19080819, 0x082b2b08, 0x19081908, 0x082b2b08, 0x19190808, 0x082b2b08,
    0x2b082b2b, 0x082b2b08, 0x2b2b2b2b, 0x082b2b08, 0x08080819, 0x082b2b19, 0x08081908, 0x082b2b19,
    0x08190808, 0x082b2b19, 0x2b191919, 0x082b2b19, 0x08082b2b, 0x082b2b2b, 0x082b082b, 0x082b2b2b,
    0x192b1908, 0x082b2b2b, 0x2b082b08, 0x082b2b2b, 0x2b082b2b, 0x082b2b2b, 0x08080819, 0x19080808,
    0x08081908, 0x19080808, 0x0808192b, 0x19080808, 0x08082b19, 0x19080808, 0x08190808, 0x19080808,
    0x0819082b, 0x19080808, 0x08191919, 0x19080808, 0x08192b08, 0x19080808, 0x08192b2b, 0x19080808,
    0x082b0819, 0x19080808, 0x082b1908, 0x19080808, 0x082b192b, 0x19080808, 0x19080808, 0x19080808,
    0x1908082b, 0x19080808, 0x19081919, 0x19080808, 0x19082b08, 0x19080808, 0x19082b2b, 0x19080808,
    0x19190819, 0x19080808, 0x19191908, 0x19080808, 0x1919192b, 0x19080808, 0x19192b19, 0x19080808,
    0x192b0808, 0x19080808, 0x192b082b, 0x19080808, 0x192b1919, 0x19080808, 0x2b080819, 0x19080808,
    0x2b081908, 0x19080808, 0x2b190808, 0x19080808, 0x2b191919, 0x19080808, 0x2b192b08, 0x19080808,
    0x2b2b0819, 0x19080808, 0x2b2b1908, 0x19080808, 0x08080808, 0x19080819, 0x0808082b, 0x19080819,
    0x08081919, 0x19080819, 0x08082b08, 0x19080819, 0x08190819, 0x19080819, 0x08191908, 0x19080819,
    0x0819192b, 0x19080819, 0x08192b19, 0x19080819, 0x082b0808, 0x19080819, 0x082b082b, 0x19080819,
    0x082b1919, 0x19080819, 0x19080819, 0x19080819, 0x19081908, 0x19080819, 0x1908192b, 0x19080819,
    0x19082b19, 0x19080819, 0x19190808, 0x19080819, 0x1919082b, 0x19080819, 0x19191919, 0x19080819,
    0x19192b08, 0x19080819, 0x192b0819, 0x19080819, 0x192b1908, 0x19080819, 0x2b080808, 0x19080819,
    0x2b08082b, 0x19080819, 0x2b081919, 0x19080819, 0x2b082b08, 0x19080819, 0x2b190819, 0x19080819,
    0x2b191908, 0x19080819, 0x2b2b0808, 0x19080819, 0x08080819, 0x1908082b, 0x08081908, 0x1908082b,
    0x08190808, 0x1908082b, 0x0819082b, 0x1908082b, 0x08191919, 0x1908082b, 0x08192b08, 0x1908082b,
    0x082b1908, 0x1908082b, 0x19080808, 0x1908082b, 0x19081919, 0x1908082b, 0x19082b08, 0x1908082b,
    0x19190819, 0x1908082b, 0x19191908, 0x1908082b, 0x192b0808, 0x1908082b, 0x2b080819, 0x1908082b,
    0x2b081908, 0x1908082b, 0x08080808, 0x19081908, 0x0808082b, 0x19081908, 0x08081919, 0x19081908,
    0x08082b08, 0x19081908, 0x08082b2b, 0x19081908, 0x08190819, 0x19081908, 0x08191908, 0x19081908,
    0x0819192b, 0x19081908, 0x08192b19, 0x19081908, 0x082b0808, 0x19081908, 0x082b082b, 0x19081908,
    0x082b1919, 0x19081908, 0x082b2b08, 0x19081908, 0x19080819, 0x19081908, 0x19081908, 0x19081908,
    0x1908192b, 0x19081908, 0x19082b19, 0x19081908, 0x19190808, 0x19081908, 0x1919082b, 0x19081908,
    0x19191919, 0x19081908, 0x19192b08, 0x19081908, 0x192b0819, 0x19081908, 0x192b1908, 0x19081908,
    0x2b080808, 0x19081908, 0x2b08082b, 0x19081908, 0x2b081919, 0x19081908, 0x2b082b08, 0x19081908,
    0x2b190819, 0x19081908, 0x2b191908, 0x19081908, 0x2b2b0808, 0x19081908, 0x08080819, 0x19081919,
    0x08081908, 0x19081919, 0x0808192b, 0x19081919, 0x08082b19, 0x19081919, 0x08190808, 0x19081919,
    0x0819082b, 0x19081919, 0x08191919, 0x19081919, 0x08192b08, 0x19081919, 0x082b0819, 0x19081919,
    0x082b1908, 0x19081919, 0x19080808, 0x19081919, 0x1908082b, 0x19081919, 0x19081919, 0x19081919,
    0x19082b08, 0x19081919, 0x19190819, 0x19081919, 0x19191908, 0x19081919, 0x192b0808, 0x19081919,
    0x192b2b2b, 0x19081919, 0x2b080819, 0x19081919, 0x2b081908, 0x19081919, 0x2b190808, 0x19081919,
    0x08080808, 0x1908192b, 0x0808082b, 0x1908192b, 0x08081919, 0x1908192b, 0x08082b08, 0x1908192b,
    0x08190819, 0x1908192b, 0x08191908, 0x1908192b, 0x082b0808, 0x1908192b, 0x19080819, 0x1908192b,
    0x19081908, 0x1908192b, 0x19190808, 0x1908192b, 0x2b080808, 0x1908192b, 0x2b2b1919, 0x1908192b,
    0x08080819, 0x19082b08, 0x08081908, 0x19082b08, 0x08082b19, 0x19082b08, 0x08190808, 0x19082b08,
    0x0819082b, 0x19082b08, 0x08191919, 0x19082b08, 0x08192b08, 0x19082b08, 0x082b0819, 0x19082b08,
    0x082b1908, 0x19082b08, 0x19080808, 0x19082b08, 0x1908082b, 0x19082b08, 0x19081919, 0x19082b08,
    0x19082b08, 0x19082b08, 0x19190819, 0x19082b08, 0x19191908, 0x19082b08, 0x192b0808, 0x19082b08,
    0x2b081908, 0x19082b08, 0x2b190808, 0x19082b08, 0x08080808, 0x19082b19, 0x0808082b, 0x19082b19,
    0x08081919, 0x19082b19, 0x08082b08, 0x19082b19, 0x08190819, 0x19082b19, 0x08191908, 0x19082b19,
    0x082b0808, 0x19082b19, 0x19080819, 0x19082b19, 0x19081908, 0x19082b19, 0x19190808, 0x19082b19,
    0x2b080808, 0x19082b19, 0x2b19192b, 0x19082b19, 0x08080819, 0x19082b2b, 0x08081908, 0x19082b2b,
    0x08190808, 0x19082b2b, 0x19080808, 0x19082b2b, 0x08080808, 0x19190808, 0x0808082b, 0x19190808,
    0x08081919, 0x19190808, 0x08082b08, 0x19190808, 0x08190819, 0x19190808, 0x08191908, 0x19190808,
    0x0819192b, 0x19190808, 0x08192b19, 0x19190808, 0x082b0808, 0x19190808, 0x082b082b, 0x19190808,
    0x082b1919, 0x19190808, 0x082b2b08, 0x19190808, 0x19080819, 0x19190808, 0x19081908, 0x19190808,
    0x1908192b, 0x19190808, 0x19082b19, 0x19190808, 0x19190808, 0x19190808, 0x1919082b, 0x19190808,
    0x19191919, 0x19190808, 0x19192b08, 0x19190808, 0x192b0819, 0x19190808, 0x192b1908, 0x19190808,
    0x2b080808, 0x19190808, 0x2b08082b, 0x19190808, 0x2b081919, 0x19190808, 0x2b082b08, 0x19190808,
    0x2b190819, 0x19190808, 0x2b191908, 0x19190808, 0x08080819, 0x19190819, 0x08081908, 0x19190819,
    0x0808192b, 0x19190819, 0x08082b19, 0x19190819, 0x08190808, 0x19190819, 0x0819082b, 0x19190819,
    0x08191919, 0x19190819, 0x08192b08, 0x19190819, 0x082b0819, 0x19190819, 0x082b1908, 0x19190819,
    0x19080808, 0x19190819, 0x1908082b, 0x19190819, 0x19081919, 0x19190819, 0x19082b08, 0x19190819,
    0x19190819, 0x19190819, 0x19191908, 0x19190819, 0x192b0808, 0x19190819, 0x2b080819, 0x19190819,
    0x2b081908, 0x19190819, 0x2b190808, 0x19190819, 0x08080808, 0x1919082b, 0x08081919, 0x1919082b,
    0x08082b08, 0x1919082b, 0x08190819, 0x1919082b, 0x08191908, 0x1919082b, 0x082b0808, 0x1919082b,
    0x19080819, 0x1919082b, 0x19081908, 0x1919082b, 0x19190808, 0x1919082b, 0x192b2b19, 0x1919082b,
    0x2b080808, 0x1919082b, 0x08080819, 0x19191908, 0x08081908, 0x19191908, 0x0808192b, 0x19191908,
    0x08082b19, 0x19191908, 0x08190808, 0x19191908, 0x0819082b, 0x19191908, 0x08191919, 0x19191908,
    0x08192b08, 0x19191908, 0x082b0819, 0x19191908, 0x082b1908, 0x19191908, 0x19080808, 0x19191908,
    0x1908082b, 0x19191908, 0x19081919, 0x19191908, 0x19082b08, 0x19191908, 0x19190819, 0x19191908,
    0x19191908, 0x19191908, 0x192b0808, 0x19191908, 0x2b080819, 0x19191908, 0x2b081908, 0x19191908,
    0x2b190808, 0x19191908, 0x08080808, 0x19191919, 0x0808082b, 0x19191919, 0x08081919, 0x19191919,
    0x08082b08, 0x19191919, 0x08190819, 0x19191919, 0x08191908, 0x19191919, 0x082b0808, 0x19191919,
    0x19080819, 0x19191919, 0x19081908, 0x19191919, 0x19190808, 0x19191919, 0x2b080808, 0x19191919,
    0x08080819, 0x1919192b, 0x08081908, 0x1919192b, 0x08190808, 0x1919192b, 0x082b192b, 0x1919192b,
    0x19080808, 0x1919192b, 0x08080808, 0x19192b08, 0x0808082b, 0x19192b08, 0x08081919, 0x19192b08,
    0x08082b08, 0x19192b08, 0x08190819, 0x19192b08, 0x08191908, 0x19192b08, 0x082b0808, 0x19192b08,
    0x19080819, 0x19192b08, 0x19081908, 0x19192b08, 0x19190808, 0x19192b08, 0x19192b2b, 0x19192b08,
    0x2b080808, 0x19192b08, 0x08080819, 0x19192b19, 0x08081908, 0x19192b19, 0x08190808, 0x19192b19,
    0x19080808, 0x19192b19, 0x08080808, 0x19192b2b, 0x08192b19, 0x19192b2b, 0x2b081919, 0x19192b2b,
    0x2b2b2b08, 0x19192b2b, 0x08080819, 0x192b0808, 0x08081908, 0x192b0808, 0x0808192b, 0x192b0808,
    0x08190808, 0x192b0808, 0x0819082b, 0x192b0808, 0x08191919, 0x192b0808, 0x08192b08, 0x192b0808,
    0x082b0819, 0x192b0808, 0x082b1908, 0x192b0808, 0x19080808, 0x192b0808, 0x19081919, 0x192b0808,
    0x19082b08, 0x192b0808, 0x19190819, 0x192b0808, 0x19191908, 0x192b0808, 0x192b0808, 0x192b0808,
    0x2b081908, 0x192b0808, 0x2b190808, 0x192b0808, 0x08080808, 0x192b0819, 0x0808082b, 0x192b0819,
    0x08081919, 0x192b0819, 0x08082b08, 0x192b0819, 0x08190819, 0x192b0819, 0x08191908, 0x192b0819,
    0x082b0808, 0x192b0819, 0x19080819, 0x192b0819, 0x19081908, 0x192b0819, 0x19190808, 0x192b0819,
    0x2b080808, 0x192b0819, 0x2b192b19, 0x192b0819, 0x08081908, 0x192b082b, 0x08190808, 0x192b082b,
    0x19080808, 0x192b082b, 0x1919192b, 0x192b082b, 0x2b2b0819, 0x192b082b, 0x08080808, 0x192b1908,
    0x08081919, 0x192b1908, 0x08082b08, 0x192b1908, 0x08190819, 0x192b1908, 0x08191908, 0x192b1908,
    0x082b0808, 0x192b1908, 0x19080819, 0x192b1908, 0x19081908, 0x192b1908, 0x19190808, 0x192b1908,
    0x2b080808, 0x192b1908, 0x08080819, 0x192b1919, 0x08081908, 0x192b1919, 0x08190808, 0x192b1919,
    0x19080808, 0x192b1919, 0x19082b2b, 0x192b1919, 0x192b2b08, 0x192b1919, 0x2b19082b, 0x192b1919,
    0x08080808, 0x192b192b, 0x2b191908, 0x192b192b, 0x08080819, 0x192b2b08, 0x08081908, 0x192b2b08,
    0x08190808, 0x192b2b08, 0x192b1919, 0x192b2b08, 0x2b192b08, 0x192b2b08, 0x08080808, 0x192b2b19,
    0x082b2b2b, 0x192b2b19, 0x1908082b, 0x192b2b2b, 0x2b2b0819, 0x192b2b2b, 0x08080808, 0x2b080808,
    0x0808082b, 0x2b080808, 0x08081919, 0x2b080808, 0x08082b08, 0x2b080808, 0x08190819, 0x2b080808,
    0x08191908, 0x2b080808, 0x08192b19, 0x2b080808, 0x082b0808, 0x2b080808, 0x082b1919, 0x2b080808,
    0x19080819, 0x2b080808, 0x19081908, 0x2b080808, 0x19190808, 0x2b080808, 0x1919082b, 0x2b080808,
    0x19191919, 0x2b080808, 0x19192b08, 0x2b080808, 0x192b0819, 0x2b080808, 0x2b080808, 0x2b080808,
    0x2b081919, 0x2b080808, 0x2b190819, 0x2b080808, 0x2b191908, 0x2b080808, 0x08080819, 0x2b080819,
    0x08081908, 0x2b080819, 0x08082b19, 0x2b080819, 0x08190808, 0x2b080819, 0x0819082b, 0x2b080819,
    0x08191919, 0x2b080819, 0x08192b08, 0x2b080819, 0x082b0819, 0x2b080819, 0x082b1908, 0x2b080819,
    0x19080808, 0x2b080819, 0x1908082b, 0x2b080819, 0x19081919, 0x2b080819, 0x19082b08, 0x2b080819,
    0x19190819, 0x2b080819, 0x19191908, 0x2b080819, 0x2b080819, 0x2b080819, 0x2b081908, 0x2b080819,
    0x2b190808, 0x2b080819, 0x2b2b2b19, 0x2b080819, 0x08080808, 0x2b08082b, 0x08081919, 0x2b08082b,
    0x08082b2b, 0x2b08082b, 0x08190819, 0x2b08082b, 0x08191908, 0x2b08082b, 0x19080819, 0x2b08082b,
    0x19081908, 0x2b08082b, 0x19190808, 0x2b08082b, 0x08080819, 0x2b081908, 0x08081908, 0x2b081908,
    0x0808192b, 0x2b081908, 0x08082b19, 0x2b081908, 0x08190808, 0x2b081908, 0x0819082b, 0x2b081908,
    0x08191919, 0x2b081908, 0x08192b08, 0x2b081908, 0x082b0819, 0x2b081908, 0x19080808, 0x2b081908,
    0x1908082b, 0x2b081908, 0x19081919, 0x2b081908, 0x19082b08, 0x2b081908, 0x19190819, 0x2b081908,
    0x19191908, 0x2b081908, 0x192b0808, 0x2b081908, 0x2b080819, 0x2b081908, 0x2b081908, 0x2b081908,
    0x2b190808, 0x2b081908, 0x08080808, 0x2b081919, 0x0808082b, 0x2b081919, 0x08081919, 0x2b081919,
    0x08082b08, 0x2b081919, 0x08190819, 0x2b081919, 0x08191908, 0x2b081919, 0x082b0808, 0x2b081919,
    0x19080819, 0x2b081919, 0x19081908, 0x2b081919, 0x19190808, 0x2b081919, 0x2b080808, 0x2b081919,
    0x2b082b2b, 0x2b081919, 0x08080819, 0x2b08192b, 0x08081908, 0x2b08192b, 0x08190808, 0x2b08192b,
    0x082b2b19, 0x2b08192b, 0x19080808, 0x2b08192b, 0x08080808, 0x2b082b08, 0x08081919, 0x2b082b08,
    0x08190819, 0x2b082b08, 0x08191908, 0x2b082b08, 0x19080819, 0x2b082b08, 0x19081908, 0x2b082b08,
    0x19190808, 0x2b082b08, 0x2b2b082b, 0x2b082b08, 0x08080819, 0x2b082b19, 0x08081908, 0x2b082b19,
    0x19080808, 0x2b082b19, 0x192b1919, 0x2b082b19, 0x082b082b, 0x2b082b2b, 0x19192b08, 0x2b082b2b,
    0x19192b2b, 0x2b082b2b, 0x2b08082b, 0x2b082b2b, 0x2b2b082b, 0x2b082b2b, 0x08080819, 0x2b190808,
    0x08081908, 0x2b190808, 0x08082b19, 0x2b190808, 0x08190808, 0x2b190808, 0x0819082b, 0x2b190808,
    0x08191919, 0x2b190808, 0x08192b08, 0x2b190808, 0x082b1908, 0x2b190808, 0x19080808, 0x2b190808,
    0x1908082b, 0x2b190808, 0x19081919, 0x2b190808, 0x19082b08, 0x2b190808, 0x19190819, 0x2b190808,
    0x19191908, 0x2b190808, 0x192b0808, 0x2b190808, 0x2b080819, 0x2b190808, 0x2b081908, 0x2b190808,
    0x2b190808, 0x2b190808, 0x08080808, 0x2b190819, 0x08081919, 0x2b190819, 0x08190819, 0x2b190819,
    0x08191908, 0x2b190819, 0x19080819, 0x2b190819, 0x19081908, 0x2b190819, 0x19190808, 0x2b190819,
    0x19192b2b, 0x2b190819, 0x08080819, 0x2b19082b, 0x08081908, 0x2b19082b, 0x08190808, 0x2b19082b,
    0x19080808, 0x2b19082b, 0x2b2b192b, 0x2b19082b, 0x08080808, 0x2b191908, 0x0808082b, 0x2b191908,
    0x08081919, 0x2b191908, 0x08082b08, 0x2b191908, 0x08190819, 0x2b191908, 0x08191908, 0x2b191908,
    0x082b0808, 0x2b191908, 0x19080819, 0x2b191908, 0x19081908, 0x2b191908, 0x19190808, 0x2b191908,
    0x2b080808, 0x2b191908, 0x2b19192b, 0x2b191908, 0x08080819, 0x2b191919, 0x08081908, 0x2b191919,
    0x08190808, 0x2b191919, 0x19080808, 0x2b191919, 0x2b192b08, 0x2b191919, 0x2b2b0819, 0x2b191919,
    0x08080808, 0x2b19192b, 0x1908192b, 0x2b19192b, 0x192b1908, 0x2b19192b, 0x08080819, 0x2b192b08,
    0x08081908, 0x2b192b08, 0x08190808, 0x2b192b08, 0x082b192b, 0x2b192b08, 0x19080808, 0x2b192b08,
    0x2b2b2b19, 0x2b192b08, 0x08080808, 0x2b192b19, 0x19082b19, 0x2b192b19, 0x1919082b, 0x2b192b19,
    0x2b190808, 0x2b192b2b, 0x08080808, 0x2b2b0808, 0x08081919, 0x2b2b0808, 0x08082b2b, 0x2b2b0808,
    0x08191908, 0x2b2b0808, 0x082b082b, 0x2b2b0808, 0x082b2b2b, 0x2b2b0808, 0x19080819, 0x2b2b0808,
    0x19081908, 0x2b2b0808, 0x19190808, 0x2b2b0808, 0x2b2b082b, 0x2b2b0808, 0x2b2b2b2b, 0x2b2b0808,
    0x19080808, 0x2b2b0819, 0x192b1919, 0x2b2b0819, 0x0808082b, 0x2b2b082b, 0x08082b2b, 0x2b2b082b,
    0x082b082b, 0x2b2b082b, 0x082b2b08, 0x2b2b082b, 0x082b2b2b, 0x2b2b082b, 0x2b08082b, 0x2b2b082b,
    0x2b082b08, 0x2b2b082b, 0x2b082b2b, 0x2b2b082b, 0x2b2b2b08, 0x2b2b082b, 0x08080819, 0x2b2b1908,
    0x08081908, 0x2b2b1908, 0x08190808, 0x2b2b1908, 0x19080808, 0x2b2b1908, 0x2b082b19, 0x2b2b1908,
    0x2b2b1908, 0x2b2b1908, 0x08080808, 0x2b2b1919, 0x08192b19, 0x2b2b1919, 0x19190819, 0x2b2b192b,
    0x08082b2b, 0x2b2b2b08, 0x082b2b08, 0x2b2b2b08, 0x2b2b082b, 0x2b2b2b08, 0x19191908, 0x2b2b2b19,
    0x2b08192b, 0x2b2b2b19, 0x08082b08, 0x2b2b2b2b, 0x08082b2b, 0x2b2b2b2b, 0x082b0808, 0x2b2b2b2b,
    0x082b082b, 0x2b2b2b2b, 0x082b2b08, 0x2b2b2b2b, 0x2b082b08, 0x2b2b2b2b, 0x2b2b2b2b, 0x2b2b2b2b
);

struct iq2_s {
    d: f16,
    qs: array<f16, 32>,
    qh: array<f16, 4>,
    scales: array<f16, 4>
};

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block = src[src_base + offset];
    let d = f32(block.d);
    var dst_i = dst_base + offset * 256;
    var qs_vals : array<u32, 16>;
    for (var i: u32 = 0; i < 16; i++) {
        qs_vals[i] = bitcast<u32>(vec2(block.qs[i * 2], block.qs[i * 2 + 1]));
    }
    var qh_vals = array<u32, 2>(
        bitcast<u32>(vec2(block.qh[0], block.qh[1])),
        bitcast<u32>(vec2(block.qh[2], block.qh[3]))
    );
    var scale_vals = array<u32, 2>(
        bitcast<u32>(vec2(block.scales[0], block.scales[1])),
        bitcast<u32>(vec2(block.scales[2], block.scales[3]))
    );
    for (var ib: u32 = 0; ib < 8; ib ++) {
        let s = get_byte(scale_vals[ib / 4], ib % 4);
        let db = array<f32, 2>(
            d * (0.5 + f32(s & 0xF)) * 0.25,
            d * (0.5 + f32(s >> 4)) * 0.25
        );
        let qs_w = qs_vals[ib];
        for (var l: u32 = 0; l < 4; l++) {
            let qh_b = (get_byte(qh_vals[ib / 4], ib % 4) << (8 - 2 * l)) & 0x300;
            let ig = (get_byte(qs_w, l) | qh_b) * 8;
            let signs = get_byte(qs_vals[ib + 8], l);
            let dl = db[l/2];
            for (var j: u32 = 0; j < 8; j++) {
                let g = get_byte(iq2s_grid[(ig + j) / 4], (ig + j) % 4);
                let m = select(1.0, -1.0, (get_byte(kmask_iq2xs[j / 4], j % 4) & signs) != 0);
                dst[dst_i] = dl * f32(g) * m;
                dst_i++;
            }
        }
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<iq2_s>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/256; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_iq3_xxs = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

const kmask_iq2xs : array<u32, 2> = array<u32, 2>(
    0x08040201u, // 1, 2, 4, 8
    0x80402010u  // 16, 32, 64, 128
);

const ksigns_iq2xs: array<u32, 32> = array<u32, 32>(
    0x03828100,0x87060584,0x8b0a0988,0x0f8e8d0c,
    0x93121190,0x17969514,0x1b9a9918,0x9f1e1d9c,
    0xa32221a0,0x27a6a524,0x2baaa928,0xaf2e2dac,
    0x33b2b130,0xb73635b4,0xbb3a39b8,0x3fbebd3c,
    0xc34241c0,0x47c6c544,0x4bcac948,0xcf4e4dcc,
    0x53d2d150,0xd75655d4,0xdb5a59d8,0x5fdedd5c,
    0x63e2e160,0xe76665e4,0xeb6a69e8,0x6feeed6c,
    0xf37271f0,0x77f6f574,0x7bfaf978,0xff7e7dfc
);

const iq3xxs_grid = array<u32, 256>(
    0x04040404, 0x04040414, 0x04040424, 0x04040c0c, 0x04040c1c, 0x04040c3e, 0x04041404, 0x04041414,
    0x04041c0c, 0x04042414, 0x04043e1c, 0x04043e2c, 0x040c040c, 0x040c041c, 0x040c0c04, 0x040c0c14,
    0x040c140c, 0x040c142c, 0x040c1c04, 0x040c1c14, 0x040c240c, 0x040c2c24, 0x040c3e04, 0x04140404,
    0x04140414, 0x04140424, 0x04140c0c, 0x04141404, 0x04141414, 0x04141c0c, 0x04141c1c, 0x04141c3e,
    0x04142c0c, 0x04142c3e, 0x04143e2c, 0x041c040c, 0x041c043e, 0x041c0c04, 0x041c0c14, 0x041c142c,
    0x041c3e04, 0x04240c1c, 0x04241c3e, 0x04242424, 0x04242c3e, 0x04243e1c, 0x04243e2c, 0x042c040c,
    0x042c043e, 0x042c1c14, 0x042c2c14, 0x04341c2c, 0x04343424, 0x043e0c04, 0x043e0c24, 0x043e0c34,
    0x043e241c, 0x043e340c, 0x0c04040c, 0x0c04041c, 0x0c040c04, 0x0c040c14, 0x0c04140c, 0x0c04141c,
    0x0c041c04, 0x0c041c14, 0x0c041c24, 0x0c04243e, 0x0c042c04, 0x0c0c0404, 0x0c0c0414, 0x0c0c0c0c,
    0x0c0c1404, 0x0c0c1414, 0x0c14040c, 0x0c14041c, 0x0c140c04, 0x0c140c14, 0x0c14140c, 0x0c141c04,
    0x0c143e14, 0x0c1c0404, 0x0c1c0414, 0x0c1c1404, 0x0c1c1c0c, 0x0c1c2434, 0x0c1c3434, 0x0c24040c,
    0x0c24042c, 0x0c242c04, 0x0c2c1404, 0x0c2c1424, 0x0c2c2434, 0x0c2c3e0c, 0x0c34042c, 0x0c3e1414,
    0x0c3e2404, 0x14040404, 0x14040414, 0x14040c0c, 0x14040c1c, 0x14041404, 0x14041414, 0x14041434,
    0x14041c0c, 0x14042414, 0x140c040c, 0x140c041c, 0x140c042c, 0x140c0c04, 0x140c0c14, 0x140c140c,
    0x140c1c04, 0x140c341c, 0x140c343e, 0x140c3e04, 0x14140404, 0x14140414, 0x14140c0c, 0x14140c3e,
    0x14141404, 0x14141414, 0x14141c3e, 0x14142404, 0x14142c2c, 0x141c040c, 0x141c0c04, 0x141c0c24,
    0x141c3e04, 0x141c3e24, 0x14241c2c, 0x14242c1c, 0x142c041c, 0x142c143e, 0x142c240c, 0x142c3e24,
    0x143e040c, 0x143e041c, 0x143e0c34, 0x143e242c, 0x1c04040c, 0x1c040c04, 0x1c040c14, 0x1c04140c,
    0x1c04141c, 0x1c042c04, 0x1c04342c, 0x1c043e14, 0x1c0c0404, 0x1c0c0414, 0x1c0c1404, 0x1c0c1c0c,
    0x1c0c2424, 0x1c0c2434, 0x1c14040c, 0x1c14041c, 0x1c140c04, 0x1c14142c, 0x1c142c14, 0x1c143e14,
    0x1c1c0c0c, 0x1c1c1c1c, 0x1c241c04, 0x1c24243e, 0x1c243e14, 0x1c2c0404, 0x1c2c0434, 0x1c2c1414,
    0x1c2c2c2c, 0x1c340c24, 0x1c341c34, 0x1c34341c, 0x1c3e1c1c, 0x1c3e3404, 0x24040424, 0x24040c3e,
    0x24041c2c, 0x24041c3e, 0x24042c1c, 0x24042c3e, 0x240c3e24, 0x24141404, 0x24141c3e, 0x24142404,
    0x24143404, 0x24143434, 0x241c043e, 0x241c242c, 0x24240424, 0x24242c0c, 0x24243424, 0x242c142c,
    0x242c241c, 0x242c3e04, 0x243e042c, 0x243e0c04, 0x243e0c14, 0x243e1c04, 0x2c040c14, 0x2c04240c,
    0x2c043e04, 0x2c0c0404, 0x2c0c0434, 0x2c0c1434, 0x2c0c2c2c, 0x2c140c24, 0x2c141c14, 0x2c143e14,
    0x2c1c0414, 0x2c1c2c1c, 0x2c240c04, 0x2c24141c, 0x2c24143e, 0x2c243e14, 0x2c2c0414, 0x2c2c1c0c,
    0x2c342c04, 0x2c3e1424, 0x2c3e2414, 0x34041424, 0x34042424, 0x34042434, 0x34043424, 0x340c140c,
    0x340c340c, 0x34140c3e, 0x34143424, 0x341c1c04, 0x341c1c34, 0x34242424, 0x342c042c, 0x342c2c14,
    0x34341c1c, 0x343e041c, 0x343e140c, 0x3e04041c, 0x3e04042c, 0x3e04043e, 0x3e040c04, 0x3e041c14,
    0x3e042c14, 0x3e0c1434, 0x3e0c2404, 0x3e140c14, 0x3e14242c, 0x3e142c14, 0x3e1c0404, 0x3e1c0c2c,
    0x3e1c1c1c, 0x3e1c3404, 0x3e24140c, 0x3e24240c, 0x3e2c0404, 0x3e2c0414, 0x3e2c1424, 0x3e341c04
);

struct iq3_xxs {
    d: f16,
    qs: array<f16, 48>
};

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block = src[src_base + offset];
    let d = f32(block.d);
    var dst_i = dst_base + offset * 256;
    for (var ib: u32 = 0; ib < 16; ib += 2) {
        let sc_sign = bitcast<u32>(vec2(block.qs[ib + 32], block.qs[ib + 33]));
        let db = d * (0.5 + f32(sc_sign >> 28)) * 0.5;
        for (var l: u32 = 0; l < 4; l++) {
            let is = (sc_sign >> (7 * l)) & 127;
            let signs = get_byte(ksigns_iq2xs[is / 4], is % 4);
            let ig_val = bitcast<u32>(vec2(block.qs[ib * 2 + l], 0.0));
            let ig1 = get_byte(ig_val, 0);
            let ig2 = get_byte(ig_val, 1);
            for (var j: u32 = 0; j < 4; j++) {
                let g1 = get_byte(iq3xxs_grid[ig1], j);
                let g2 = get_byte(iq3xxs_grid[ig2], j);
                let m1 = select(1.0, -1.0, (get_byte(kmask_iq2xs[0], j) & signs) != 0);
                let m2 = select(1.0, -1.0, (get_byte(kmask_iq2xs[1], j) & signs) != 0);
                dst[dst_i] = db * f32(g1) * m1;
                dst[dst_i + 4] = db * f32(g2) * m2;
                dst_i++;
            }
            dst_i += 4;
        }
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<iq3_xxs>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/256; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_iq3_s = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

const kmask_iq2xs : array<u32, 2> = array<u32, 2>(
    0x08040201u, // 1, 2, 4, 8
    0x80402010u  // 16, 32, 64, 128
);

const ksigns_iq2xs: array<u32, 32> = array<u32, 32>(
    0x03828100,0x87060584,0x8b0a0988,0x0f8e8d0c,
    0x93121190,0x17969514,0x1b9a9918,0x9f1e1d9c,
    0xa32221a0,0x27a6a524,0x2baaa928,0xaf2e2dac,
    0x33b2b130,0xb73635b4,0xbb3a39b8,0x3fbebd3c,
    0xc34241c0,0x47c6c544,0x4bcac948,0xcf4e4dcc,
    0x53d2d150,0xd75655d4,0xdb5a59d8,0x5fdedd5c,
    0x63e2e160,0xe76665e4,0xeb6a69e8,0x6feeed6c,
    0xf37271f0,0x77f6f574,0x7bfaf978,0xff7e7dfc
);

const iq3s_grid = array<u32, 512>(
    0x01010101, 0x01010103, 0x01010105, 0x0101010b, 0x0101010f, 0x01010301, 0x01010303, 0x01010305,
    0x01010309, 0x0101030d, 0x01010501, 0x01010503, 0x0101050b, 0x01010707, 0x01010901, 0x01010905,
    0x0101090b, 0x0101090f, 0x01010b03, 0x01010b07, 0x01010d01, 0x01010d05, 0x01010f03, 0x01010f09,
    0x01010f0f, 0x01030101, 0x01030103, 0x01030105, 0x01030109, 0x01030301, 0x01030303, 0x0103030b,
    0x01030501, 0x01030507, 0x0103050f, 0x01030703, 0x0103070b, 0x01030909, 0x01030d03, 0x01030d0b,
    0x01030f05, 0x01050101, 0x01050103, 0x0105010b, 0x0105010f, 0x01050301, 0x01050307, 0x0105030d,
    0x01050503, 0x0105050b, 0x01050701, 0x01050709, 0x01050905, 0x0105090b, 0x0105090f, 0x01050b03,
    0x01050b07, 0x01050f01, 0x01050f07, 0x01070107, 0x01070303, 0x0107030b, 0x01070501, 0x01070505,
    0x01070703, 0x01070707, 0x0107070d, 0x01070909, 0x01070b01, 0x01070b05, 0x01070d0f, 0x01070f03,
    0x01070f0b, 0x01090101, 0x01090307, 0x0109030f, 0x01090503, 0x01090509, 0x01090705, 0x01090901,
    0x01090907, 0x01090b03, 0x01090f01, 0x010b0105, 0x010b0109, 0x010b0501, 0x010b0505, 0x010b050d,
    0x010b0707, 0x010b0903, 0x010b090b, 0x010b090f, 0x010b0d0d, 0x010b0f07, 0x010d010d, 0x010d0303,
    0x010d0307, 0x010d0703, 0x010d0b05, 0x010d0f03, 0x010f0101, 0x010f0105, 0x010f0109, 0x010f0501,
    0x010f0505, 0x010f050d, 0x010f0707, 0x010f0b01, 0x010f0b09, 0x03010101, 0x03010103, 0x03010105,
    0x03010109, 0x03010301, 0x03010303, 0x03010307, 0x0301030b, 0x0301030f, 0x03010501, 0x03010505,
    0x03010703, 0x03010709, 0x0301070d, 0x03010b09, 0x03010b0d, 0x03010d03, 0x03010f05, 0x03030101,
    0x03030103, 0x03030107, 0x0303010d, 0x03030301, 0x03030309, 0x03030503, 0x03030701, 0x03030707,
    0x03030903, 0x03030b01, 0x03030b05, 0x03030f01, 0x03030f0d, 0x03050101, 0x03050305, 0x0305030b,
    0x0305030f, 0x03050501, 0x03050509, 0x03050705, 0x03050901, 0x03050907, 0x03050b0b, 0x03050d01,
    0x03050f05, 0x03070103, 0x03070109, 0x0307010f, 0x03070301, 0x03070307, 0x03070503, 0x0307050f,
    0x03070701, 0x03070709, 0x03070903, 0x03070d05, 0x03070f01, 0x03090107, 0x0309010b, 0x03090305,
    0x03090309, 0x03090703, 0x03090707, 0x03090905, 0x0309090d, 0x03090b01, 0x03090b09, 0x030b0103,
    0x030b0301, 0x030b0307, 0x030b0503, 0x030b0701, 0x030b0705, 0x030b0b03, 0x030d0501, 0x030d0509,
    0x030d050f, 0x030d0909, 0x030d090d, 0x030f0103, 0x030f0107, 0x030f0301, 0x030f0305, 0x030f0503,
    0x030f070b, 0x030f0903, 0x030f0d05, 0x030f0f01, 0x05010101, 0x05010103, 0x05010107, 0x0501010b,
    0x0501010f, 0x05010301, 0x05010305, 0x05010309, 0x0501030d, 0x05010503, 0x05010507, 0x0501050f,
    0x05010701, 0x05010705, 0x05010903, 0x05010907, 0x0501090b, 0x05010b01, 0x05010b05, 0x05010d0f,
    0x05010f01, 0x05010f07, 0x05010f0b, 0x05030101, 0x05030105, 0x05030301, 0x05030307, 0x0503030f,
    0x05030505, 0x0503050b, 0x05030703, 0x05030709, 0x05030905, 0x05030b03, 0x05050103, 0x05050109,
    0x0505010f, 0x05050503, 0x05050507, 0x05050701, 0x0505070f, 0x05050903, 0x05050b07, 0x05050b0f,
    0x05050f03, 0x05050f09, 0x05070101, 0x05070105, 0x0507010b, 0x05070303, 0x05070505, 0x05070509,
    0x05070703, 0x05070707, 0x05070905, 0x05070b01, 0x05070d0d, 0x05090103, 0x0509010f, 0x05090501,
    0x05090507, 0x05090705, 0x0509070b, 0x05090903, 0x05090f05, 0x05090f0b, 0x050b0109, 0x050b0303,
    0x050b0505, 0x050b070f, 0x050b0901, 0x050b0b07, 0x050b0f01, 0x050d0101, 0x050d0105, 0x050d010f,
    0x050d0503, 0x050d0b0b, 0x050d0d03, 0x050f010b, 0x050f0303, 0x050f050d, 0x050f0701, 0x050f0907,
    0x050f0b01, 0x07010105, 0x07010303, 0x07010307, 0x0701030b, 0x0701030f, 0x07010505, 0x07010703,
    0x07010707, 0x0701070b, 0x07010905, 0x07010909, 0x0701090f, 0x07010b03, 0x07010d07, 0x07010f03,
    0x07030103, 0x07030107, 0x0703010b, 0x07030309, 0x07030503, 0x07030507, 0x07030901, 0x07030d01,
    0x07030f05, 0x07030f0d, 0x07050101, 0x07050305, 0x07050501, 0x07050705, 0x07050709, 0x07050b01,
    0x07070103, 0x07070301, 0x07070309, 0x07070503, 0x07070507, 0x0707050f, 0x07070701, 0x07070903,
    0x07070907, 0x0707090f, 0x07070b0b, 0x07070f07, 0x07090107, 0x07090303, 0x0709030d, 0x07090505,
    0x07090703, 0x07090b05, 0x07090d01, 0x07090d09, 0x070b0103, 0x070b0301, 0x070b0305, 0x070b050b,
    0x070b0705, 0x070b0909, 0x070b0b0d, 0x070b0f07, 0x070d030d, 0x070d0903, 0x070f0103, 0x070f0107,
    0x070f0501, 0x070f0505, 0x070f070b, 0x09010101, 0x09010109, 0x09010305, 0x09010501, 0x09010509,
    0x0901050f, 0x09010705, 0x09010903, 0x09010b01, 0x09010f01, 0x09030105, 0x0903010f, 0x09030303,
    0x09030307, 0x09030505, 0x09030701, 0x0903070b, 0x09030907, 0x09030b03, 0x09030b0b, 0x09050103,
    0x09050107, 0x09050301, 0x0905030b, 0x09050503, 0x09050707, 0x09050901, 0x09050b0f, 0x09050d05,
    0x09050f01, 0x09070109, 0x09070303, 0x09070307, 0x09070501, 0x09070505, 0x09070703, 0x0907070b,
    0x09090101, 0x09090105, 0x09090509, 0x0909070f, 0x09090901, 0x09090f03, 0x090b010b, 0x090b010f,
    0x090b0503, 0x090b0d05, 0x090d0307, 0x090d0709, 0x090d0d01, 0x090f0301, 0x090f030b, 0x090f0701,
    0x090f0907, 0x090f0b03, 0x0b010105, 0x0b010301, 0x0b010309, 0x0b010505, 0x0b010901, 0x0b010909,
    0x0b01090f, 0x0b010b05, 0x0b010d0d, 0x0b010f09, 0x0b030103, 0x0b030107, 0x0b03010b, 0x0b030305,
    0x0b030503, 0x0b030705, 0x0b030f05, 0x0b050101, 0x0b050303, 0x0b050507, 0x0b050701, 0x0b05070d,
    0x0b050b07, 0x0b070105, 0x0b07010f, 0x0b070301, 0x0b07050f, 0x0b070909, 0x0b070b03, 0x0b070d0b,
    0x0b070f07, 0x0b090103, 0x0b090109, 0x0b090501, 0x0b090705, 0x0b09090d, 0x0b0b0305, 0x0b0b050d,
    0x0b0b0b03, 0x0b0b0b07, 0x0b0d0905, 0x0b0f0105, 0x0b0f0109, 0x0b0f0505, 0x0d010303, 0x0d010307,
    0x0d01030b, 0x0d010703, 0x0d010707, 0x0d010d01, 0x0d030101, 0x0d030501, 0x0d03050f, 0x0d030d09,
    0x0d050305, 0x0d050709, 0x0d050905, 0x0d050b0b, 0x0d050d05, 0x0d050f01, 0x0d070101, 0x0d070309,
    0x0d070503, 0x0d070901, 0x0d09050b, 0x0d090907, 0x0d090d05, 0x0d0b0101, 0x0d0b0107, 0x0d0b0709,
    0x0d0b0d01, 0x0d0d010b, 0x0d0d0901, 0x0d0f0303, 0x0d0f0307, 0x0f010101, 0x0f010109, 0x0f01010f,
    0x0f010501, 0x0f010505, 0x0f01070d, 0x0f010901, 0x0f010b09, 0x0f010d05, 0x0f030105, 0x0f030303,
    0x0f030509, 0x0f030907, 0x0f03090b, 0x0f050103, 0x0f050109, 0x0f050301, 0x0f05030d, 0x0f050503,
    0x0f050701, 0x0f050b03, 0x0f070105, 0x0f070705, 0x0f07070b, 0x0f070b07, 0x0f090103, 0x0f09010b,
    0x0f090307, 0x0f090501, 0x0f090b01, 0x0f0b0505, 0x0f0b0905, 0x0f0d0105, 0x0f0d0703, 0x0f0f0101
);

struct iq3_s {
    d: f16,
    qs: array<f16, 32>,
    qh: array<f16, 4>,
    signs: array<f16, 16>,
    scales: array<f16, 2>
};

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block = src[src_base + offset];
    let d = f32(block.d);
    var dst_i = dst_base + offset * 256;
    var qh_vals = array<u32, 2>(
        bitcast<u32>(vec2(block.qh[0], block.qh[1])),
        bitcast<u32>(vec2(block.qh[2], block.qh[3]))
    );
    var sign_vals: array<u32, 8>;
    for (var i: u32 = 0; i < 8; i++) {
        sign_vals[i] = bitcast<u32>(vec2(block.signs[i * 2], block.signs[i * 2 + 1]));
    }
    var scale_vals = bitcast<u32>(vec2(block.scales[0], block.scales[1]));
    for (var ib: u32 = 0; ib < 4; ib++) {
        let s = get_byte(scale_vals, ib);
        let db = array<f32, 2>(
            d * (1.0 + 2.0 * f32(s & 0xF)),
            d * (1.0 + 2.0 * f32(s >> 4))
        );
        for (var k: u32 = 0; k < 2; k++) {
            let dl = db[k];
            let qh_byte = get_byte(qh_vals[ib / 2], (ib % 2) * 2 + k);
            let sign_w = sign_vals[ib * 2 + k];
            for (var l: u32 = 0; l < 4; l++) {
                let signs = get_byte(sign_w, l);
                let ig_val = bitcast<u32>(vec2(block.qs[ib * 8 + k * 4 + l], 0.0));
                let ig1 = get_byte(ig_val, 0) | ((qh_byte << ((8 - (2 * l)))) & 256);
                let ig2 = get_byte(ig_val, 1) | ((qh_byte << ((7 - (2 * l)))) & 256);
                for (var j: u32 = 0; j < 4; j++) {
                    let g1 = get_byte(iq3s_grid[ig1], j);
                    let g2 = get_byte(iq3s_grid[ig2], j);
                    let m1 = select(1.0, -1.0, (get_byte(kmask_iq2xs[0], j) & signs) != 0);
                    let m2 = select(1.0, -1.0, (get_byte(kmask_iq2xs[1], j) & signs) != 0);
                    dst[dst_i] = dl * f32(g1) * m1;
                    dst[dst_i + 4] = dl * f32(g2) * m2;
                    dst_i++;
                }
                dst_i += 4;
            }
        }
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<iq3_s>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/256; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_iq1_s = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

const IQ1_DELTA: f32 = 0.125;

const iq1_grid = array<u32, 1024>(
    0xfffdffff, 0xfff7fff0, 0xffccfff5, 0xffdfffc0, 0xffd7ffdd, 0xff30ffd5, 0xff03ff0c, 0xff10ff01,
    0xff7dff7f, 0xff75ff77, 0xff5fff40, 0xff57ff5d, 0xfcf3ff55, 0xfcccfcf0, 0xfcc1fcc3, 0xfcc5fcc4,
    0xfc3cfcd0, 0xfc34fc31, 0xfc00fc0d, 0xfc1cfc05, 0xfc11fc13, 0xfc70fc17, 0xfc43fc4c, 0xfc50fc41,
    0xfdfdfdff, 0xfdf5fdf7, 0xfddffdc0, 0xfdd7fddd, 0xfd30fdd5, 0xfd04fd0c, 0xfd14fd13, 0xfd7dfd7f,
    0xfd75fd77, 0xfd40fd4c, 0xfd5ffd44, 0xfd57fd5d, 0xf3ccfd55, 0xf3c1f3c3, 0xf33cf3d0, 0xf300f334,
    0xf313f305, 0xf34cf310, 0xf350f344, 0xf0f3f0fc, 0xf0f1f0f0, 0xf0c7f0c0, 0xf0d4f0c5, 0xf030f03f,
    0xf00ff035, 0xf003f00c, 0xf001f000, 0xf01ff004, 0xf010f01d, 0xf015f017, 0xf04cf07c, 0xf047f040,
    0xf05cf045, 0xf050f053, 0xf054f051, 0xf1c4f1c3, 0xf133f13c, 0xf10df10f, 0xf107f100, 0xf11cf11f,
    0xf114f111, 0xf14cf170, 0xf144f143, 0xf7fdf7ff, 0xf7f5f7f7, 0xf7dff7c0, 0xf7d7f7dd, 0xf730f7d5,
    0xf701f70c, 0xf77ff710, 0xf777f77d, 0xf740f775, 0xf75df75f, 0xf755f757, 0xf4ccf4f0, 0xf4c4f4c3,
    0xf4d0f4d3, 0xf40ff43c, 0xf400f40c, 0xf413f41c, 0xf44cf414, 0xf441f443, 0xf450f444, 0xf5fdf5ff,
    0xf5f5f5f7, 0xf5dff5c0, 0xf5d7f5dd, 0xf530f5d5, 0xf504f50c, 0xf510f51c, 0xf57df57f, 0xf577f570,
    0xf540f575, 0xf55df55f, 0xf555f557, 0xcfcccfcf, 0xcfc4cfc3, 0xcfd0cfd3, 0xcf33cf3c, 0xcf00cf0f,
    0xcf1ccf07, 0xcf10cf13, 0xcf4ccf14, 0xcf41cf43, 0xcf50cf5c, 0xccf3ccfc, 0xccf4ccf1, 0xcccdcccf,
    0xccc7ccc0, 0xccd3ccdc, 0xcc30ccd4, 0xcc0fcc35, 0xcc0dcc0c, 0xcc00cc03, 0xcc04cc01, 0xcc10cc1f,
    0xcc4dcc73, 0xcc5ccc40, 0xcdcccc53, 0xcdc1cdc3, 0xcd3fcdd0, 0xcd34cd31, 0xcd00cd0d, 0xcd05cd07,
    0xcd11cd13, 0xcd4ccd70, 0xcd41cd43, 0xc3fccd50, 0xc3f4c3f1, 0xc3c0c3c3, 0xc3c4c3c7, 0xc3d1c3dc,
    0xc330c33c, 0xc337c331, 0xc30cc335, 0xc300c303, 0xc304c301, 0xc310c31d, 0xc373c317, 0xc34fc374,
    0xc340c343, 0xc344c347, 0xc35cc345, 0xc350c353, 0xc0fdc354, 0xc0f5c0f0, 0xc0c3c0cc, 0xc0c1c0c0,
    0xc0dfc0c4, 0xc0d0c0dd, 0xc0d5c0d7, 0xc033c03c, 0xc031c030, 0xc00dc00c, 0xc000c003, 0xc004c001,
    0xc01cc005, 0xc010c013, 0xc014c011, 0xc07dc07f, 0xc070c073, 0xc075c077, 0xc04cc04f, 0xc040c043,
    0xc044c041, 0xc05fc045, 0xc050c05d, 0xc1f3c1fc, 0xc1f1c1f0, 0xc1c1c1c0, 0xc1c5c1c7, 0xc1d1c1dc,
    0xc13dc13f, 0xc130c133, 0xc135c137, 0xc100c10c, 0xc107c101, 0xc11cc104, 0xc110c113, 0xc114c117,
    0xc171c115, 0xc14dc175, 0xc153c140, 0xc7ccc154, 0xc7d0c7c1, 0xc733c73c, 0xc734c731, 0xc700c70f,
    0xc705c707, 0xc71cc71f, 0xc711c713, 0xc770c714, 0xc743c74c, 0xc4cfc750, 0xc4c0c4cd, 0xc4dcc4c5,
    0xc43dc4d0, 0xc430c433, 0xc40cc437, 0xc400c403, 0xc404c401, 0xc41fc405, 0xc415c410, 0xc44cc474,
    0xc440c44d, 0xc45cc447, 0xc454c451, 0xc5c1c5f4, 0xc5d1c5d3, 0xc531c533, 0xc50fc534, 0xc500c50d,
    0xc51cc507, 0xc514c511, 0xc54cc570, 0xc545c541, 0xdffddfff, 0xdff5dff7, 0xdfdfdfc0, 0xdfd0dfdd,
    0xdfd5dfd7, 0xdf0cdf30, 0xdf1cdf04, 0xdf7fdf10, 0xdf77df7d, 0xdf40df75, 0xdf5ddf5f, 0xdf57df50,
    0xdcf0df55, 0xdcc3dccc, 0xdcd0dcc4, 0xdc33dc3d, 0xdc00dc34, 0xdc05dc07, 0xdc13dc1c, 0xdc11dc10,
    0xdc4fdc70, 0xdc44dc41, 0xddfcdc50, 0xddf5ddf7, 0xddc0ddcc, 0xdddddddf, 0xddd5ddd7, 0xdd0cdd30,
    0xdd04dd01, 0xdd7cdd10, 0xdd75dd77, 0xdd40dd4c, 0xdd5ddd5f, 0xdd55dd57, 0xd3c3d3f0, 0xd3c4d3c1,
    0xd333d3d0, 0xd331d330, 0xd30dd334, 0xd307d300, 0xd311d305, 0xd34cd370, 0xd344d343, 0xd350d35c,
    0xd0c0d0f4, 0xd0d4d0dc, 0xd030d03f, 0xd00cd037, 0xd000d003, 0xd01dd004, 0xd017d010, 0xd04fd074,
    0xd040d043, 0xd045d047, 0xd053d05c, 0xd054d051, 0xd1cfd1f0, 0xd1c4d1cd, 0xd13cd1d0, 0xd100d134,
    0xd11cd11f, 0xd173d114, 0xd14fd171, 0xd7ffd145, 0xd7f7d7fd, 0xd7c0d7f5, 0xd7ddd7df, 0xd7d5d7d7,
    0xd70cd730, 0xd710d703, 0xd77dd77f, 0xd775d777, 0xd75dd75f, 0xd755d757, 0xd4ccd4f4, 0xd4c4d4c3,
    0xd431d4d0, 0xd40dd434, 0xd41cd400, 0xd411d413, 0xd470d414, 0xd441d44f, 0xd453d444, 0xd5ffd450,
    0xd5f7d5fd, 0xd5dfd5f5, 0xd5d7d5dd, 0xd530d5d5, 0xd501d50c, 0xd510d504, 0xd57dd57f, 0xd575d577,
    0xd55fd540, 0xd557d55d, 0x3ff0d555, 0x3fc13fcc, 0x3f343fd0, 0x3f003f0d, 0x3f053f07, 0x3f133f1c,
    0x3f433f11, 0x3f5c3f44, 0x3cff3f51, 0x3cf33cfc, 0x3cf43cf1, 0x3cc03ccd, 0x3cc73cc1, 0x3cdc3cc5,
    0x3cd43cd1, 0x3c373c30, 0x3c0c3c35, 0x3c003c03, 0x3c043c01, 0x3c103c05, 0x3c153c17, 0x3c733c7c,
    0x3c4f3c71, 0x3c403c4d, 0x3c5c3c5f, 0x3df03c5d, 0x3dc33dcc, 0x3dd03dc1, 0x3d0d3d3c, 0x3d053d00,
    0x3d143d13, 0x3d433d74, 0x33fc3d50, 0x33c433c0, 0x333033d4, 0x33353337, 0x3303330c, 0x33013300,
    0x331d331c, 0x33173310, 0x337c3315, 0x33743371, 0x334d334f, 0x335f3340, 0x3354335c, 0x30fd30fc,
    0x30f530f0, 0x30c330cc, 0x30c130c0, 0x30df30c4, 0x30d530d0, 0x3033303c, 0x30313030, 0x300f3034,
    0x3003300c, 0x30013000, 0x30043007, 0x3013301c, 0x30113010, 0x307d3014, 0x30703073, 0x304c3077,
    0x30403043, 0x30443041, 0x30503045, 0x30553057, 0x31f031fc, 0x31c331f4, 0x31c731c0, 0x31dc31c5,
    0x31d431d3, 0x313d313f, 0x31373130, 0x310c310f, 0x3100310d, 0x31043101, 0x3110311d, 0x317c3117,
    0x31753170, 0x31403143, 0x3153315c, 0x37f03151, 0x37c037cc, 0x37d037c5, 0x3734373d, 0x3700370f,
    0x371c3707, 0x37113713, 0x37703714, 0x3743374c, 0x37443741, 0x34fc3750, 0x34f134f0, 0x34cf34f5,
    0x34c034c3, 0x34dc34c7, 0x34d134d3, 0x3430343f, 0x340c3435, 0x3403340d, 0x34013400, 0x341f3404,
    0x3410341d, 0x34153411, 0x34743471, 0x3440344d, 0x34473441, 0x3453345c, 0x34543451, 0x353335c1,
    0x35343531, 0x35073500, 0x35133505, 0x35433514, 0x0ffc3550, 0x0ff00ff3, 0x0ff40ff1, 0x0fc00fcd,
    0x0fdc0fc5, 0x0fd40fd3, 0x0f300f3f, 0x0f0c0f37, 0x0f000f03, 0x0f040f01, 0x0f170f10, 0x0f740f71,
    0x0f470f40, 0x0f5c0f5f, 0x0f540f51, 0x0cf70cf0, 0x0cf50cf4, 0x0cc30ccc, 0x0cc10cc0, 0x0cc40cc7,
    0x0cd00cdf, 0x0cd70cd1, 0x0c3c0cd5, 0x0c300c33, 0x0c340c31, 0x0c0c0c0f, 0x0c030c0d, 0x0c010c00,
    0x0c040c07, 0x0c1c0c05, 0x0c100c13, 0x0c140c11, 0x0c700c7d, 0x0c430c4c, 0x0c410c40, 0x0c5f0c44,
    0x0c550c50, 0x0df10dfc, 0x0dc00dcd, 0x0ddc0dc5, 0x0d3d0dd3, 0x0d350d30, 0x0d030d0c, 0x0d010d00,
    0x0d1d0d04, 0x0d700d10, 0x0d4d0d4f, 0x0d440d40, 0x0d530d45, 0x03f003f3, 0x03c303cc, 0x03c103c0,
    0x03c403c7, 0x03d003dc, 0x03d503d7, 0x0333033c, 0x03310330, 0x03350334, 0x030c030f, 0x03000303,
    0x03070301, 0x03050304, 0x031d031c, 0x03100313, 0x03140311, 0x0377037f, 0x034c0375, 0x03400343,
    0x03440341, 0x0353035c, 0x03550350, 0x00fd00fc, 0x00f000f3, 0x00f400f1, 0x00cc00cf, 0x00c300cd,
    0x00c100c0, 0x00c500c4, 0x00d300dc, 0x00d100d0, 0x003f00d4, 0x003d003c, 0x00300033, 0x00370031,
    0x000f0034, 0x000d000c, 0x00000003, 0x00070001, 0x00050004, 0x001c001f, 0x00100013, 0x00170011,
    0x00150014, 0x0073007c, 0x00740070, 0x004f0075, 0x0043004c, 0x00410040, 0x00440047, 0x0053005c,
    0x00510050, 0x01ff0054, 0x01fd01fc, 0x01f101f3, 0x01f401f7, 0x01c301cc, 0x01c701c0, 0x01df01c4,
    0x01dd01dc, 0x01d001d3, 0x01d701d1, 0x013c01d4, 0x01310130, 0x01340137, 0x010f0135, 0x010d010c,
    0x01000103, 0x01070101, 0x01050104, 0x0113011c, 0x01140110, 0x0170017d, 0x01770171, 0x01750174,
    0x0140014c, 0x015d0145, 0x01510150, 0x01540157, 0x07f007f3, 0x07f407f1, 0x07c007cf, 0x07dc07c7,
    0x073007d5, 0x07350737, 0x0703070c, 0x07010700, 0x07040707, 0x071d071f, 0x07100713, 0x0774077d,
    0x074d074f, 0x07470740, 0x0754075c, 0x04fd04fc, 0x04f504f0, 0x04c304cc, 0x04c104c0, 0x04d004c4,
    0x0433043c, 0x04310430, 0x040f0434, 0x040d040c, 0x04000403, 0x04070401, 0x04050404, 0x0413041c,
    0x04110410, 0x047c0414, 0x04740470, 0x0443044c, 0x04410440, 0x04440447, 0x05f30450, 0x05c005f7,
    0x05df05c5, 0x05d105d0, 0x053005d4, 0x05340537, 0x0500050c, 0x05070501, 0x051d0504, 0x05170510,
    0x057c0515, 0x054d0575, 0x05410540, 0x05450547, 0x1ff0055c, 0x1fc11fc3, 0x1fd01fc4, 0x1f0f1f33,
    0x1f011f00, 0x1f051f07, 0x1f131f1c, 0x1f141f11, 0x1f411f7c, 0x1cfc1f50, 0x1cf11cf3, 0x1ccd1cf4,
    0x1cdc1cc0, 0x1cd11cdd, 0x1c301cd4, 0x1c0c1c34, 0x1c011c00, 0x1c101c04, 0x1c151c11, 0x1c751c73,
    0x1c401c4d, 0x1c511c5c, 0x1dcc1c54, 0x1dc41dc1, 0x1d3c1d3f, 0x1d001d31, 0x1d071d01, 0x1d701d1f,
    0x1d411d4c, 0x13cc1d50, 0x13c013cd, 0x13c513c1, 0x13d113dc, 0x133f13d4, 0x1330133d, 0x13351337,
    0x1303130c, 0x13011300, 0x13051304, 0x131d131f, 0x13731310, 0x13741370, 0x134d134f, 0x13401343,
    0x13471341, 0x135c1345, 0x13541353, 0x10f710f0, 0x10cc10f5, 0x10c110c0, 0x103310c4, 0x10311030,
    0x100f1034, 0x1003100c, 0x10011000, 0x101c1004, 0x10101013, 0x10141011, 0x10741071, 0x104c1075,
    0x10411040, 0x10451044, 0x1050105d, 0x10571051, 0x11f411fd, 0x11df11c0, 0x11d711d1, 0x113f11d4,
    0x11371130, 0x110c1135, 0x11001103, 0x11071101, 0x111f1105, 0x11171110, 0x117d117f, 0x11751170,
    0x11411143, 0x11441147, 0x1153115f, 0x11551151, 0x17c417c1, 0x173c17d0, 0x1700170d, 0x171c1705,
    0x17701714, 0x1747174c, 0x14fc1751, 0x14cf14f3, 0x14dc14c0, 0x14d114d3, 0x143f14d4, 0x1430143c,
    0x14371431, 0x1403140c, 0x14011400, 0x141f1404, 0x14151410, 0x1473147d, 0x14401475, 0x1453145c,
    0x14541450, 0x15c115cc, 0x153c15c7, 0x15341533, 0x1500150f, 0x15051507, 0x15101513, 0x15711514,
    0x15471543, 0x15511545, 0x7ffd7fff, 0x7ff57ff7, 0x7fdd7fdf, 0x7fd57fd7, 0x7f0f7f30, 0x7f037f0c,
    0x7f047f01, 0x7f7f7f10, 0x7f777f7d, 0x7f407f75, 0x7f5d7f5f, 0x7f557f57, 0x7ccc7cf0, 0x7cc17cc3,
    0x7cd07cc4, 0x7c337c3c, 0x7c0f7c34, 0x7c007c0d, 0x7c077c01, 0x7c137c04, 0x7c147c11, 0x7c747c70,
    0x7c417c43, 0x7c507c44, 0x7dfd7dff, 0x7df57df7, 0x7ddf7dc0, 0x7dd77ddd, 0x7d0c7dd5, 0x7d047d03,
    0x7d7f7d10, 0x7d777d7d, 0x7d407d75, 0x7d5d7d5f, 0x7d557d57, 0x73c473c3, 0x7333733c, 0x7300730c,
    0x731c7305, 0x73147313, 0x73447343, 0x70f470fc, 0x70c070cd, 0x70d170c5, 0x703f70d4, 0x7030703c,
    0x700c7037, 0x70007003, 0x70047001, 0x70107005, 0x70177011, 0x707c7015, 0x70717073, 0x704f7074,
    0x7040704d, 0x70517047, 0x71c171cc, 0x71d071c4, 0x7133713c, 0x71357134, 0x7100710f, 0x71057104,
    0x7111711c, 0x71707115, 0x7145714c, 0x77ff7153, 0x77f777fd, 0x77c077f5, 0x77dd77df, 0x77d577d7,
    0x7730773c, 0x7703770c, 0x77107704, 0x777f7714, 0x7777777d, 0x77407775, 0x775d775f, 0x77557757,
    0x74f174f0, 0x74c374cc, 0x74d074c1, 0x7433743c, 0x74347431, 0x740d740f, 0x74057400, 0x7413741c,
    0x74417470, 0x74507444, 0x75fd75ff, 0x75f575f7, 0x75df75c0, 0x75d775dd, 0x753075d5, 0x7503750c,
    0x757f7501, 0x7577757d, 0x75407575, 0x755d755f, 0x75557557, 0x4fcc4ff0, 0x4fc74fc1, 0x4fd04fc4,
    0x4f314f3c, 0x4f004f34, 0x4f054f07, 0x4f154f14, 0x4f4c4f70, 0x4f414f43, 0x4f504f44, 0x4cf34cfc,
    0x4cf44cf1, 0x4cc04ccf, 0x4cc54cc7, 0x4cd34cdc, 0x4cd44cd1, 0x4c304c3f, 0x4c0c4c0f, 0x4c004c03,
    0x4c044c01, 0x4c104c1d, 0x4c714c73, 0x4c404c4d, 0x4c5c4c47, 0x4c514c53, 0x4df04c54, 0x4dc34dcc,
    0x4dd04dc4, 0x4d314d33, 0x4d0f4d34, 0x4d004d0d, 0x4d114d07, 0x4d704d14, 0x4d414d43, 0x43fc4d54,
    0x43f143f3, 0x43c043cf, 0x43d143c7, 0x4335433f, 0x4303430c, 0x43014300, 0x43044307, 0x431c431f,
    0x4310431d, 0x43714373, 0x4343434d, 0x43474340, 0x4354435c, 0x40f040ff, 0x40f540f7, 0x40cc40cf,
    0x40c040c3, 0x40c440c1, 0x40d040dc, 0x40d540d4, 0x4033403c, 0x40314030, 0x400f4034, 0x400d400c,
    0x40004003, 0x40074001, 0x40054004, 0x4013401c, 0x40114010, 0x407c4014, 0x40774070, 0x404d404c,
    0x40404043, 0x40444041, 0x405f4045, 0x4050405d, 0x40554057, 0x41f341fc, 0x41c041cf, 0x41df41c4,
    0x41d441d1, 0x41374130, 0x410c4134, 0x4100410d, 0x41044101, 0x41174110, 0x4173417d, 0x41754174,
    0x4143414d, 0x41534140, 0x41544151, 0x47c147f0, 0x47d047c4, 0x4731473c, 0x470d470f, 0x47014700,
    0x47134705, 0x47704710, 0x4741474c, 0x47504744, 0x44f144f3, 0x44cf44f4, 0x44c044cd, 0x44c544c7,
    0x44dc44df, 0x44d144d3, 0x443d443f, 0x44374430, 0x440c4435, 0x44004403, 0x44044401, 0x4410441d,
    0x44154411, 0x4473447c, 0x444d444f, 0x44454440, 0x4451445c, 0x45c045f0, 0x453345d0, 0x45344531,
    0x4500450f, 0x451c4507, 0x454c4570, 0x45404543, 0x5fff4541, 0x5ff75ffd, 0x5fc05ff5, 0x5fdd5fdf,
    0x5fd55fd7, 0x5f0c5f30, 0x5f015f03, 0x5f7f5f04, 0x5f775f7d, 0x5f405f75, 0x5f5d5f5f, 0x5f555f57,
    0x5cf45cf0, 0x5cc35ccc, 0x5cc45cc1, 0x5c315cc5, 0x5c0c5c34, 0x5c075c00, 0x5c1c5c05, 0x5c705c13,
    0x5c4d5c4f, 0x5c445c41, 0x5df75dfd, 0x5dcf5df5, 0x5ddd5dc4, 0x5dd55dd7, 0x5d0c5d30, 0x5d045d01,
    0x5d7f5d10, 0x5d775d7d, 0x5d405d75, 0x5d5d5d5f, 0x5d555d57, 0x53d053c4, 0x5333533c, 0x5303530f,
    0x53075300, 0x531c5305, 0x53115310, 0x53145317, 0x50f15370, 0x50cf50f4, 0x50c050cd, 0x50d150c7,
    0x503d50d4, 0x500c5030, 0x50005003, 0x50045001, 0x50155010, 0x5073507c, 0x50715070, 0x504d5074,
    0x50475040, 0x51cc51f0, 0x51c551c1, 0x51d051dc, 0x51315133, 0x510d5135, 0x51015100, 0x511f5107,
    0x5171511d, 0x5140514f, 0x51445141, 0x5153515c, 0x57ff5151, 0x57f757fd, 0x57df57f5, 0x57d757dd,
    0x570c57d5, 0x57015703, 0x577f5704, 0x5777577d, 0x57405775, 0x575d575f, 0x57555757, 0x54c354f0,
    0x54dc54c4, 0x543c54d0, 0x5400540f, 0x541c5405, 0x54145411, 0x5441544f, 0x55fd55ff, 0x55f555f7,
    0x55dd55df, 0x55d555d7, 0x5503550c, 0x557f5501, 0x5577557d, 0x55405575, 0x555d555f, 0x55555557
);

struct iq1_s {
    d: f16,
    qs: array<f16, 16>,
    qh: array<f16, 8>
};

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block = src[src_base + offset];
    let d = f32(block.d);
    var dst_i = dst_base + offset * 256;
    for (var ib: u32 = 0; ib < 8; ib++) {
        let qh = bitcast<u32>(vec2(block.qh[ib], 0.0));
        let dl = d * (2 * f32((qh >> 12) & 7) + 1);
        let delta = select(IQ1_DELTA, -IQ1_DELTA, (qh & 0x8000) != 0);
        let qs_w = bitcast<u32>(vec2(block.qs[ib * 2], block.qs[ib * 2 + 1]));
        for (var l: u32 = 0; l < 4; l++) {
            let ig = (get_byte(qs_w, l) | (((qh >> (3 * l)) & 7) << 8)) * 8;
            for (var j: u32 = 0; j < 8; j++) {
                let gw = iq1_grid[(ig + j) / 16];
                let g = (gw >> (((ig + j) % 16) * 2)) & 3;
                let gs = bitcast<i32>(g << 30) >> 30;
                dst[dst_i] = dl * (f32(gs) + delta);
                dst_i++;
            }
        }
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<iq1_s>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/256; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_iq1_m = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

const IQ1_DELTA: f32 = 0.125;

const iq1_grid = array<u32, 1024>(
    0xfffdffff, 0xfff7fff0, 0xffccfff5, 0xffdfffc0, 0xffd7ffdd, 0xff30ffd5, 0xff03ff0c, 0xff10ff01,
    0xff7dff7f, 0xff75ff77, 0xff5fff40, 0xff57ff5d, 0xfcf3ff55, 0xfcccfcf0, 0xfcc1fcc3, 0xfcc5fcc4,
    0xfc3cfcd0, 0xfc34fc31, 0xfc00fc0d, 0xfc1cfc05, 0xfc11fc13, 0xfc70fc17, 0xfc43fc4c, 0xfc50fc41,
    0xfdfdfdff, 0xfdf5fdf7, 0xfddffdc0, 0xfdd7fddd, 0xfd30fdd5, 0xfd04fd0c, 0xfd14fd13, 0xfd7dfd7f,
    0xfd75fd77, 0xfd40fd4c, 0xfd5ffd44, 0xfd57fd5d, 0xf3ccfd55, 0xf3c1f3c3, 0xf33cf3d0, 0xf300f334,
    0xf313f305, 0xf34cf310, 0xf350f344, 0xf0f3f0fc, 0xf0f1f0f0, 0xf0c7f0c0, 0xf0d4f0c5, 0xf030f03f,
    0xf00ff035, 0xf003f00c, 0xf001f000, 0xf01ff004, 0xf010f01d, 0xf015f017, 0xf04cf07c, 0xf047f040,
    0xf05cf045, 0xf050f053, 0xf054f051, 0xf1c4f1c3, 0xf133f13c, 0xf10df10f, 0xf107f100, 0xf11cf11f,
    0xf114f111, 0xf14cf170, 0xf144f143, 0xf7fdf7ff, 0xf7f5f7f7, 0xf7dff7c0, 0xf7d7f7dd, 0xf730f7d5,
    0xf701f70c, 0xf77ff710, 0xf777f77d, 0xf740f775, 0xf75df75f, 0xf755f757, 0xf4ccf4f0, 0xf4c4f4c3,
    0xf4d0f4d3, 0xf40ff43c, 0xf400f40c, 0xf413f41c, 0xf44cf414, 0xf441f443, 0xf450f444, 0xf5fdf5ff,
    0xf5f5f5f7, 0xf5dff5c0, 0xf5d7f5dd, 0xf530f5d5, 0xf504f50c, 0xf510f51c, 0xf57df57f, 0xf577f570,
    0xf540f575, 0xf55df55f, 0xf555f557, 0xcfcccfcf, 0xcfc4cfc3, 0xcfd0cfd3, 0xcf33cf3c, 0xcf00cf0f,
    0xcf1ccf07, 0xcf10cf13, 0xcf4ccf14, 0xcf41cf43, 0xcf50cf5c, 0xccf3ccfc, 0xccf4ccf1, 0xcccdcccf,
    0xccc7ccc0, 0xccd3ccdc, 0xcc30ccd4, 0xcc0fcc35, 0xcc0dcc0c, 0xcc00cc03, 0xcc04cc01, 0xcc10cc1f,
    0xcc4dcc73, 0xcc5ccc40, 0xcdcccc53, 0xcdc1cdc3, 0xcd3fcdd0, 0xcd34cd31, 0xcd00cd0d, 0xcd05cd07,
    0xcd11cd13, 0xcd4ccd70, 0xcd41cd43, 0xc3fccd50, 0xc3f4c3f1, 0xc3c0c3c3, 0xc3c4c3c7, 0xc3d1c3dc,
    0xc330c33c, 0xc337c331, 0xc30cc335, 0xc300c303, 0xc304c301, 0xc310c31d, 0xc373c317, 0xc34fc374,
    0xc340c343, 0xc344c347, 0xc35cc345, 0xc350c353, 0xc0fdc354, 0xc0f5c0f0, 0xc0c3c0cc, 0xc0c1c0c0,
    0xc0dfc0c4, 0xc0d0c0dd, 0xc0d5c0d7, 0xc033c03c, 0xc031c030, 0xc00dc00c, 0xc000c003, 0xc004c001,
    0xc01cc005, 0xc010c013, 0xc014c011, 0xc07dc07f, 0xc070c073, 0xc075c077, 0xc04cc04f, 0xc040c043,
    0xc044c041, 0xc05fc045, 0xc050c05d, 0xc1f3c1fc, 0xc1f1c1f0, 0xc1c1c1c0, 0xc1c5c1c7, 0xc1d1c1dc,
    0xc13dc13f, 0xc130c133, 0xc135c137, 0xc100c10c, 0xc107c101, 0xc11cc104, 0xc110c113, 0xc114c117,
    0xc171c115, 0xc14dc175, 0xc153c140, 0xc7ccc154, 0xc7d0c7c1, 0xc733c73c, 0xc734c731, 0xc700c70f,
    0xc705c707, 0xc71cc71f, 0xc711c713, 0xc770c714, 0xc743c74c, 0xc4cfc750, 0xc4c0c4cd, 0xc4dcc4c5,
    0xc43dc4d0, 0xc430c433, 0xc40cc437, 0xc400c403, 0xc404c401, 0xc41fc405, 0xc415c410, 0xc44cc474,
    0xc440c44d, 0xc45cc447, 0xc454c451, 0xc5c1c5f4, 0xc5d1c5d3, 0xc531c533, 0xc50fc534, 0xc500c50d,
    0xc51cc507, 0xc514c511, 0xc54cc570, 0xc545c541, 0xdffddfff, 0xdff5dff7, 0xdfdfdfc0, 0xdfd0dfdd,
    0xdfd5dfd7, 0xdf0cdf30, 0xdf1cdf04, 0xdf7fdf10, 0xdf77df7d, 0xdf40df75, 0xdf5ddf5f, 0xdf57df50,
    0xdcf0df55, 0xdcc3dccc, 0xdcd0dcc4, 0xdc33dc3d, 0xdc00dc34, 0xdc05dc07, 0xdc13dc1c, 0xdc11dc10,
    0xdc4fdc70, 0xdc44dc41, 0xddfcdc50, 0xddf5ddf7, 0xddc0ddcc, 0xdddddddf, 0xddd5ddd7, 0xdd0cdd30,
    0xdd04dd01, 0xdd7cdd10, 0xdd75dd77, 0xdd40dd4c, 0xdd5ddd5f, 0xdd55dd57, 0xd3c3d3f0, 0xd3c4d3c1,
    0xd333d3d0, 0xd331d330, 0xd30dd334, 0xd307d300, 0xd311d305, 0xd34cd370, 0xd344d343, 0xd350d35c,
    0xd0c0d0f4, 0xd0d4d0dc, 0xd030d03f, 0xd00cd037, 0xd000d003, 0xd01dd004, 0xd017d010, 0xd04fd074,
    0xd040d043, 0xd045d047, 0xd053d05c, 0xd054d051, 0xd1cfd1f0, 0xd1c4d1cd, 0xd13cd1d0, 0xd100d134,
    0xd11cd11f, 0xd173d114, 0xd14fd171, 0xd7ffd145, 0xd7f7d7fd, 0xd7c0d7f5, 0xd7ddd7df, 0xd7d5d7d7,
    0xd70cd730, 0xd710d703, 0xd77dd77f, 0xd775d777, 0xd75dd75f, 0xd755d757, 0xd4ccd4f4, 0xd4c4d4c3,
    0xd431d4d0, 0xd40dd434, 0xd41cd400, 0xd411d413, 0xd470d414, 0xd441d44f, 0xd453d444, 0xd5ffd450,
    0xd5f7d5fd, 0xd5dfd5f5, 0xd5d7d5dd, 0xd530d5d5, 0xd501d50c, 0xd510d504, 0xd57dd57f, 0xd575d577,
    0xd55fd540, 0xd557d55d, 0x3ff0d555, 0x3fc13fcc, 0x3f343fd0, 0x3f003f0d, 0x3f053f07, 0x3f133f1c,
    0x3f433f11, 0x3f5c3f44, 0x3cff3f51, 0x3cf33cfc, 0x3cf43cf1, 0x3cc03ccd, 0x3cc73cc1, 0x3cdc3cc5,
    0x3cd43cd1, 0x3c373c30, 0x3c0c3c35, 0x3c003c03, 0x3c043c01, 0x3c103c05, 0x3c153c17, 0x3c733c7c,
    0x3c4f3c71, 0x3c403c4d, 0x3c5c3c5f, 0x3df03c5d, 0x3dc33dcc, 0x3dd03dc1, 0x3d0d3d3c, 0x3d053d00,
    0x3d143d13, 0x3d433d74, 0x33fc3d50, 0x33c433c0, 0x333033d4, 0x33353337, 0x3303330c, 0x33013300,
    0x331d331c, 0x33173310, 0x337c3315, 0x33743371, 0x334d334f, 0x335f3340, 0x3354335c, 0x30fd30fc,
    0x30f530f0, 0x30c330cc, 0x30c130c0, 0x30df30c4, 0x30d530d0, 0x3033303c, 0x30313030, 0x300f3034,
    0x3003300c, 0x30013000, 0x30043007, 0x3013301c, 0x30113010, 0x307d3014, 0x30703073, 0x304c3077,
    0x30403043, 0x30443041, 0x30503045, 0x30553057, 0x31f031fc, 0x31c331f4, 0x31c731c0, 0x31dc31c5,
    0x31d431d3, 0x313d313f, 0x31373130, 0x310c310f, 0x3100310d, 0x31043101, 0x3110311d, 0x317c3117,
    0x31753170, 0x31403143, 0x3153315c, 0x37f03151, 0x37c037cc, 0x37d037c5, 0x3734373d, 0x3700370f,
    0x371c3707, 0x37113713, 0x37703714, 0x3743374c, 0x37443741, 0x34fc3750, 0x34f134f0, 0x34cf34f5,
    0x34c034c3, 0x34dc34c7, 0x34d134d3, 0x3430343f, 0x340c3435, 0x3403340d, 0x34013400, 0x341f3404,
    0x3410341d, 0x34153411, 0x34743471, 0x3440344d, 0x34473441, 0x3453345c, 0x34543451, 0x353335c1,
    0x35343531, 0x35073500, 0x35133505, 0x35433514, 0x0ffc3550, 0x0ff00ff3, 0x0ff40ff1, 0x0fc00fcd,
    0x0fdc0fc5, 0x0fd40fd3, 0x0f300f3f, 0x0f0c0f37, 0x0f000f03, 0x0f040f01, 0x0f170f10, 0x0f740f71,
    0x0f470f40, 0x0f5c0f5f, 0x0f540f51, 0x0cf70cf0, 0x0cf50cf4, 0x0cc30ccc, 0x0cc10cc0, 0x0cc40cc7,
    0x0cd00cdf, 0x0cd70cd1, 0x0c3c0cd5, 0x0c300c33, 0x0c340c31, 0x0c0c0c0f, 0x0c030c0d, 0x0c010c00,
    0x0c040c07, 0x0c1c0c05, 0x0c100c13, 0x0c140c11, 0x0c700c7d, 0x0c430c4c, 0x0c410c40, 0x0c5f0c44,
    0x0c550c50, 0x0df10dfc, 0x0dc00dcd, 0x0ddc0dc5, 0x0d3d0dd3, 0x0d350d30, 0x0d030d0c, 0x0d010d00,
    0x0d1d0d04, 0x0d700d10, 0x0d4d0d4f, 0x0d440d40, 0x0d530d45, 0x03f003f3, 0x03c303cc, 0x03c103c0,
    0x03c403c7, 0x03d003dc, 0x03d503d7, 0x0333033c, 0x03310330, 0x03350334, 0x030c030f, 0x03000303,
    0x03070301, 0x03050304, 0x031d031c, 0x03100313, 0x03140311, 0x0377037f, 0x034c0375, 0x03400343,
    0x03440341, 0x0353035c, 0x03550350, 0x00fd00fc, 0x00f000f3, 0x00f400f1, 0x00cc00cf, 0x00c300cd,
    0x00c100c0, 0x00c500c4, 0x00d300dc, 0x00d100d0, 0x003f00d4, 0x003d003c, 0x00300033, 0x00370031,
    0x000f0034, 0x000d000c, 0x00000003, 0x00070001, 0x00050004, 0x001c001f, 0x00100013, 0x00170011,
    0x00150014, 0x0073007c, 0x00740070, 0x004f0075, 0x0043004c, 0x00410040, 0x00440047, 0x0053005c,
    0x00510050, 0x01ff0054, 0x01fd01fc, 0x01f101f3, 0x01f401f7, 0x01c301cc, 0x01c701c0, 0x01df01c4,
    0x01dd01dc, 0x01d001d3, 0x01d701d1, 0x013c01d4, 0x01310130, 0x01340137, 0x010f0135, 0x010d010c,
    0x01000103, 0x01070101, 0x01050104, 0x0113011c, 0x01140110, 0x0170017d, 0x01770171, 0x01750174,
    0x0140014c, 0x015d0145, 0x01510150, 0x01540157, 0x07f007f3, 0x07f407f1, 0x07c007cf, 0x07dc07c7,
    0x073007d5, 0x07350737, 0x0703070c, 0x07010700, 0x07040707, 0x071d071f, 0x07100713, 0x0774077d,
    0x074d074f, 0x07470740, 0x0754075c, 0x04fd04fc, 0x04f504f0, 0x04c304cc, 0x04c104c0, 0x04d004c4,
    0x0433043c, 0x04310430, 0x040f0434, 0x040d040c, 0x04000403, 0x04070401, 0x04050404, 0x0413041c,
    0x04110410, 0x047c0414, 0x04740470, 0x0443044c, 0x04410440, 0x04440447, 0x05f30450, 0x05c005f7,
    0x05df05c5, 0x05d105d0, 0x053005d4, 0x05340537, 0x0500050c, 0x05070501, 0x051d0504, 0x05170510,
    0x057c0515, 0x054d0575, 0x05410540, 0x05450547, 0x1ff0055c, 0x1fc11fc3, 0x1fd01fc4, 0x1f0f1f33,
    0x1f011f00, 0x1f051f07, 0x1f131f1c, 0x1f141f11, 0x1f411f7c, 0x1cfc1f50, 0x1cf11cf3, 0x1ccd1cf4,
    0x1cdc1cc0, 0x1cd11cdd, 0x1c301cd4, 0x1c0c1c34, 0x1c011c00, 0x1c101c04, 0x1c151c11, 0x1c751c73,
    0x1c401c4d, 0x1c511c5c, 0x1dcc1c54, 0x1dc41dc1, 0x1d3c1d3f, 0x1d001d31, 0x1d071d01, 0x1d701d1f,
    0x1d411d4c, 0x13cc1d50, 0x13c013cd, 0x13c513c1, 0x13d113dc, 0x133f13d4, 0x1330133d, 0x13351337,
    0x1303130c, 0x13011300, 0x13051304, 0x131d131f, 0x13731310, 0x13741370, 0x134d134f, 0x13401343,
    0x13471341, 0x135c1345, 0x13541353, 0x10f710f0, 0x10cc10f5, 0x10c110c0, 0x103310c4, 0x10311030,
    0x100f1034, 0x1003100c, 0x10011000, 0x101c1004, 0x10101013, 0x10141011, 0x10741071, 0x104c1075,
    0x10411040, 0x10451044, 0x1050105d, 0x10571051, 0x11f411fd, 0x11df11c0, 0x11d711d1, 0x113f11d4,
    0x11371130, 0x110c1135, 0x11001103, 0x11071101, 0x111f1105, 0x11171110, 0x117d117f, 0x11751170,
    0x11411143, 0x11441147, 0x1153115f, 0x11551151, 0x17c417c1, 0x173c17d0, 0x1700170d, 0x171c1705,
    0x17701714, 0x1747174c, 0x14fc1751, 0x14cf14f3, 0x14dc14c0, 0x14d114d3, 0x143f14d4, 0x1430143c,
    0x14371431, 0x1403140c, 0x14011400, 0x141f1404, 0x14151410, 0x1473147d, 0x14401475, 0x1453145c,
    0x14541450, 0x15c115cc, 0x153c15c7, 0x15341533, 0x1500150f, 0x15051507, 0x15101513, 0x15711514,
    0x15471543, 0x15511545, 0x7ffd7fff, 0x7ff57ff7, 0x7fdd7fdf, 0x7fd57fd7, 0x7f0f7f30, 0x7f037f0c,
    0x7f047f01, 0x7f7f7f10, 0x7f777f7d, 0x7f407f75, 0x7f5d7f5f, 0x7f557f57, 0x7ccc7cf0, 0x7cc17cc3,
    0x7cd07cc4, 0x7c337c3c, 0x7c0f7c34, 0x7c007c0d, 0x7c077c01, 0x7c137c04, 0x7c147c11, 0x7c747c70,
    0x7c417c43, 0x7c507c44, 0x7dfd7dff, 0x7df57df7, 0x7ddf7dc0, 0x7dd77ddd, 0x7d0c7dd5, 0x7d047d03,
    0x7d7f7d10, 0x7d777d7d, 0x7d407d75, 0x7d5d7d5f, 0x7d557d57, 0x73c473c3, 0x7333733c, 0x7300730c,
    0x731c7305, 0x73147313, 0x73447343, 0x70f470fc, 0x70c070cd, 0x70d170c5, 0x703f70d4, 0x7030703c,
    0x700c7037, 0x70007003, 0x70047001, 0x70107005, 0x70177011, 0x707c7015, 0x70717073, 0x704f7074,
    0x7040704d, 0x70517047, 0x71c171cc, 0x71d071c4, 0x7133713c, 0x71357134, 0x7100710f, 0x71057104,
    0x7111711c, 0x71707115, 0x7145714c, 0x77ff7153, 0x77f777fd, 0x77c077f5, 0x77dd77df, 0x77d577d7,
    0x7730773c, 0x7703770c, 0x77107704, 0x777f7714, 0x7777777d, 0x77407775, 0x775d775f, 0x77557757,
    0x74f174f0, 0x74c374cc, 0x74d074c1, 0x7433743c, 0x74347431, 0x740d740f, 0x74057400, 0x7413741c,
    0x74417470, 0x74507444, 0x75fd75ff, 0x75f575f7, 0x75df75c0, 0x75d775dd, 0x753075d5, 0x7503750c,
    0x757f7501, 0x7577757d, 0x75407575, 0x755d755f, 0x75557557, 0x4fcc4ff0, 0x4fc74fc1, 0x4fd04fc4,
    0x4f314f3c, 0x4f004f34, 0x4f054f07, 0x4f154f14, 0x4f4c4f70, 0x4f414f43, 0x4f504f44, 0x4cf34cfc,
    0x4cf44cf1, 0x4cc04ccf, 0x4cc54cc7, 0x4cd34cdc, 0x4cd44cd1, 0x4c304c3f, 0x4c0c4c0f, 0x4c004c03,
    0x4c044c01, 0x4c104c1d, 0x4c714c73, 0x4c404c4d, 0x4c5c4c47, 0x4c514c53, 0x4df04c54, 0x4dc34dcc,
    0x4dd04dc4, 0x4d314d33, 0x4d0f4d34, 0x4d004d0d, 0x4d114d07, 0x4d704d14, 0x4d414d43, 0x43fc4d54,
    0x43f143f3, 0x43c043cf, 0x43d143c7, 0x4335433f, 0x4303430c, 0x43014300, 0x43044307, 0x431c431f,
    0x4310431d, 0x43714373, 0x4343434d, 0x43474340, 0x4354435c, 0x40f040ff, 0x40f540f7, 0x40cc40cf,
    0x40c040c3, 0x40c440c1, 0x40d040dc, 0x40d540d4, 0x4033403c, 0x40314030, 0x400f4034, 0x400d400c,
    0x40004003, 0x40074001, 0x40054004, 0x4013401c, 0x40114010, 0x407c4014, 0x40774070, 0x404d404c,
    0x40404043, 0x40444041, 0x405f4045, 0x4050405d, 0x40554057, 0x41f341fc, 0x41c041cf, 0x41df41c4,
    0x41d441d1, 0x41374130, 0x410c4134, 0x4100410d, 0x41044101, 0x41174110, 0x4173417d, 0x41754174,
    0x4143414d, 0x41534140, 0x41544151, 0x47c147f0, 0x47d047c4, 0x4731473c, 0x470d470f, 0x47014700,
    0x47134705, 0x47704710, 0x4741474c, 0x47504744, 0x44f144f3, 0x44cf44f4, 0x44c044cd, 0x44c544c7,
    0x44dc44df, 0x44d144d3, 0x443d443f, 0x44374430, 0x440c4435, 0x44004403, 0x44044401, 0x4410441d,
    0x44154411, 0x4473447c, 0x444d444f, 0x44454440, 0x4451445c, 0x45c045f0, 0x453345d0, 0x45344531,
    0x4500450f, 0x451c4507, 0x454c4570, 0x45404543, 0x5fff4541, 0x5ff75ffd, 0x5fc05ff5, 0x5fdd5fdf,
    0x5fd55fd7, 0x5f0c5f30, 0x5f015f03, 0x5f7f5f04, 0x5f775f7d, 0x5f405f75, 0x5f5d5f5f, 0x5f555f57,
    0x5cf45cf0, 0x5cc35ccc, 0x5cc45cc1, 0x5c315cc5, 0x5c0c5c34, 0x5c075c00, 0x5c1c5c05, 0x5c705c13,
    0x5c4d5c4f, 0x5c445c41, 0x5df75dfd, 0x5dcf5df5, 0x5ddd5dc4, 0x5dd55dd7, 0x5d0c5d30, 0x5d045d01,
    0x5d7f5d10, 0x5d775d7d, 0x5d405d75, 0x5d5d5d5f, 0x5d555d57, 0x53d053c4, 0x5333533c, 0x5303530f,
    0x53075300, 0x531c5305, 0x53115310, 0x53145317, 0x50f15370, 0x50cf50f4, 0x50c050cd, 0x50d150c7,
    0x503d50d4, 0x500c5030, 0x50005003, 0x50045001, 0x50155010, 0x5073507c, 0x50715070, 0x504d5074,
    0x50475040, 0x51cc51f0, 0x51c551c1, 0x51d051dc, 0x51315133, 0x510d5135, 0x51015100, 0x511f5107,
    0x5171511d, 0x5140514f, 0x51445141, 0x5153515c, 0x57ff5151, 0x57f757fd, 0x57df57f5, 0x57d757dd,
    0x570c57d5, 0x57015703, 0x577f5704, 0x5777577d, 0x57405775, 0x575d575f, 0x57555757, 0x54c354f0,
    0x54dc54c4, 0x543c54d0, 0x5400540f, 0x541c5405, 0x54145411, 0x5441544f, 0x55fd55ff, 0x55f555f7,
    0x55dd55df, 0x55d555d7, 0x5503550c, 0x557f5501, 0x5577557d, 0x55405575, 0x555d555f, 0x55555557
);

struct iq1_m {
    qs: array<u32, 8>,
    qh: array<u32, 4>,
    scales: array<u32, 2>
};

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block = src[src_base + offset];

    let scale = ((block.scales[0] >> 12) & 0xF) | ((block.scales[0] >> 24) & 0x00F0) | ((block.scales[1] >> 4) & 0x0F00) | ((block.scales[1] >> 16) & 0xF000);
    let d = f32(bitcast<vec2<f16>>(scale).x);
    var dst_i = dst_base + offset * 256;
    for (var ib: u32 = 0; ib < 8; ib++) {
        let sw = (block.scales[ib / 4] >> (16 * ((ib / 2) % 2))) & 0xFFFF;
        let s1 : u32 = (sw >> (6 * (ib % 2))) & 0x7;
        let s2 : u32 = (sw >> (6 * (ib % 2) + 3)) & 0x7;
        var dl = array<f32, 2>(
            d * f32(2 * s1 + 1),
            d * f32(2 * s2 + 1)
        );

        let qh = block.qh[ib / 2] >> (16 * (ib % 2));
        var idx = array<u32, 4>(
            get_byte(block.qs[ib], 0) | ((qh << 8) & 0x700),
            get_byte(block.qs[ib], 1) | ((qh << 4) & 0x700),
            get_byte(block.qs[ib], 2) | ((qh) & 0x700),
            get_byte(block.qs[ib], 3) | ((qh >> 4) & 0x700)
        );
        var delta = array<f32, 4>(
            select(IQ1_DELTA, -IQ1_DELTA, (qh & 0x08) != 0),
            select(IQ1_DELTA, -IQ1_DELTA, (qh & 0x80) != 0),
            select(IQ1_DELTA, -IQ1_DELTA, ((qh >> 8) & 0x08) != 0),
            select(IQ1_DELTA, -IQ1_DELTA, ((qh >> 8) & 0x80) != 0)
        );
        for (var l: u32 = 0; l < 4; l++) {
            let ig = idx[l] * 8;
            for (var j: u32 = 0; j < 8; j++) {
                let gw = iq1_grid[(ig + j) / 16];
                let g = (gw >> (((ig + j) % 16) * 2)) & 3;
                let gs = bitcast<i32>(g << 30) >> 30;
                dst[dst_i] = dl[l/2] * (f32(gs) + delta[l]);
                dst_i++;
            }
        }
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<iq1_m>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/256; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_iq4_nl = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

const kvalues_iq4nl = array<i32, 16>(
    -127, -104, -83, -65, -49, -35, -22, -10, 1, 13, 25, 38, 53, 69, 89, 113
);

struct iq4_nl {
    d: f16,
    qs: array<f16, 8>,
};

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block = src[src_base + offset];
    let d = f32(block.d);
    var dst_i = dst_base + offset * 32;
    var qs: array<u32, 4>;
    for (var i: u32 = 0; i < 4; i++) {
        qs[i] = bitcast<u32>(vec2(block.qs[i * 2], block.qs[i * 2 + 1]));
    }
    for (var j: u32 = 0; j < 16; j++) {
        let qsb = get_byte(qs[j / 4], j % 4);
        dst[dst_i] = d * f32(kvalues_iq4nl[qsb & 0xF]);
        dst[dst_i + 16] = d * f32(kvalues_iq4nl[qsb >> 4]);
        dst_i++;
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<iq4_nl>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/32; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_get_rows_iq4_xs = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

const kvalues_iq4nl = array<i32, 16>(
    -127, -104, -83, -65, -49, -35, -22, -10, 1, 13, 25, 38, 53, 69, 89, 113
);

struct iq4_xs {
    d: f16,
    scales_h: f16,
    scales_l: u32,
    qs: array<u32, 32>
};

fn copy_elements(src_base: u32, dst_base: u32, offset: u32) {
    let block = src[src_base + offset];
    let d = f32(block.d);
    let scales_h = bitcast<u32>(vec2(block.scales_h, 0.0));
    var dst_i = dst_base + offset * 256;
    for (var ib: u32 = 0; ib < 8; ib++) {
        let ls = ((get_byte(block.scales_l, ib / 2) >> (4 * (ib % 2))) & 0xF) | (((scales_h >> (2 * ib)) & 3) << 4);
        let dl = d * (f32(ls) - 32.0);
        for (var j: u32 = 0; j < 16; j++) {
            let iqs = ib * 16 + j;
            let qsb = get_byte(block.qs[iqs / 4], iqs % 4);
            dst[dst_i] = dl * f32(kvalues_iq4nl[qsb & 0xF]);
            dst[dst_i + 16] = dl * f32(kvalues_iq4nl[qsb >> 4]);
            dst_i++;
        }
        dst_i += 16;
    }
}



@group(0) @binding(0)
var<storage, read_write> src: array<iq4_xs>;

@group(0) @binding(1)
var<storage, read_write> idx: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of dst
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(3)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.n_rows * params.ne2 * params.ne3) {
        return;
    }
    var i = gid.x;
    let i_dst3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_dst2 = i / params.n_rows;
    let i_dst1 = i % params.n_rows;

    let i_idx2 = i_dst3 % params.idx2;
    let i_idx1 = i_dst2 % params.idx1;
    let i_idx0 = i_dst1;

    let i_idx = params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2;

    let idx_val = u32(idx[i_idx]);

    let i_src_row = params.offset_src + idx_val * params.stride_src1 + i_dst2 * params.stride_src2 + i_dst3 * params.stride_src3;
    let i_dst_row = params.offset_dst + i_dst1 * params.stride_dst1 + i_dst2 * params.stride_dst2 + i_dst3 * params.stride_dst3;

    for (var i: u32 = 0; i < params.ne0/256; i++) {
      copy_elements(i_src_row, i_dst_row, i);
    }
})";

const char* wgsl_reglu_f32 = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;

fn a_value(base: u32) -> f32 {
    let offset: u32 = select(0, params.ne0, params.swapped != 0);
    return src0[base + offset];
}

fn b_value(base: u32) -> f32 {
    let offset: u32 = select(params.ne0, 0, params.swapped != 0);
    return src0[base + offset];
}

fn op(a: f32, b: f32) -> f32 {
    return max(a, 0) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_reglu_f32_split = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(3)
var<uniform> params: Params;

fn a_value(base: u32) -> f32 {
    return src0[base];
}

fn b_value(base: u32) -> f32 {
    return src1[base];
}

fn op(a: f32, b: f32) -> f32 {
    return max(a, 0) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_reglu_f16 = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;

fn a_value(base: u32) -> f16 {
    let offset: u32 = select(0, params.ne0, params.swapped != 0);
    return src0[base + offset];
}

fn b_value(base: u32) -> f16 {
    let offset: u32 = select(params.ne0, 0, params.swapped != 0);
    return src0[base + offset];
}

fn op(a: f16, b: f16) -> f16 {
    return max(a, 0) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_reglu_f16_split = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f16>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(3)
var<uniform> params: Params;

fn a_value(base: u32) -> f16 {
    return src0[base];
}

fn b_value(base: u32) -> f16 {
    return src1[base];
}

fn op(a: f16, b: f16) -> f16 {
    return max(a, 0) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_geglu_f32 = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;

fn a_value(base: u32) -> f32 {
    let offset: u32 = select(0, params.ne0, params.swapped != 0);
    return src0[base + offset];
}

fn b_value(base: u32) -> f32 {
    let offset: u32 = select(params.ne0, 0, params.swapped != 0);
    return src0[base + offset];
}

const SQRT_2_OVER_PI: f32 = 0.79788456080286535587989211986876;
const GELU_COEF_A: f32 = 0.044715;

fn op(a: f32, b: f32) -> f32 {
    let val = SQRT_2_OVER_PI * a * (1.0 + GELU_COEF_A * a * a);
    return 0.5 * a * (2.0 - 2.0 / (exp(2 * val) + 1)) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_geglu_f32_split = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(3)
var<uniform> params: Params;

fn a_value(base: u32) -> f32 {
    return src0[base];
}

fn b_value(base: u32) -> f32 {
    return src1[base];
}

const SQRT_2_OVER_PI: f32 = 0.79788456080286535587989211986876;
const GELU_COEF_A: f32 = 0.044715;

fn op(a: f32, b: f32) -> f32 {
    let val = SQRT_2_OVER_PI * a * (1.0 + GELU_COEF_A * a * a);
    return 0.5 * a * (2.0 - 2.0 / (exp(2 * val) + 1)) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_geglu_f16 = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;

fn a_value(base: u32) -> f16 {
    let offset: u32 = select(0, params.ne0, params.swapped != 0);
    return src0[base + offset];
}

fn b_value(base: u32) -> f16 {
    let offset: u32 = select(params.ne0, 0, params.swapped != 0);
    return src0[base + offset];
}

const SQRT_2_OVER_PI: f16 = 0.79788456080286535587989211986876;
const GELU_COEF_A: f16 = 0.044715;

fn op(a: f16, b: f16) -> f16 {
    let val = SQRT_2_OVER_PI * a * (1.0 + GELU_COEF_A * a * a);
    return 0.5 * a * (2.0 - 2.0 / (exp(2 * val) + 1)) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_geglu_f16_split = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f16>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(3)
var<uniform> params: Params;

fn a_value(base: u32) -> f16 {
    return src0[base];
}

fn b_value(base: u32) -> f16 {
    return src1[base];
}

const SQRT_2_OVER_PI: f16 = 0.79788456080286535587989211986876;
const GELU_COEF_A: f16 = 0.044715;

fn op(a: f16, b: f16) -> f16 {
    let val = SQRT_2_OVER_PI * a * (1.0 + GELU_COEF_A * a * a);
    return 0.5 * a * (2.0 - 2.0 / (exp(2 * val) + 1)) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_swiglu_f32 = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;

fn a_value(base: u32) -> f32 {
    let offset: u32 = select(0, params.ne0, params.swapped != 0);
    return src0[base + offset];
}

fn b_value(base: u32) -> f32 {
    let offset: u32 = select(params.ne0, 0, params.swapped != 0);
    return src0[base + offset];
}

fn op(a: f32, b: f32) -> f32 {
    return a / (1.0 + exp(-a)) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_swiglu_f32_split = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(3)
var<uniform> params: Params;

fn a_value(base: u32) -> f32 {
    return src0[base];
}

fn b_value(base: u32) -> f32 {
    return src1[base];
}

fn op(a: f32, b: f32) -> f32 {
    return a / (1.0 + exp(-a)) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_swiglu_f16 = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;

fn a_value(base: u32) -> f16 {
    let offset: u32 = select(0, params.ne0, params.swapped != 0);
    return src0[base + offset];
}

fn b_value(base: u32) -> f16 {
    let offset: u32 = select(params.ne0, 0, params.swapped != 0);
    return src0[base + offset];
}

fn op(a: f16, b: f16) -> f16 {
    return a / (1.0 + exp(-a)) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_swiglu_f16_split = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f16>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(3)
var<uniform> params: Params;

fn a_value(base: u32) -> f16 {
    return src0[base];
}

fn b_value(base: u32) -> f16 {
    return src1[base];
}

fn op(a: f16, b: f16) -> f16 {
    return a / (1.0 + exp(-a)) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_swiglu_oai_f32 = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;

fn a_value(base: u32) -> f32 {
    let offset: u32 = select(0, params.ne0, params.swapped != 0);
    return src0[base + offset];
}

fn b_value(base: u32) -> f32 {
    let offset: u32 = select(params.ne0, 0, params.swapped != 0);
    return src0[base + offset];
}

fn op(a: f32, b: f32) -> f32 {
  let xi = min(a, params.limit);
  let gi = max(min(b, params.limit), -params.limit);
  var out_glu = xi / (1.0 + exp(-xi * params.alpha));
  out_glu = out_glu * (1.0 + gi);
  return out_glu;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_swiglu_oai_f32_split = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(3)
var<uniform> params: Params;

fn a_value(base: u32) -> f32 {
    return src0[base];
}

fn b_value(base: u32) -> f32 {
    return src1[base];
}

fn op(a: f32, b: f32) -> f32 {
  let xi = min(a, params.limit);
  let gi = max(min(b, params.limit), -params.limit);
  var out_glu = xi / (1.0 + exp(-xi * params.alpha));
  out_glu = out_glu * (1.0 + gi);
  return out_glu;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_geglu_erf_f32 = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;

fn a_value(base: u32) -> f32 {
    let offset: u32 = select(0, params.ne0, params.swapped != 0);
    return src0[base + offset];
}

fn b_value(base: u32) -> f32 {
    let offset: u32 = select(params.ne0, 0, params.swapped != 0);
    return src0[base + offset];
}

const p_erf: f32 = 0.3275911;
const a1_erf: f32 = 0.254829592;
const a2_erf: f32 = -0.284496736;
const a3_erf: f32 = 1.421413741;
const a4_erf: f32 = -1.453152027;
const a5_erf: f32 = 1.061405429;
const SQRT_2_INV: f32 = 0.7071067811865476;

fn op(a: f32, b: f32) -> f32 {
  let a_div_sqr2 = a * SQRT_2_INV;
  let sign_x = sign(a_div_sqr2);
  let x = abs(a_div_sqr2);
  let t = 1.0 / (1.0 + p_erf * x);
  let y = 1.0 - (((((a5_erf * t + a4_erf) * t + a3_erf) * t + a2_erf) * t + a1_erf) * t * exp(-x * x));
  let erf_approx = sign_x * y;
  return 0.5 * a * (1.0 + erf_approx) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_geglu_erf_f32_split = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(3)
var<uniform> params: Params;

fn a_value(base: u32) -> f32 {
    return src0[base];
}

fn b_value(base: u32) -> f32 {
    return src1[base];
}

const p_erf: f32 = 0.3275911;
const a1_erf: f32 = 0.254829592;
const a2_erf: f32 = -0.284496736;
const a3_erf: f32 = 1.421413741;
const a4_erf: f32 = -1.453152027;
const a5_erf: f32 = 1.061405429;
const SQRT_2_INV: f32 = 0.7071067811865476;

fn op(a: f32, b: f32) -> f32 {
  let a_div_sqr2 = a * SQRT_2_INV;
  let sign_x = sign(a_div_sqr2);
  let x = abs(a_div_sqr2);
  let t = 1.0 / (1.0 + p_erf * x);
  let y = 1.0 - (((((a5_erf * t + a4_erf) * t + a3_erf) * t + a2_erf) * t + a1_erf) * t * exp(-x * x));
  let erf_approx = sign_x * y;
  return 0.5 * a * (1.0 + erf_approx) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_geglu_erf_f16 = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;

fn a_value(base: u32) -> f16 {
    let offset: u32 = select(0, params.ne0, params.swapped != 0);
    return src0[base + offset];
}

fn b_value(base: u32) -> f16 {
    let offset: u32 = select(params.ne0, 0, params.swapped != 0);
    return src0[base + offset];
}

const p_erf: f16 = 0.3275911;
const a1_erf: f16 = 0.254829592;
const a2_erf: f16 = -0.284496736;
const a3_erf: f16 = 1.421413741;
const a4_erf: f16 = -1.453152027;
const a5_erf: f16 = 1.061405429;
const SQRT_2_INV: f16 = 0.7071067811865476;

fn op(a: f16, b: f16) -> f16 {
  let a_div_sqr2 = a * SQRT_2_INV;
  let sign_x = sign(a_div_sqr2);
  let x = abs(a_div_sqr2);
  let t = 1.0 / (1.0 + p_erf * x);
  let y = 1.0 - (((((a5_erf * t + a4_erf) * t + a3_erf) * t + a2_erf) * t + a1_erf) * t * exp(-x * x));
  let erf_approx = sign_x * y;
  return 0.5 * a * (1.0 + erf_approx) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_geglu_erf_f16_split = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f16>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(3)
var<uniform> params: Params;

fn a_value(base: u32) -> f16 {
    return src0[base];
}

fn b_value(base: u32) -> f16 {
    return src1[base];
}

const p_erf: f16 = 0.3275911;
const a1_erf: f16 = 0.254829592;
const a2_erf: f16 = -0.284496736;
const a3_erf: f16 = 1.421413741;
const a4_erf: f16 = -1.453152027;
const a5_erf: f16 = 1.061405429;
const SQRT_2_INV: f16 = 0.7071067811865476;

fn op(a: f16, b: f16) -> f16 {
  let a_div_sqr2 = a * SQRT_2_INV;
  let sign_x = sign(a_div_sqr2);
  let x = abs(a_div_sqr2);
  let t = 1.0 / (1.0 + p_erf * x);
  let y = 1.0 - (((((a5_erf * t + a4_erf) * t + a3_erf) * t + a2_erf) * t + a1_erf) * t * exp(-x * x));
  let erf_approx = sign_x * y;
  return 0.5 * a * (1.0 + erf_approx) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_geglu_quick_f32 = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;

fn a_value(base: u32) -> f32 {
    let offset: u32 = select(0, params.ne0, params.swapped != 0);
    return src0[base + offset];
}

fn b_value(base: u32) -> f32 {
    let offset: u32 = select(params.ne0, 0, params.swapped != 0);
    return src0[base + offset];
}

const GELU_QUICK_COEF: f32 = -1.702;

fn op(a: f32, b: f32) -> f32 {
    return a * (1.0 / (1.0 + exp(GELU_QUICK_COEF * a))) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_geglu_quick_f32_split = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(3)
var<uniform> params: Params;

fn a_value(base: u32) -> f32 {
    return src0[base];
}

fn b_value(base: u32) -> f32 {
    return src1[base];
}

const GELU_QUICK_COEF: f32 = -1.702;

fn op(a: f32, b: f32) -> f32 {
    return a * (1.0 / (1.0 + exp(GELU_QUICK_COEF * a))) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_geglu_quick_f16 = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;

fn a_value(base: u32) -> f16 {
    let offset: u32 = select(0, params.ne0, params.swapped != 0);
    return src0[base + offset];
}

fn b_value(base: u32) -> f16 {
    let offset: u32 = select(params.ne0, 0, params.swapped != 0);
    return src0[base + offset];
}

const GELU_QUICK_COEF: f16 = -1.702;

fn op(a: f16, b: f16) -> f16 {
    return a * (1.0 / (1.0 + exp(GELU_QUICK_COEF * a))) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_geglu_quick_f16_split = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    swapped: u32,
    alpha: f32,
    limit: f32,
}

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> src1: array<f16>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(3)
var<uniform> params: Params;

fn a_value(base: u32) -> f16 {
    return src0[base];
}

fn b_value(base: u32) -> f16 {
    return src1[base];
}

const GELU_QUICK_COEF: f16 = -1.702;

fn op(a: f16, b: f16) -> f16 {
    return a * (1.0 / (1.0 + exp(GELU_QUICK_COEF * a))) * b;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_a = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01 + i0;
    let i_b = params.offset_src1 + i3 * params.stride_src13 + i2 * params.stride_src12 + i1 * params.stride_src11 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    dst[i_dst] = op(a_value(i_a), b_value(i_b));
})";

const char* wgsl_memset = R"(@group(0) @binding(0)
var<storage, read_write> output_buffer: array<u32>;

struct Params {
    offset: u32, // in bytes
    size: u32,   // in bytes
    value: u32,  // 4 8-bit values, which are either repeating (memset_tensor) or may be separate (cleaning up unaligned set_tensor operations)
};

@group(0) @binding(1)
var<uniform> params: Params;

override wg_size: u32;
override bytes_per_thread: u32;

@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    let i = gid.x * bytes_per_thread;
    let start = params.offset;
    let end = params.offset + params.size;

    for (var j: u32 = 0u; j < bytes_per_thread; j += 4) {
        let byte_index = start + i + j;
        if (byte_index + 4 <= end) {
            output_buffer[byte_index >> 2] = params.value;
        } else {
            // Handle tail (unaligned)
            for (var k: u32 = 0; k < 4; k++) {
                let idx = byte_index + k;
                if (idx < end) {
                    let word_idx = idx >> 2;
                    let bit_offset = (idx & 3) * 8u;
                    let mask = ~(0xffu << bit_offset);
                    let existing = output_buffer[word_idx];
                    output_buffer[word_idx] = (existing & mask) | (params.value & (0xffu << bit_offset));
                }
            }
        }
    }
}
)";

const char* wgsl_mul_mat_f32_f32 = R"(enable f16;

fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    return f32(src0[src0_idx_base + offset]) * f32(src1[src1_idx_base + offset]);
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<f32>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/1; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_f16_f16 = R"(enable f16;

fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    return f32(src0[src0_idx_base + offset]) * f32(src1[src1_idx_base + offset]);
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<f16>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f16>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/1; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_f16_f32 = R"(enable f16;

fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    return f32(src0[src0_idx_base + offset]) * f32(src1[src1_idx_base + offset]);
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<f16>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/1; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_q4_0_f32 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q4_0 {
    d: f16,
    qs: array<f16, 8>
};

fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block_q4_0 = src0[src0_idx_base + offset];
    let d = f32(block_q4_0.d);
    var sum: f32 = 0.0;
    for (var j: u32 = 0; j < 4; j++) {
        let q_packed = bitcast<u32>(vec2(block_q4_0.qs[2 * j], block_q4_0.qs[2 * j + 1]));
        for (var k: u32 = 0; k < 4; k++) {
            let q_byte = get_byte(q_packed, k);
            let q_hi = (f32((q_byte >> 4) & 0xF) - 8.0f) * d;
            let q_lo = (f32(q_byte & 0xF) - 8.0f) * d;
            let src1_offset = src1_idx_base + offset * 32 + j * 4 + k;
            sum += q_lo * f32(src1[src1_offset]);
            sum += q_hi * f32(src1[src1_offset + 16]);
        }
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<q4_0>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/32; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_q4_1_f32 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q4_1 {
    d: f16,
    m: f16,
    qs: array<u32, 4>
};

fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block_q4_1 = src0[src0_idx_base + offset];
    let d = f32(block_q4_1.d);
    let m = f32(block_q4_1.m);
    var sum: f32 = 0.0;
    for (var j: u32 = 0; j < 4; j++) {
        let q_packed = block_q4_1.qs[j];
        for (var k: u32 = 0; k < 4; k++) {
            let q_byte = get_byte(q_packed, k);
            let q_hi = f32((q_byte >> 4) & 0xF) * d + m;
            let q_lo = f32(q_byte & 0xF) * d + m;
            let src1_offset = src1_idx_base + offset * 32 + j * 4 + k;
            sum += q_lo * f32(src1[src1_offset]);
            sum += q_hi * f32(src1[src1_offset + 16]);
        }
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<q4_1>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/32; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_q5_0_f32 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q5_0 {
    d: f16,
    qh: array<f16, 2>,
    qs: array<f16, 8>
};

fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block_q5_0 = src0[src0_idx_base + offset];
    let d = f32(block_q5_0.d);
    var sum: f32 = 0.0;
    let qh_packed = bitcast<u32>(vec2(block_q5_0.qh[0], block_q5_0.qh[1]));
    for (var j: u32 = 0; j < 4; j++) {
        let q_packed = bitcast<u32>(vec2(block_q5_0.qs[2 * j], block_q5_0.qs[2 * j + 1]));
        for (var k: u32 = 0; k < 4; k++) {
            let q_byte = get_byte(q_packed, k);
            let qh_hi = (qh_packed >> (j * 4 + k + 12)) & 0x10;
            let q_hi = (f32(((q_byte >> 4) & 0xF) | qh_hi) - 16.0) * d;
            let qh_lo = ((qh_packed >> (j * 4 + k)) << 4) & 0x10;
            let q_lo = (f32((q_byte & 0xF) | qh_lo) - 16.0) * d;
            let src1_offset = src1_idx_base + offset * 32 + j * 4 + k;
            sum += q_lo * f32(src1[src1_offset]);
            sum += q_hi * f32(src1[src1_offset + 16]);
        }
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<q5_0>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/32; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_q5_1_f32 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q5_1 {
    d: f16,
    m: f16,
    qh: u32,
    qs: array<u32, 4>
};

fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block_q5_1 = src0[src0_idx_base + offset];
    let d = f32(block_q5_1.d);
    let m = f32(block_q5_1.m);
    var sum: f32 = 0.0;
    for (var j: u32 = 0; j < 4; j++) {
        let q_packed = block_q5_1.qs[j];
        for (var k: u32 = 0; k < 4; k++) {
            let q_byte = get_byte(q_packed, k);
            let qh_hi = (block_q5_1.qh >> (j * 4 + k + 12)) & 0x10;
            let q_hi = f32(((q_byte >> 4) & 0xF) | qh_hi) * d + m;
            let qh_lo = ((block_q5_1.qh >> (j * 4 + k)) << 4) & 0x10;
            let q_lo = f32((q_byte & 0xF) | qh_lo) * d + m;
            let src1_offset = src1_idx_base + offset * 32 + j * 4 + k;
            sum += q_lo * f32(src1[src1_offset]);
            sum += q_hi * f32(src1[src1_offset + 16]);
        }
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<q5_1>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/32; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_q8_0_f32 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q8_0 {
    d: f16,
    qs: array<f16, 16>
};

fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block_q8_0 = src0[src0_idx_base + offset];
    let d = f32(block_q8_0.d);
    var sum: f32 = 0.0;
    for (var j: u32 = 0; j < 8; j++) {
        let q_packed = bitcast<u32>(vec2(block_q8_0.qs[2 * j], block_q8_0.qs[2 * j + 1]));
        for (var k: u32 = 0; k < 4; k++) {
            let q_byte = get_byte_i32(q_packed, k);
            let q_val = f32(q_byte) * d;
            let src1_offset = src1_idx_base + offset * 32 + j * 4 + k;
            sum += q_val * f32(src1[src1_offset]);
        }
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<q8_0>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/32; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_q2_k_f32 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q2_k {
    scales: array<u32, 4>,
    qs: array<u32, 16>,
    d: f16,
    dmin: f16
};

// 16 blocks of 16 elements each
fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block = src0[src0_idx_base + offset];
    let d = f32(block.d);
    let m = f32(block.dmin);
    var sum = 0.0;
    var src1_i = src1_idx_base + offset * 256;
    var is: u32 = 0;
    // 2 halves of the block (128 elements each)
    for (var q_b_idx: u32 = 0; q_b_idx < 64; q_b_idx += 32) {
        // 4 groups (each group has 2 blocks of 16 elements)
        for (var shift: u32 = 0; shift < 8; shift += 2) {
            // 2 blocks
            for (var k: u32 = 0; k < 32; k += 16) {
                let sc = get_byte(block.scales[is / 4], is % 4);
                is++;
                let dl = d * f32(sc & 0xF);
                let ml = m * f32(sc >> 4);
                for (var l: u32 = 0u; l < 16; l++) {
                    let q_idx = q_b_idx + k + l;
                    let q_byte = get_byte(block.qs[q_idx / 4], q_idx % 4);
                    let qs_val = (q_byte >> shift) & 3;
                    sum += (f32(qs_val) * dl - ml) * src1[src1_i];
                    src1_i++;
                }
            }
        }
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<q2_k>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/256; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_q3_k_f32 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q3_k {
    hmask: array<f16, 16>,
    qs: array<f16, 32>,
    scales: array<f16, 6>,
    d: f16
};

// 16 blocks of 16 elements each
fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block = src0[src0_idx_base + offset];
    let d = f32(block.d);

    // extract 6-bit scales, which consist of 4-bits from first 8 bytes of scale,
    // and 2-bits from the last 4 bytes
    let kmask1: u32 = 0x03030303;
    let kmask2: u32 = 0x0f0f0f0f;
    var scale_vals: array<u32, 4>;
    for (var i: u32 = 0; i < 4; i++) {
        scale_vals[i] = bitcast<u32>(vec2(block.scales[2 * i], block.scales[2 * i + 1]));
    }
    var tmp: u32 = scale_vals[2];
    scale_vals[2] = ((scale_vals[0] >> 4) & kmask2) | (((tmp >> 4) & kmask1) << 4);
    scale_vals[3] = ((scale_vals[1] >> 4) & kmask2) | (((tmp >> 6) & kmask1) << 4);
    scale_vals[0] = (scale_vals[0] & kmask2) | ((tmp & kmask1) << 4);
    scale_vals[1] = (scale_vals[1] & kmask2) | (((tmp >> 2) & kmask1) << 4);

    // convert arrays of f16 -> u32
    var hmask_vals: array<u32, 8>;
    for (var i: u32 = 0; i < 8; i++) {
        hmask_vals[i] = bitcast<u32>(vec2(block.hmask[2 * i], block.hmask[2 * i + 1]));
    }
    var qs_vals: array<u32, 16>;
    for (var i: u32 = 0; i < 16; i++) {
        qs_vals[i] = bitcast<u32>(vec2(block.qs[2 * i], block.qs[2 * i + 1]));
    }

    var sum = 0.0;
    var src1_i = src1_idx_base + offset * 256;
    var is: u32 = 0;
    var m: u32 = 1;
    // 2 halves of the block (128 elements each)
    for (var q_b_idx: u32 = 0; q_b_idx < 64; q_b_idx += 32) {
        // 4 groups (each group has 2 blocks of 16 elements)
        for (var shift: u32 = 0; shift < 8; shift += 2) {
            // 2 blocks
            for (var k: u32 = 0; k < 32; k += 16) {
                let sc = get_byte(scale_vals[is / 4], is % 4);
                is++;
                let dl = d * (f32(sc) - 32.0);
                for (var l: u32 = 0u; l < 16u; l++) {
                    let q_idx = q_b_idx + k + l;
                    let hm_idx = k + l;
                    let q_byte = get_byte(qs_vals[q_idx / 4], q_idx % 4);
                    let hmask_byte = get_byte(hmask_vals[hm_idx / 4], hm_idx % 4);
                    let hm = select(4.0, 0.0, (hmask_byte & m) != 0);
                    let qs_val = (q_byte >> shift) & 3;
                    sum += ((f32(qs_val) - hm) * dl) * src1[src1_i];
                    src1_i++;
                }
            }
            m <<= 1;
        }
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<q3_k>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/256; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_q4_k_f32 = R"(enable f16;

fn get_scale_min(is: u32, scales: array<u32, 3>) -> vec2<f32> {
    if (is < 4) {
        let sc_byte = get_byte(scales[is / 4], is % 4);
        let min_byte = get_byte(scales[(is + 4) / 4], is % 4);
        return vec2(f32(sc_byte & 63), f32(min_byte & 63));
    } else {
        let sc_min_lo = get_byte(scales[(is + 4) / 4], (is + 4) % 4);
        let sc_hi = get_byte(scales[(is - 4) / 4], (is - 4) % 4);
        let min_hi = get_byte(scales[is / 4], is % 4);
        let sc = (sc_min_lo & 0xF) | ((sc_hi >> 6) << 4);
        let m = (sc_min_lo >> 4) | ((min_hi >> 6) << 4);
        return vec2(f32(sc), f32(m));
    }
}

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q4_k {
    d: f16,
    dmin: f16,
    scales: array<u32, 3>,
    qs: array<u32, 32>
};

// 8 blocks of 32 elements each
fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block = src0[src0_idx_base + offset];
    let d = f32(block.d);
    let m = f32(block.dmin);
    var sum = 0.0;
    var src1_i = src1_idx_base + offset * 256;
    var is: u32 = 0;
    // 2 blocks each iteration
    for (var q_b_idx: u32 = 0; q_b_idx < 128; q_b_idx += 32) {
        for (var shift: u32 = 0; shift < 8; shift += 4) {
            let scale_min = get_scale_min(is, block.scales);
            is++;
            let dl = d * scale_min.x;
            let ml = m * scale_min.y;
            for (var l: u32 = 0; l < 32; l++) {
                let q_idx = q_b_idx + l;
                let q_byte = get_byte(block.qs[q_idx / 4], q_idx % 4);
                let qs_val = (q_byte >> shift) & 0xF;
                sum += (f32(qs_val) * dl - ml) * src1[src1_i];
                src1_i++;
            }
        }
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<q4_k>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/256; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_q5_k_f32 = R"(enable f16;

fn get_scale_min(is: u32, scales: array<u32, 3>) -> vec2<f32> {
    if (is < 4) {
        let sc_byte = get_byte(scales[is / 4], is % 4);
        let min_byte = get_byte(scales[(is + 4) / 4], is % 4);
        return vec2(f32(sc_byte & 63), f32(min_byte & 63));
    } else {
        let sc_min_lo = get_byte(scales[(is + 4) / 4], (is + 4) % 4);
        let sc_hi = get_byte(scales[(is - 4) / 4], (is - 4) % 4);
        let min_hi = get_byte(scales[is / 4], is % 4);
        let sc = (sc_min_lo & 0xF) | ((sc_hi >> 6) << 4);
        let m = (sc_min_lo >> 4) | ((min_hi >> 6) << 4);
        return vec2(f32(sc), f32(m));
    }
}

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q5_k {
    d: f16,
    dmin: f16,
    scales: array<u32, 3>,
    qh: array<u32, 8>,
    qs: array<u32, 32>
};

// 8 blocks of 32 elements each
fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block = src0[src0_idx_base + offset];
    let d = f32(block.d);
    let m = f32(block.dmin);
    var sum = 0.0;
    var src1_i = src1_idx_base + offset * 256;
    var is: u32 = 0;
    var u: u32 = 1;
    // 2 blocks each iteration
    for (var q_b_idx: u32 = 0; q_b_idx < 128; q_b_idx += 32) {
        for (var shift: u32 = 0; shift < 8; shift += 4) {
            let scale_min = get_scale_min(is, block.scales);
            is++;
            let dl = d * scale_min.x;
            let ml = m * scale_min.y;
            for (var l: u32 = 0; l < 32; l++) {
                let q_idx = q_b_idx + l;
                let q_byte = get_byte(block.qs[q_idx / 4], q_idx % 4);
                let qh_byte = get_byte(block.qh[l / 4], l % 4);
                let qs_val = (q_byte >> shift) & 0xF;
                let qh_val = select(0.0, 16.0, (qh_byte & u) != 0);
                sum += ((f32(qs_val) + qh_val) * dl - ml) * src1[src1_i];
               src1_i++;
            }
            u <<= 1;
        }
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<q5_k>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/256; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_q6_k_f32 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

struct q6_k {
    ql: array<f16, 64>,
    qh: array<f16, 32>,
    scales: array<f16, 8>,
    d: f16
};

// 16 blocks of 16 elements each
fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block = src0[src0_idx_base + offset];
    let d = f32(block.d);

    // convert arrays of f16 -> u32
    var ql_vals: array<u32, 32>;
    for (var i: u32 = 0; i < 32; i++) {
        ql_vals[i] = bitcast<u32>(vec2(block.ql[2 * i], block.ql[2 * i + 1]));
    }
    var qh_vals: array<u32, 16>;
    for (var i: u32 = 0; i < 16; i++) {
        qh_vals[i] = bitcast<u32>(vec2(block.qh[2 * i], block.qh[2 * i + 1]));
    }
    var scale_vals: array<u32, 4>;
    for (var i: u32 = 0; i < 4; i++) {
        scale_vals[i] = bitcast<u32>(vec2(block.scales[2 * i], block.scales[2 * i + 1]));
    }

    var sum = 0.0;
    var src1_i = src1_idx_base + offset * 256;
    var qh_b_idx: u32 = 0;
    var sc_b_idx: u32 = 0;
    for (var ql_b_idx: u32 = 0; ql_b_idx < 128; ql_b_idx += 64) {
        for (var l: u32 = 0; l < 32; l++) {
            let ql13_b = get_byte(ql_vals[(ql_b_idx + l) / 4], (ql_b_idx + l) % 4);
            let ql24_b = get_byte(ql_vals[(ql_b_idx + l + 32) / 4], (ql_b_idx + l + 32) % 4);
            let qh_b = get_byte(qh_vals[(qh_b_idx + l) / 4], (qh_b_idx + l) % 4);

            let q1 = f32((ql13_b & 0xF) | ((qh_b & 3) << 4)) - 32.0;
            let q2 = f32((ql24_b & 0xF) | (((qh_b >> 2) & 3) << 4)) - 32.0;
            let q3 = f32((ql13_b >> 4) | (((qh_b >> 4) & 3) << 4)) - 32.0;
            let q4 = f32((ql24_b >> 4) | (((qh_b >> 6) & 3) << 4)) - 32.0;

            let is = l/16;
            let is1 = sc_b_idx + is;
            let sc1 = get_byte_i32(scale_vals[is1 / 4], is1 % 4);
            let is2 = sc_b_idx + is + 2;
            let sc2 = get_byte_i32(scale_vals[is2 / 4], is2 % 4);
            let is3 = sc_b_idx + is + 4;
            let sc3 = get_byte_i32(scale_vals[is3 / 4], is3 % 4);
            let is4 = sc_b_idx + is + 6;
            let sc4 = get_byte_i32(scale_vals[is4 / 4], is4 % 4);

            sum += d * f32(sc1) * q1 * src1[src1_i + l];
            sum += d * f32(sc2) * q2 * src1[src1_i + l + 32];
            sum += d * f32(sc3) * q3 * src1[src1_i + l + 64];
            sum += d * f32(sc4) * q4 * src1[src1_i + l + 96];
        }
        src1_i += 128;
        qh_b_idx += 32;
        sc_b_idx += 8;
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<q6_k>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/256; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_iq2_xxs_f32 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

const kmask_iq2xs : array<u32, 2> = array<u32, 2>(
    0x08040201u, // 1, 2, 4, 8
    0x80402010u  // 16, 32, 64, 128
);

const ksigns_iq2xs: array<u32, 32> = array<u32, 32>(
    0x03828100,0x87060584,0x8b0a0988,0x0f8e8d0c,
    0x93121190,0x17969514,0x1b9a9918,0x9f1e1d9c,
    0xa32221a0,0x27a6a524,0x2baaa928,0xaf2e2dac,
    0x33b2b130,0xb73635b4,0xbb3a39b8,0x3fbebd3c,
    0xc34241c0,0x47c6c544,0x4bcac948,0xcf4e4dcc,
    0x53d2d150,0xd75655d4,0xdb5a59d8,0x5fdedd5c,
    0x63e2e160,0xe76665e4,0xeb6a69e8,0x6feeed6c,
    0xf37271f0,0x77f6f574,0x7bfaf978,0xff7e7dfc
);

const iq2xxs_grid = array<u32, 512>(
    0x08080808, 0x08080808, 0x0808082b, 0x08080808, 0x08081919, 0x08080808, 0x08082b08, 0x08080808,
    0x08082b2b, 0x08080808, 0x08190819, 0x08080808, 0x08191908, 0x08080808, 0x082b0808, 0x08080808,
    0x082b082b, 0x08080808, 0x082b2b08, 0x08080808, 0x082b2b2b, 0x08080808, 0x19080819, 0x08080808,
    0x19081908, 0x08080808, 0x19190808, 0x08080808, 0x19192b08, 0x08080808, 0x192b0819, 0x08080808,
    0x192b1908, 0x08080808, 0x2b080808, 0x08080808, 0x2b08082b, 0x08080808, 0x2b082b2b, 0x08080808,
    0x2b2b082b, 0x08080808, 0x08080819, 0x08080819, 0x08081908, 0x08080819, 0x08190808, 0x08080819,
    0x08191919, 0x08080819, 0x19080808, 0x08080819, 0x2b081908, 0x08080819, 0x2b192b08, 0x08080819,
    0x08080808, 0x0808082b, 0x0808082b, 0x0808082b, 0x082b082b, 0x0808082b, 0x2b08082b, 0x0808082b,
    0x08080819, 0x08081908, 0x08081908, 0x08081908, 0x08190808, 0x08081908, 0x082b0819, 0x08081908,
    0x082b1908, 0x08081908, 0x19080808, 0x08081908, 0x1908082b, 0x08081908, 0x19082b08, 0x08081908,
    0x192b0808, 0x08081908, 0x2b080819, 0x08081908, 0x2b081908, 0x08081908, 0x2b190808, 0x08081908,
    0x2b2b1908, 0x08081908, 0x08080808, 0x08081919, 0x0808082b, 0x08081919, 0x08082b08, 0x08081919,
    0x082b0808, 0x08081919, 0x1908192b, 0x08081919, 0x192b2b19, 0x08081919, 0x2b080808, 0x08081919,
    0x2b190819, 0x08081919, 0x08082b19, 0x0808192b, 0x08190808, 0x0808192b, 0x19080808, 0x0808192b,
    0x2b081908, 0x0808192b, 0x2b2b1908, 0x0808192b, 0x08080808, 0x08082b08, 0x08081919, 0x08082b08,
    0x08082b08, 0x08082b08, 0x08191908, 0x08082b08, 0x082b2b08, 0x08082b08, 0x19080819, 0x08082b08,
    0x19081908, 0x08082b08, 0x19190808, 0x08082b08, 0x1919082b, 0x08082b08, 0x2b082b08, 0x08082b08,
    0x08081908, 0x08082b19, 0x19080808, 0x08082b19, 0x0808082b, 0x08082b2b, 0x08191908, 0x08082b2b,
    0x08080819, 0x08190808, 0x08081908, 0x08190808, 0x08190808, 0x08190808, 0x082b0819, 0x08190808,
    0x19080808, 0x08190808, 0x192b0808, 0x08190808, 0x2b081908, 0x08190808, 0x2b190808, 0x08190808,
    0x2b191919, 0x08190808, 0x08080808, 0x08190819, 0x08082b08, 0x08190819, 0x082b0808, 0x08190819,
    0x19190808, 0x08190819, 0x19192b2b, 0x08190819, 0x2b080808, 0x08190819, 0x082b1908, 0x0819082b,
    0x19081919, 0x0819082b, 0x08080808, 0x08191908, 0x08082b08, 0x08191908, 0x082b0808, 0x08191908,
    0x082b1919, 0x08191908, 0x19082b19, 0x08191908, 0x2b080808, 0x08191908, 0x08192b08, 0x08191919,
    0x192b082b, 0x08191919, 0x08080808, 0x0819192b, 0x0819192b, 0x0819192b, 0x08080819, 0x08192b08,
    0x08081908, 0x08192b08, 0x08190808, 0x08192b08, 0x19080808, 0x08192b08, 0x2b080819, 0x08192b08,
    0x08080808, 0x08192b19, 0x08081919, 0x08192b19, 0x2b2b0808, 0x08192b19, 0x19190819, 0x08192b2b,
    0x08080808, 0x082b0808, 0x0808082b, 0x082b0808, 0x08082b2b, 0x082b0808, 0x19081908, 0x082b0808,
    0x192b0819, 0x082b0808, 0x2b080808, 0x082b0808, 0x2b08082b, 0x082b0808, 0x082b2b19, 0x082b0819,
    0x19082b08, 0x082b0819, 0x08080808, 0x082b082b, 0x0808082b, 0x082b082b, 0x08080819, 0x082b1908,
    0x08081908, 0x082b1908, 0x08190808, 0x082b1908, 0x19080808, 0x082b1908, 0x1919192b, 0x082b1908,
    0x08080808, 0x082b1919, 0x19080819, 0x082b1919, 0x192b1908, 0x082b1919, 0x2b190808, 0x082b192b,
    0x08082b08, 0x082b2b08, 0x082b0808, 0x082b2b08, 0x2b191908, 0x082b2b08, 0x19081908, 0x082b2b2b,
    0x08080819, 0x19080808, 0x08081908, 0x19080808, 0x08190808, 0x19080808, 0x08192b08, 0x19080808,
    0x082b0819, 0x19080808, 0x082b1908, 0x19080808, 0x19080808, 0x19080808, 0x19082b08, 0x19080808,
    0x1919192b, 0x19080808, 0x192b0808, 0x19080808, 0x2b080819, 0x19080808, 0x2b081908, 0x19080808,
    0x2b190808, 0x19080808, 0x08080808, 0x19080819, 0x082b0808, 0x19080819, 0x192b0819, 0x19080819,
    0x2b080808, 0x19080819, 0x2b081919, 0x19080819, 0x08080819, 0x1908082b, 0x08190808, 0x1908082b,
    0x19082b08, 0x1908082b, 0x1919192b, 0x1908082b, 0x192b2b08, 0x1908082b, 0x08080808, 0x19081908,
    0x08082b08, 0x19081908, 0x082b0808, 0x19081908, 0x2b080808, 0x19081908, 0x2b192b19, 0x19081908,
    0x0819082b, 0x19081919, 0x082b1908, 0x19081919, 0x08080808, 0x1908192b, 0x08080819, 0x19082b08,
    0x08081908, 0x19082b08, 0x08190808, 0x19082b08, 0x19080808, 0x19082b08, 0x19081919, 0x19082b08,
    0x08080808, 0x19082b19, 0x19192b08, 0x19082b19, 0x192b0819, 0x19082b19, 0x2b08082b, 0x19082b19,
    0x19081919, 0x19082b2b, 0x2b190808, 0x19082b2b, 0x08080808, 0x19190808, 0x08082b08, 0x19190808,
    0x08190819, 0x19190808, 0x08192b19, 0x19190808, 0x082b0808, 0x19190808, 0x2b080808, 0x19190808,
    0x2b082b08, 0x19190808, 0x08081908, 0x19190819, 0x1908082b, 0x19190819, 0x2b2b1908, 0x19190819,
    0x2b190819, 0x1919082b, 0x2b190808, 0x19191908, 0x2b19082b, 0x19191908, 0x08082b2b, 0x19191919,
    0x08080819, 0x1919192b, 0x19191908, 0x1919192b, 0x08080808, 0x19192b08, 0x08190819, 0x19192b08,
    0x08192b19, 0x19192b08, 0x192b1908, 0x19192b08, 0x19080808, 0x19192b19, 0x08082b08, 0x19192b2b,
    0x08081908, 0x192b0808, 0x08190808, 0x192b0808, 0x19080808, 0x192b0808, 0x192b2b08, 0x192b0808,
    0x08080808, 0x192b0819, 0x19191919, 0x192b0819, 0x08192b08, 0x192b082b, 0x192b0808, 0x192b082b,
    0x08080808, 0x192b1908, 0x08081919, 0x192b1908, 0x08190808, 0x192b1919, 0x0819082b, 0x192b1919,
    0x2b081908, 0x192b1919, 0x1908082b, 0x192b2b08, 0x08080808, 0x2b080808, 0x0808082b, 0x2b080808,
    0x08082b2b, 0x2b080808, 0x19080819, 0x2b080808, 0x2b08082b, 0x2b080808, 0x08081908, 0x2b080819,
    0x08192b08, 0x2b080819, 0x19080808, 0x2b080819, 0x08190819, 0x2b08082b, 0x08080819, 0x2b081908,
    0x08081908, 0x2b081908, 0x08190808, 0x2b081908, 0x08191919, 0x2b081908, 0x19080808, 0x2b081908,
    0x192b0808, 0x2b081908, 0x08080808, 0x2b081919, 0x1908192b, 0x2b081919, 0x2b191908, 0x2b081919,
    0x08082b19, 0x2b08192b, 0x19080808, 0x2b08192b, 0x192b0808, 0x2b08192b, 0x0808082b, 0x2b082b08,
    0x08081908, 0x2b082b19, 0x08190819, 0x2b082b2b, 0x08081908, 0x2b190808, 0x08190808, 0x2b190808,
    0x082b1908, 0x2b190808, 0x19080808, 0x2b190808, 0x2b2b0819, 0x2b190808, 0x0819192b, 0x2b190819,
    0x2b080808, 0x2b190819, 0x19081919, 0x2b19082b, 0x08080808, 0x2b191908, 0x082b082b, 0x2b191908,
    0x19081908, 0x2b191908, 0x19190819, 0x2b191919, 0x2b080819, 0x2b192b08, 0x082b0808, 0x2b192b19,
    0x0808082b, 0x2b2b0808, 0x19190808, 0x2b2b0808, 0x2b081919, 0x2b2b0808, 0x08082b19, 0x2b2b0819,
    0x08080808, 0x2b2b082b, 0x08192b08, 0x2b2b1908, 0x19190808, 0x2b2b2b08, 0x08081908, 0x2b2b2b19
);

struct iq2_xxs {
    d: f16,
    qs: array<f16, 32>
};

fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block = src0[src0_idx_base + offset];
    let d = f32(block.d);
    var src1_i = src1_idx_base + offset * 256;
    var sum = 0.0;
    for (var ib: u32 = 0; ib < 32; ib += 4) {
        let aux0 = bitcast<u32>(vec2(block.qs[ib], block.qs[ib + 1]));
        let aux1 = bitcast<u32>(vec2(block.qs[ib + 2], block.qs[ib + 3]));
        let db = d * (0.5 + f32(aux1 >> 28)) * 0.25;
        for (var l: u32 = 0; l < 4; l++) {
            let ig = get_byte(aux0, l) * 8;
            let is = (aux1 >> (7 * l)) & 127;
            let signs = get_byte(ksigns_iq2xs[is / 4], is % 4);
            for (var j: u32 = 0; j < 8; j++) {
                let g = get_byte(iq2xxs_grid[(ig + j) / 4], (ig + j) % 4);
                let m = select(1.0, -1.0, (get_byte(kmask_iq2xs[j / 4], j % 4) & signs) != 0);
                sum += db * f32(g) * m * src1[src1_i];
                src1_i++;
            }
        }
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<iq2_xxs>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/256; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_iq2_xs_f32 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

const kmask_iq2xs : array<u32, 2> = array<u32, 2>(
    0x08040201u, // 1, 2, 4, 8
    0x80402010u  // 16, 32, 64, 128
);

const ksigns_iq2xs: array<u32, 32> = array<u32, 32>(
    0x03828100,0x87060584,0x8b0a0988,0x0f8e8d0c,
    0x93121190,0x17969514,0x1b9a9918,0x9f1e1d9c,
    0xa32221a0,0x27a6a524,0x2baaa928,0xaf2e2dac,
    0x33b2b130,0xb73635b4,0xbb3a39b8,0x3fbebd3c,
    0xc34241c0,0x47c6c544,0x4bcac948,0xcf4e4dcc,
    0x53d2d150,0xd75655d4,0xdb5a59d8,0x5fdedd5c,
    0x63e2e160,0xe76665e4,0xeb6a69e8,0x6feeed6c,
    0xf37271f0,0x77f6f574,0x7bfaf978,0xff7e7dfc
);

const iq2xs_grid = array<u32, 1024>(
    0x08080808, 0x08080808, 0x0808082b, 0x08080808, 0x08081919, 0x08080808, 0x08082b08, 0x08080808,
    0x08082b2b, 0x08080808, 0x08190819, 0x08080808, 0x08191908, 0x08080808, 0x0819192b, 0x08080808,
    0x08192b19, 0x08080808, 0x082b0808, 0x08080808, 0x082b082b, 0x08080808, 0x082b1919, 0x08080808,
    0x082b2b08, 0x08080808, 0x19080819, 0x08080808, 0x19081908, 0x08080808, 0x1908192b, 0x08080808,
    0x19082b19, 0x08080808, 0x19190808, 0x08080808, 0x1919082b, 0x08080808, 0x19191919, 0x08080808,
    0x19192b08, 0x08080808, 0x192b0819, 0x08080808, 0x192b1908, 0x08080808, 0x2b080808, 0x08080808,
    0x2b08082b, 0x08080808, 0x2b081919, 0x08080808, 0x2b082b08, 0x08080808, 0x2b190819, 0x08080808,
    0x2b191908, 0x08080808, 0x2b192b19, 0x08080808, 0x2b2b0808, 0x08080808, 0x08080819, 0x08080819,
    0x08081908, 0x08080819, 0x0808192b, 0x08080819, 0x08082b19, 0x08080819, 0x08190808, 0x08080819,
    0x0819082b, 0x08080819, 0x08191919, 0x08080819, 0x08192b08, 0x08080819, 0x08192b2b, 0x08080819,
    0x082b0819, 0x08080819, 0x082b1908, 0x08080819, 0x19080808, 0x08080819, 0x1908082b, 0x08080819,
    0x19081919, 0x08080819, 0x19082b08, 0x08080819, 0x19190819, 0x08080819, 0x19191908, 0x08080819,
    0x192b0808, 0x08080819, 0x192b2b08, 0x08080819, 0x2b080819, 0x08080819, 0x2b081908, 0x08080819,
    0x2b190808, 0x08080819, 0x08080808, 0x0808082b, 0x0808082b, 0x0808082b, 0x08081919, 0x0808082b,
    0x08082b08, 0x0808082b, 0x08190819, 0x0808082b, 0x08191908, 0x0808082b, 0x082b0808, 0x0808082b,
    0x19080819, 0x0808082b, 0x19081908, 0x0808082b, 0x19190808, 0x0808082b, 0x19191919, 0x0808082b,
    0x2b080808, 0x0808082b, 0x2b082b2b, 0x0808082b, 0x08080819, 0x08081908, 0x08081908, 0x08081908,
    0x0808192b, 0x08081908, 0x08082b19, 0x08081908, 0x08190808, 0x08081908, 0x0819082b, 0x08081908,
    0x08191919, 0x08081908, 0x08192b08, 0x08081908, 0x082b0819, 0x08081908, 0x082b1908, 0x08081908,
    0x19080808, 0x08081908, 0x1908082b, 0x08081908, 0x19081919, 0x08081908, 0x19082b08, 0x08081908,
    0x19190819, 0x08081908, 0x19191908, 0x08081908, 0x1919192b, 0x08081908, 0x192b0808, 0x08081908,
    0x2b080819, 0x08081908, 0x2b081908, 0x08081908, 0x2b190808, 0x08081908, 0x08080808, 0x08081919,
    0x0808082b, 0x08081919, 0x08081919, 0x08081919, 0x08082b08, 0x08081919, 0x08190819, 0x08081919,
    0x08191908, 0x08081919, 0x082b0808, 0x08081919, 0x19080819, 0x08081919, 0x19081908, 0x08081919,
    0x19190808, 0x08081919, 0x192b0819, 0x08081919, 0x2b080808, 0x08081919, 0x08080819, 0x0808192b,
    0x08081908, 0x0808192b, 0x08190808, 0x0808192b, 0x082b192b, 0x0808192b, 0x19080808, 0x0808192b,
    0x1908082b, 0x0808192b, 0x2b081908, 0x0808192b, 0x08080808, 0x08082b08, 0x0808082b, 0x08082b08,
    0x08081919, 0x08082b08, 0x08082b08, 0x08082b08, 0x08082b2b, 0x08082b08, 0x08190819, 0x08082b08,
    0x08191908, 0x08082b08, 0x082b0808, 0x08082b08, 0x082b1919, 0x08082b08, 0x19080819, 0x08082b08,
    0x19081908, 0x08082b08, 0x19190808, 0x08082b08, 0x19192b08, 0x08082b08, 0x2b080808, 0x08082b08,
    0x2b2b0808, 0x08082b08, 0x2b2b2b2b, 0x08082b08, 0x08080819, 0x08082b19, 0x08081908, 0x08082b19,
    0x08190808, 0x08082b19, 0x19080808, 0x08082b19, 0x2b080819, 0x08082b19, 0x2b082b19, 0x08082b19,
    0x08080808, 0x08082b2b, 0x082b0808, 0x08082b2b, 0x082b2b08, 0x08082b2b, 0x2b19192b, 0x08082b2b,
    0x2b2b0808, 0x08082b2b, 0x08080819, 0x08190808, 0x08081908, 0x08190808, 0x0808192b, 0x08190808,
    0x08082b19, 0x08190808, 0x08190808, 0x08190808, 0x0819082b, 0x08190808, 0x08191919, 0x08190808,
    0x08192b08, 0x08190808, 0x082b0819, 0x08190808, 0x082b1908, 0x08190808, 0x19080808, 0x08190808,
    0x1908082b, 0x08190808, 0x19081919, 0x08190808, 0x19082b08, 0x08190808, 0x19190819, 0x08190808,
    0x19191908, 0x08190808, 0x192b0808, 0x08190808, 0x192b2b2b, 0x08190808, 0x2b080819, 0x08190808,
    0x2b081908, 0x08190808, 0x2b190808, 0x08190808, 0x08080808, 0x08190819, 0x0808082b, 0x08190819,
    0x08081919, 0x08190819, 0x08082b08, 0x08190819, 0x08190819, 0x08190819, 0x08191908, 0x08190819,
    0x082b0808, 0x08190819, 0x19080819, 0x08190819, 0x19081908, 0x08190819, 0x19190808, 0x08190819,
    0x2b080808, 0x08190819, 0x2b191908, 0x08190819, 0x2b19192b, 0x08190819, 0x08080819, 0x0819082b,
    0x08081908, 0x0819082b, 0x0808192b, 0x0819082b, 0x08190808, 0x0819082b, 0x19080808, 0x0819082b,
    0x192b0808, 0x0819082b, 0x08080808, 0x08191908, 0x0808082b, 0x08191908, 0x08081919, 0x08191908,
    0x08082b08, 0x08191908, 0x08190819, 0x08191908, 0x08191908, 0x08191908, 0x082b0808, 0x08191908,
    0x19080819, 0x08191908, 0x19081908, 0x08191908, 0x19082b19, 0x08191908, 0x19190808, 0x08191908,
    0x192b1908, 0x08191908, 0x2b080808, 0x08191908, 0x08080819, 0x08191919, 0x08081908, 0x08191919,
    0x08190808, 0x08191919, 0x19080808, 0x08191919, 0x08080808, 0x0819192b, 0x08191908, 0x0819192b,
    0x19082b19, 0x0819192b, 0x08080819, 0x08192b08, 0x08081908, 0x08192b08, 0x08190808, 0x08192b08,
    0x0819082b, 0x08192b08, 0x19080808, 0x08192b08, 0x19191908, 0x08192b08, 0x2b08192b, 0x08192b08,
    0x08080808, 0x08192b19, 0x08081919, 0x08192b19, 0x192b192b, 0x08192b19, 0x19190819, 0x08192b2b,
    0x2b2b2b19, 0x08192b2b, 0x08080808, 0x082b0808, 0x0808082b, 0x082b0808, 0x08081919, 0x082b0808,
    0x08082b08, 0x082b0808, 0x08082b2b, 0x082b0808, 0x08190819, 0x082b0808, 0x08191908, 0x082b0808,
    0x082b0808, 0x082b0808, 0x19080819, 0x082b0808, 0x19081908, 0x082b0808, 0x19190808, 0x082b0808,
    0x2b080808, 0x082b0808, 0x2b2b0808, 0x082b0808, 0x08080819, 0x082b0819, 0x08081908, 0x082b0819,
    0x08190808, 0x082b0819, 0x19080808, 0x082b0819, 0x19082b08, 0x082b0819, 0x192b1919, 0x082b0819,
    0x08080808, 0x082b082b, 0x082b082b, 0x082b082b, 0x2b080808, 0x082b082b, 0x2b2b2b08, 0x082b082b,
    0x08080819, 0x082b1908, 0x08081908, 0x082b1908, 0x08190808, 0x082b1908, 0x082b2b19, 0x082b1908,
    0x19080808, 0x082b1908, 0x08080808, 0x082b1919, 0x19080819, 0x082b1919, 0x1919082b, 0x082b1919,
    0x2b192b19, 0x082b1919, 0x08080819, 0x082b192b, 0x08192b2b, 0x082b192b, 0x2b2b192b, 0x082b192b,
    0x08080808, 0x082b2b08, 0x08082b08, 0x082b2b08, 0x08082b2b, 0x082b2b08, 0x082b0808, 0x082b2b08,
    0x19191919, 0x082b2b08, 0x2b082b08, 0x082b2b08, 0x2b2b082b, 0x082b2b08, 0x192b2b08, 0x082b2b19,
    0x2b190808, 0x082b2b19, 0x08082b08, 0x082b2b2b, 0x082b0808, 0x082b2b2b, 0x2b08082b, 0x082b2b2b,
    0x2b082b08, 0x082b2b2b, 0x2b082b2b, 0x082b2b2b, 0x08080819, 0x19080808, 0x08081908, 0x19080808,
    0x0808192b, 0x19080808, 0x08082b19, 0x19080808, 0x08190808, 0x19080808, 0x0819082b, 0x19080808,
    0x08191919, 0x19080808, 0x08192b08, 0x19080808, 0x082b0819, 0x19080808, 0x082b1908, 0x19080808,
    0x19080808, 0x19080808, 0x1908082b, 0x19080808, 0x19081919, 0x19080808, 0x19082b08, 0x19080808,
    0x19082b2b, 0x19080808, 0x19190819, 0x19080808, 0x19191908, 0x19080808, 0x192b0808, 0x19080808,
    0x192b1919, 0x19080808, 0x2b080819, 0x19080808, 0x2b081908, 0x19080808, 0x2b190808, 0x19080808,
    0x08080808, 0x19080819, 0x0808082b, 0x19080819, 0x08081919, 0x19080819, 0x08082b08, 0x19080819,
    0x08190819, 0x19080819, 0x08191908, 0x19080819, 0x082b0808, 0x19080819, 0x19080819, 0x19080819,
    0x19081908, 0x19080819, 0x19190808, 0x19080819, 0x2b080808, 0x19080819, 0x2b081919, 0x19080819,
    0x2b2b082b, 0x19080819, 0x08080819, 0x1908082b, 0x08081908, 0x1908082b, 0x08190808, 0x1908082b,
    0x0819082b, 0x1908082b, 0x082b2b19, 0x1908082b, 0x19080808, 0x1908082b, 0x08080808, 0x19081908,
    0x0808082b, 0x19081908, 0x08081919, 0x19081908, 0x08082b08, 0x19081908, 0x08190819, 0x19081908,
    0x08191908, 0x19081908, 0x08192b19, 0x19081908, 0x082b0808, 0x19081908, 0x19080819, 0x19081908,
    0x19081908, 0x19081908, 0x19190808, 0x19081908, 0x2b080808, 0x19081908, 0x2b191908, 0x19081908,
    0x08080819, 0x19081919, 0x08081908, 0x19081919, 0x08190808, 0x19081919, 0x082b1908, 0x19081919,
    0x19080808, 0x19081919, 0x2b192b2b, 0x19081919, 0x08080808, 0x1908192b, 0x08082b2b, 0x1908192b,
    0x19081908, 0x1908192b, 0x19190808, 0x1908192b, 0x08080819, 0x19082b08, 0x08081908, 0x19082b08,
    0x08190808, 0x19082b08, 0x19080808, 0x19082b08, 0x19081919, 0x19082b08, 0x19191908, 0x19082b08,
    0x192b082b, 0x19082b08, 0x08080808, 0x19082b19, 0x08190819, 0x19082b19, 0x19081908, 0x19082b19,
    0x19190808, 0x19082b19, 0x192b2b19, 0x19082b19, 0x08081908, 0x19082b2b, 0x08080808, 0x19190808,
    0x0808082b, 0x19190808, 0x08081919, 0x19190808, 0x08082b08, 0x19190808, 0x08190819, 0x19190808,
    0x08191908, 0x19190808, 0x082b0808, 0x19190808, 0x082b2b08, 0x19190808, 0x19080819, 0x19190808,
    0x19081908, 0x19190808, 0x19190808, 0x19190808, 0x2b080808, 0x19190808, 0x08080819, 0x19190819,
    0x08081908, 0x19190819, 0x08190808, 0x19190819, 0x08191919, 0x19190819, 0x19080808, 0x19190819,
    0x1908082b, 0x19190819, 0x08080808, 0x1919082b, 0x19081908, 0x1919082b, 0x2b2b2b2b, 0x1919082b,
    0x08080819, 0x19191908, 0x08081908, 0x19191908, 0x08190808, 0x19191908, 0x082b0819, 0x19191908,
    0x19080808, 0x19191908, 0x192b0808, 0x19191908, 0x2b080819, 0x19191908, 0x2b2b0819, 0x19191908,
    0x08080808, 0x19191919, 0x08082b08, 0x19191919, 0x2b080808, 0x19191919, 0x2b082b08, 0x19191919,
    0x082b0819, 0x1919192b, 0x192b2b08, 0x1919192b, 0x2b2b0819, 0x1919192b, 0x08080808, 0x19192b08,
    0x08191908, 0x19192b08, 0x19080819, 0x19192b08, 0x19190808, 0x19192b08, 0x2b192b19, 0x19192b08,
    0x08192b2b, 0x19192b19, 0x19080808, 0x19192b19, 0x1908082b, 0x19192b19, 0x2b081919, 0x19192b2b,
    0x08080819, 0x192b0808, 0x08081908, 0x192b0808, 0x08190808, 0x192b0808, 0x19080808, 0x192b0808,
    0x19191908, 0x192b0808, 0x192b082b, 0x192b0808, 0x2b08192b, 0x192b0808, 0x2b2b2b19, 0x192b0808,
    0x08080808, 0x192b0819, 0x082b1908, 0x192b082b, 0x19082b2b, 0x192b082b, 0x2b19082b, 0x192b082b,
    0x08080808, 0x192b1908, 0x0819192b, 0x192b1908, 0x08190808, 0x192b1919, 0x19080808, 0x192b1919,
    0x19081919, 0x192b1919, 0x2b2b1908, 0x192b1919, 0x08080819, 0x192b2b08, 0x192b2b2b, 0x192b2b08,
    0x082b1919, 0x192b2b19, 0x0808192b, 0x192b2b2b, 0x19191908, 0x192b2b2b, 0x192b082b, 0x192b2b2b,
    0x08080808, 0x2b080808, 0x0808082b, 0x2b080808, 0x08081919, 0x2b080808, 0x08082b08, 0x2b080808,
    0x08190819, 0x2b080808, 0x08191908, 0x2b080808, 0x082b0808, 0x2b080808, 0x082b2b2b, 0x2b080808,
    0x19080819, 0x2b080808, 0x19081908, 0x2b080808, 0x19190808, 0x2b080808, 0x2b080808, 0x2b080808,
    0x2b08082b, 0x2b080808, 0x2b2b2b08, 0x2b080808, 0x2b2b2b2b, 0x2b080808, 0x08080819, 0x2b080819,
    0x08081908, 0x2b080819, 0x0808192b, 0x2b080819, 0x08190808, 0x2b080819, 0x19080808, 0x2b080819,
    0x19190819, 0x2b080819, 0x19192b19, 0x2b080819, 0x08080808, 0x2b08082b, 0x082b0808, 0x2b08082b,
    0x2b080808, 0x2b08082b, 0x2b08082b, 0x2b08082b, 0x2b2b0808, 0x2b08082b, 0x2b2b2b08, 0x2b08082b,
    0x08080819, 0x2b081908, 0x08081908, 0x2b081908, 0x08190808, 0x2b081908, 0x0819082b, 0x2b081908,
    0x08191919, 0x2b081908, 0x19080808, 0x2b081908, 0x192b0808, 0x2b081908, 0x2b082b19, 0x2b081908,
    0x08080808, 0x2b081919, 0x19081908, 0x2b081919, 0x2b2b1919, 0x2b081919, 0x08192b08, 0x2b08192b,
    0x192b2b2b, 0x2b08192b, 0x08080808, 0x2b082b08, 0x08082b08, 0x2b082b08, 0x082b1919, 0x2b082b08,
    0x19192b2b, 0x2b082b08, 0x2b080808, 0x2b082b08, 0x2b08082b, 0x2b082b08, 0x2b2b2b08, 0x2b082b08,
    0x0808192b, 0x2b082b19, 0x082b082b, 0x2b082b2b, 0x2b080808, 0x2b082b2b, 0x2b082b08, 0x2b082b2b,
    0x2b19192b, 0x2b082b2b, 0x2b2b2b08, 0x2b082b2b, 0x08080819, 0x2b190808, 0x08081908, 0x2b190808,
    0x08190808, 0x2b190808, 0x19080808, 0x2b190808, 0x1919192b, 0x2b190808, 0x2b081908, 0x2b190808,
    0x08080808, 0x2b190819, 0x082b082b, 0x2b190819, 0x192b1908, 0x2b190819, 0x1919192b, 0x2b19082b,
    0x2b082b19, 0x2b19082b, 0x08080808, 0x2b191908, 0x08081919, 0x2b191908, 0x19081908, 0x2b191908,
    0x19190808, 0x2b191908, 0x19192b08, 0x2b191908, 0x082b2b19, 0x2b191919, 0x2b190808, 0x2b191919,
    0x2b19082b, 0x2b191919, 0x19080819, 0x2b19192b, 0x19190819, 0x2b192b08, 0x2b2b192b, 0x2b192b08,
    0x19082b19, 0x2b192b19, 0x08191919, 0x2b192b2b, 0x192b0808, 0x2b192b2b, 0x08080808, 0x2b2b0808,
    0x0808082b, 0x2b2b0808, 0x08082b08, 0x2b2b0808, 0x08082b2b, 0x2b2b0808, 0x082b0808, 0x2b2b0808,
    0x082b2b2b, 0x2b2b0808, 0x2b2b0808, 0x2b2b0808, 0x19190819, 0x2b2b0819, 0x19192b19, 0x2b2b0819,
    0x2b2b192b, 0x2b2b0819, 0x08080808, 0x2b2b082b, 0x0808082b, 0x2b2b082b, 0x08082b08, 0x2b2b082b,
    0x082b2b2b, 0x2b2b082b, 0x2b080808, 0x2b2b082b, 0x2b2b0808, 0x2b2b082b, 0x19080808, 0x2b2b1908,
    0x2b191919, 0x2b2b1908, 0x192b1919, 0x2b2b192b, 0x2b192b08, 0x2b2b192b, 0x08082b2b, 0x2b2b2b08,
    0x082b0808, 0x2b2b2b08, 0x082b082b, 0x2b2b2b08, 0x082b2b08, 0x2b2b2b08, 0x2b2b0808, 0x2b2b2b08,
    0x2b2b2b08, 0x2b2b2b08, 0x08081908, 0x2b2b2b19, 0x2b081908, 0x2b2b2b19, 0x2b08192b, 0x2b2b2b19,
    0x082b2b08, 0x2b2b2b2b, 0x082b2b2b, 0x2b2b2b2b, 0x2b190819, 0x2b2b2b2b, 0x2b2b2b2b, 0x2b2b2b2b
);

struct iq2_xs {
    d: f16,
    qs: array<f16, 32>,
    scales: array<f16, 4>
};

fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block = src0[src0_idx_base + offset];
    let d = f32(block.d);
    var src1_i = src1_idx_base + offset * 256;
    var scale_vals = array<u32, 2>(
        bitcast<u32>(vec2(block.scales[0], block.scales[1])),
        bitcast<u32>(vec2(block.scales[2], block.scales[3]))
    );
    var sum = 0.0;
    for (var ib: u32 = 0; ib < 32; ib += 4) {
        let s = get_byte(scale_vals[ib / 16], (ib % 16) / 4);
        let db = array<f32, 2>(
            d * (0.5 + f32(s & 0xF)) * 0.25,
            d * (0.5 + f32(s >> 4)) * 0.25
        );
        for (var l: u32 = 0; l < 4; l++) {
            let qs_val = bitcast<u32>(vec2(block.qs[ib + l], 0.0));
            let ig = (qs_val & 511) * 8;
            let is = qs_val >> 9;
            let signs = get_byte(ksigns_iq2xs[is / 4], is % 4);
            let dl = db[l/2];
            for (var j: u32 = 0; j < 8; j++) {
                let g = get_byte(iq2xs_grid[(ig + j) / 4], (ig + j) % 4);
                let m = select(1.0, -1.0, (get_byte(kmask_iq2xs[j / 4], j % 4) & signs) != 0);
                sum += dl * f32(g) * m * src1[src1_i];
                src1_i++;
            }
        }
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<iq2_xs>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/256; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_iq2_s_f32 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

const kmask_iq2xs : array<u32, 2> = array<u32, 2>(
    0x08040201u, // 1, 2, 4, 8
    0x80402010u  // 16, 32, 64, 128
);

const ksigns_iq2xs: array<u32, 32> = array<u32, 32>(
    0x03828100,0x87060584,0x8b0a0988,0x0f8e8d0c,
    0x93121190,0x17969514,0x1b9a9918,0x9f1e1d9c,
    0xa32221a0,0x27a6a524,0x2baaa928,0xaf2e2dac,
    0x33b2b130,0xb73635b4,0xbb3a39b8,0x3fbebd3c,
    0xc34241c0,0x47c6c544,0x4bcac948,0xcf4e4dcc,
    0x53d2d150,0xd75655d4,0xdb5a59d8,0x5fdedd5c,
    0x63e2e160,0xe76665e4,0xeb6a69e8,0x6feeed6c,
    0xf37271f0,0x77f6f574,0x7bfaf978,0xff7e7dfc
);

const iq2s_grid = array<u32, 2048>(
    0x08080808, 0x08080808, 0x0808082b, 0x08080808, 0x08081919, 0x08080808, 0x08082b08, 0x08080808,
    0x08082b2b, 0x08080808, 0x08190819, 0x08080808, 0x08191908, 0x08080808, 0x0819192b, 0x08080808,
    0x08192b19, 0x08080808, 0x082b0808, 0x08080808, 0x082b082b, 0x08080808, 0x082b1919, 0x08080808,
    0x082b2b08, 0x08080808, 0x19080819, 0x08080808, 0x19081908, 0x08080808, 0x1908192b, 0x08080808,
    0x19082b19, 0x08080808, 0x19190808, 0x08080808, 0x1919082b, 0x08080808, 0x19191919, 0x08080808,
    0x19192b08, 0x08080808, 0x192b0819, 0x08080808, 0x192b1908, 0x08080808, 0x192b192b, 0x08080808,
    0x192b2b19, 0x08080808, 0x2b080808, 0x08080808, 0x2b08082b, 0x08080808, 0x2b081919, 0x08080808,
    0x2b082b08, 0x08080808, 0x2b190819, 0x08080808, 0x2b191908, 0x08080808, 0x2b2b0808, 0x08080808,
    0x2b2b1919, 0x08080808, 0x2b2b2b2b, 0x08080808, 0x08080819, 0x08080819, 0x08081908, 0x08080819,
    0x0808192b, 0x08080819, 0x08082b19, 0x08080819, 0x08190808, 0x08080819, 0x0819082b, 0x08080819,
    0x08191919, 0x08080819, 0x08192b08, 0x08080819, 0x082b0819, 0x08080819, 0x082b1908, 0x08080819,
    0x19080808, 0x08080819, 0x1908082b, 0x08080819, 0x19081919, 0x08080819, 0x19082b08, 0x08080819,
    0x19190819, 0x08080819, 0x19191908, 0x08080819, 0x1919192b, 0x08080819, 0x19192b19, 0x08080819,
    0x192b0808, 0x08080819, 0x192b1919, 0x08080819, 0x192b2b08, 0x08080819, 0x2b080819, 0x08080819,
    0x2b081908, 0x08080819, 0x2b190808, 0x08080819, 0x2b19082b, 0x08080819, 0x2b191919, 0x08080819,
    0x2b2b0819, 0x08080819, 0x2b2b1908, 0x08080819, 0x08080808, 0x0808082b, 0x0808082b, 0x0808082b,
    0x08081919, 0x0808082b, 0x08082b08, 0x0808082b, 0x08190819, 0x0808082b, 0x08191908, 0x0808082b,
    0x082b0808, 0x0808082b, 0x082b2b2b, 0x0808082b, 0x19080819, 0x0808082b, 0x19081908, 0x0808082b,
    0x1908192b, 0x0808082b, 0x19082b19, 0x0808082b, 0x19190808, 0x0808082b, 0x19191919, 0x0808082b,
    0x2b080808, 0x0808082b, 0x2b081919, 0x0808082b, 0x2b082b2b, 0x0808082b, 0x2b191908, 0x0808082b,
    0x2b2b082b, 0x0808082b, 0x08080819, 0x08081908, 0x08081908, 0x08081908, 0x0808192b, 0x08081908,
    0x08082b19, 0x08081908, 0x08190808, 0x08081908, 0x0819082b, 0x08081908, 0x08191919, 0x08081908,
    0x08192b08, 0x08081908, 0x082b0819, 0x08081908, 0x082b1908, 0x08081908, 0x082b192b, 0x08081908,
    0x082b2b19, 0x08081908, 0x19080808, 0x08081908, 0x1908082b, 0x08081908, 0x19081919, 0x08081908,
    0x19082b08, 0x08081908, 0x19082b2b, 0x08081908, 0x19190819, 0x08081908, 0x19191908, 0x08081908,
    0x1919192b, 0x08081908, 0x19192b19, 0x08081908, 0x192b0808, 0x08081908, 0x192b082b, 0x08081908,
    0x192b1919, 0x08081908, 0x2b080819, 0x08081908, 0x2b081908, 0x08081908, 0x2b08192b, 0x08081908,
    0x2b082b19, 0x08081908, 0x2b190808, 0x08081908, 0x2b191919, 0x08081908, 0x2b192b08, 0x08081908,
    0x2b2b0819, 0x08081908, 0x2b2b1908, 0x08081908, 0x08080808, 0x08081919, 0x0808082b, 0x08081919,
    0x08081919, 0x08081919, 0x08082b08, 0x08081919, 0x08082b2b, 0x08081919, 0x08190819, 0x08081919,
    0x08191908, 0x08081919, 0x0819192b, 0x08081919, 0x08192b19, 0x08081919, 0x082b0808, 0x08081919,
    0x082b1919, 0x08081919, 0x082b2b08, 0x08081919, 0x19080819, 0x08081919, 0x19081908, 0x08081919,
    0x1908192b, 0x08081919, 0x19082b19, 0x08081919, 0x19190808, 0x08081919, 0x1919082b, 0x08081919,
    0x19191919, 0x08081919, 0x19192b08, 0x08081919, 0x192b0819, 0x08081919, 0x192b1908, 0x08081919,
    0x2b080808, 0x08081919, 0x2b08082b, 0x08081919, 0x2b081919, 0x08081919, 0x2b082b08, 0x08081919,
    0x2b190819, 0x08081919, 0x2b191908, 0x08081919, 0x2b2b0808, 0x08081919, 0x08080819, 0x0808192b,
    0x08081908, 0x0808192b, 0x0808192b, 0x0808192b, 0x08082b19, 0x0808192b, 0x08190808, 0x0808192b,
    0x08191919, 0x0808192b, 0x19080808, 0x0808192b, 0x19081919, 0x0808192b, 0x19082b08, 0x0808192b,
    0x19190819, 0x0808192b, 0x19191908, 0x0808192b, 0x192b0808, 0x0808192b, 0x2b080819, 0x0808192b,
    0x2b081908, 0x0808192b, 0x2b190808, 0x0808192b, 0x08080808, 0x08082b08, 0x0808082b, 0x08082b08,
    0x08081919, 0x08082b08, 0x08082b08, 0x08082b08, 0x08190819, 0x08082b08, 0x08191908, 0x08082b08,
    0x0819192b, 0x08082b08, 0x08192b19, 0x08082b08, 0x082b0808, 0x08082b08, 0x082b1919, 0x08082b08,
    0x082b2b2b, 0x08082b08, 0x19080819, 0x08082b08, 0x19081908, 0x08082b08, 0x1908192b, 0x08082b08,
    0x19082b19, 0x08082b08, 0x19190808, 0x08082b08, 0x1919082b, 0x08082b08, 0x19191919, 0x08082b08,
    0x19192b08, 0x08082b08, 0x192b0819, 0x08082b08, 0x192b1908, 0x08082b08, 0x2b080808, 0x08082b08,
    0x2b081919, 0x08082b08, 0x2b191908, 0x08082b08, 0x2b2b2b2b, 0x08082b08, 0x08080819, 0x08082b19,
    0x08081908, 0x08082b19, 0x08190808, 0x08082b19, 0x0819082b, 0x08082b19, 0x08191919, 0x08082b19,
    0x08192b08, 0x08082b19, 0x082b0819, 0x08082b19, 0x19080808, 0x08082b19, 0x19081919, 0x08082b19,
    0x19082b08, 0x08082b19, 0x19190819, 0x08082b19, 0x19191908, 0x08082b19, 0x192b0808, 0x08082b19,
    0x2b080819, 0x08082b19, 0x2b190808, 0x08082b19, 0x08080808, 0x08082b2b, 0x08190819, 0x08082b2b,
    0x08191908, 0x08082b2b, 0x082b082b, 0x08082b2b, 0x082b2b08, 0x08082b2b, 0x082b2b2b, 0x08082b2b,
    0x19190808, 0x08082b2b, 0x2b192b19, 0x08082b2b, 0x08080819, 0x08190808, 0x08081908, 0x08190808,
    0x0808192b, 0x08190808, 0x08082b19, 0x08190808, 0x08190808, 0x08190808, 0x0819082b, 0x08190808,
    0x08191919, 0x08190808, 0x08192b08, 0x08190808, 0x082b0819, 0x08190808, 0x082b1908, 0x08190808,
    0x082b192b, 0x08190808, 0x19080808, 0x08190808, 0x1908082b, 0x08190808, 0x19081919, 0x08190808,
    0x19082b08, 0x08190808, 0x19190819, 0x08190808, 0x19191908, 0x08190808, 0x1919192b, 0x08190808,
    0x19192b19, 0x08190808, 0x192b0808, 0x08190808, 0x192b082b, 0x08190808, 0x192b1919, 0x08190808,
    0x192b2b08, 0x08190808, 0x2b080819, 0x08190808, 0x2b081908, 0x08190808, 0x2b08192b, 0x08190808,
    0x2b190808, 0x08190808, 0x2b191919, 0x08190808, 0x2b192b08, 0x08190808, 0x2b2b0819, 0x08190808,
    0x2b2b1908, 0x08190808, 0x08080808, 0x08190819, 0x0808082b, 0x08190819, 0x08081919, 0x08190819,
    0x08082b08, 0x08190819, 0x08082b2b, 0x08190819, 0x08190819, 0x08190819, 0x08191908, 0x08190819,
    0x0819192b, 0x08190819, 0x08192b19, 0x08190819, 0x082b0808, 0x08190819, 0x082b082b, 0x08190819,
    0x082b1919, 0x08190819, 0x082b2b08, 0x08190819, 0x19080819, 0x08190819, 0x19081908, 0x08190819,
    0x1908192b, 0x08190819, 0x19082b19, 0x08190819, 0x19190808, 0x08190819, 0x1919082b, 0x08190819,
    0x19191919, 0x08190819, 0x19192b08, 0x08190819, 0x192b0819, 0x08190819, 0x192b1908, 0x08190819,
    0x2b080808, 0x08190819, 0x2b08082b, 0x08190819, 0x2b081919, 0x08190819, 0x2b082b08, 0x08190819,
    0x2b190819, 0x08190819, 0x2b191908, 0x08190819, 0x08080819, 0x0819082b, 0x08081908, 0x0819082b,
    0x08082b19, 0x0819082b, 0x08190808, 0x0819082b, 0x08191919, 0x0819082b, 0x082b0819, 0x0819082b,
    0x082b1908, 0x0819082b, 0x19080808, 0x0819082b, 0x19081919, 0x0819082b, 0x19190819, 0x0819082b,
    0x19191908, 0x0819082b, 0x2b080819, 0x0819082b, 0x2b081908, 0x0819082b, 0x2b190808, 0x0819082b,
    0x08080808, 0x08191908, 0x0808082b, 0x08191908, 0x08081919, 0x08191908, 0x08082b08, 0x08191908,
    0x08190819, 0x08191908, 0x08191908, 0x08191908, 0x0819192b, 0x08191908, 0x08192b19, 0x08191908,
    0x082b0808, 0x08191908, 0x082b1919, 0x08191908, 0x082b2b08, 0x08191908, 0x19080819, 0x08191908,
    0x19081908, 0x08191908, 0x1908192b, 0x08191908, 0x19082b19, 0x08191908, 0x19190808, 0x08191908,
    0x1919082b, 0x08191908, 0x19191919, 0x08191908, 0x19192b08, 0x08191908, 0x192b0819, 0x08191908,
    0x192b1908, 0x08191908, 0x2b080808, 0x08191908, 0x2b08082b, 0x08191908, 0x2b081919, 0x08191908,
    0x2b082b08, 0x08191908, 0x2b190819, 0x08191908, 0x2b191908, 0x08191908, 0x2b2b0808, 0x08191908,
    0x08080819, 0x08191919, 0x08081908, 0x08191919, 0x0808192b, 0x08191919, 0x08082b19, 0x08191919,
    0x08190808, 0x08191919, 0x0819082b, 0x08191919, 0x08191919, 0x08191919, 0x08192b08, 0x08191919,
    0x082b0819, 0x08191919, 0x082b1908, 0x08191919, 0x19080808, 0x08191919, 0x1908082b, 0x08191919,
    0x19081919, 0x08191919, 0x19082b08, 0x08191919, 0x19190819, 0x08191919, 0x19191908, 0x08191919,
    0x192b0808, 0x08191919, 0x2b080819, 0x08191919, 0x2b081908, 0x08191919, 0x2b190808, 0x08191919,
    0x08080808, 0x0819192b, 0x08081919, 0x0819192b, 0x08082b08, 0x0819192b, 0x08190819, 0x0819192b,
    0x08191908, 0x0819192b, 0x082b0808, 0x0819192b, 0x19080819, 0x0819192b, 0x19081908, 0x0819192b,
    0x19190808, 0x0819192b, 0x2b080808, 0x0819192b, 0x2b2b2b2b, 0x0819192b, 0x08080819, 0x08192b08,
    0x08081908, 0x08192b08, 0x0808192b, 0x08192b08, 0x08082b19, 0x08192b08, 0x08190808, 0x08192b08,
    0x08191919, 0x08192b08, 0x08192b08, 0x08192b08, 0x082b0819, 0x08192b08, 0x19080808, 0x08192b08,
    0x1908082b, 0x08192b08, 0x19081919, 0x08192b08, 0x19082b08, 0x08192b08, 0x19190819, 0x08192b08,
    0x19191908, 0x08192b08, 0x192b0808, 0x08192b08, 0x2b080819, 0x08192b08, 0x2b081908, 0x08192b08,
    0x08080808, 0x08192b19, 0x0808082b, 0x08192b19, 0x08081919, 0x08192b19, 0x08082b08, 0x08192b19,
    0x08190819, 0x08192b19, 0x08191908, 0x08192b19, 0x082b0808, 0x08192b19, 0x19080819, 0x08192b19,
    0x19081908, 0x08192b19, 0x19190808, 0x08192b19, 0x192b2b19, 0x08192b19, 0x2b2b082b, 0x08192b19,
    0x08081908, 0x08192b2b, 0x08190808, 0x08192b2b, 0x19080808, 0x08192b2b, 0x1919192b, 0x08192b2b,
    0x08080808, 0x082b0808, 0x0808082b, 0x082b0808, 0x08081919, 0x082b0808, 0x08082b08, 0x082b0808,
    0x08190819, 0x082b0808, 0x08191908, 0x082b0808, 0x0819192b, 0x082b0808, 0x08192b19, 0x082b0808,
    0x082b0808, 0x082b0808, 0x082b1919, 0x082b0808, 0x082b2b2b, 0x082b0808, 0x19080819, 0x082b0808,
    0x19081908, 0x082b0808, 0x19190808, 0x082b0808, 0x1919082b, 0x082b0808, 0x19191919, 0x082b0808,
    0x192b1908, 0x082b0808, 0x2b080808, 0x082b0808, 0x2b082b2b, 0x082b0808, 0x2b191908, 0x082b0808,
    0x2b2b2b2b, 0x082b0808, 0x08080819, 0x082b0819, 0x08081908, 0x082b0819, 0x08190808, 0x082b0819,
    0x0819082b, 0x082b0819, 0x08191919, 0x082b0819, 0x082b0819, 0x082b0819, 0x19080808, 0x082b0819,
    0x1908082b, 0x082b0819, 0x19081919, 0x082b0819, 0x19190819, 0x082b0819, 0x19191908, 0x082b0819,
    0x192b0808, 0x082b0819, 0x2b080819, 0x082b0819, 0x2b081908, 0x082b0819, 0x2b190808, 0x082b0819,
    0x08080808, 0x082b082b, 0x08082b2b, 0x082b082b, 0x082b082b, 0x082b082b, 0x082b2b08, 0x082b082b,
    0x082b2b2b, 0x082b082b, 0x19081908, 0x082b082b, 0x19190808, 0x082b082b, 0x2b082b08, 0x082b082b,
    0x2b082b2b, 0x082b082b, 0x2b2b2b08, 0x082b082b, 0x08080819, 0x082b1908, 0x08081908, 0x082b1908,
    0x0808192b, 0x082b1908, 0x08082b19, 0x082b1908, 0x08190808, 0x082b1908, 0x08191919, 0x082b1908,
    0x08192b08, 0x082b1908, 0x082b0819, 0x082b1908, 0x082b1908, 0x082b1908, 0x19080808, 0x082b1908,
    0x1908082b, 0x082b1908, 0x19081919, 0x082b1908, 0x19082b08, 0x082b1908, 0x19190819, 0x082b1908,
    0x19191908, 0x082b1908, 0x192b0808, 0x082b1908, 0x2b080819, 0x082b1908, 0x2b081908, 0x082b1908,
    0x2b190808, 0x082b1908, 0x08080808, 0x082b1919, 0x08081919, 0x082b1919, 0x08082b08, 0x082b1919,
    0x08190819, 0x082b1919, 0x08191908, 0x082b1919, 0x082b0808, 0x082b1919, 0x19080819, 0x082b1919,
    0x19081908, 0x082b1919, 0x19190808, 0x082b1919, 0x192b192b, 0x082b1919, 0x2b080808, 0x082b1919,
    0x08080819, 0x082b192b, 0x08081908, 0x082b192b, 0x08190808, 0x082b192b, 0x19080808, 0x082b192b,
    0x19192b19, 0x082b192b, 0x08080808, 0x082b2b08, 0x08081919, 0x082b2b08, 0x08190819, 0x082b2b08,
    0x08191908, 0x082b2b08, 0x19080819, 0x082b2b08, 0x19081908, 0x082b2b08, 0x19190808, 0x082b2b08,
    0x2b082b2b, 0x082b2b08, 0x2b2b2b2b, 0x082b2b08, 0x08080819, 0x082b2b19, 0x08081908, 0x082b2b19,
    0x08190808, 0x082b2b19, 0x2b191919, 0x082b2b19, 0x08082b2b, 0x082b2b2b, 0x082b082b, 0x082b2b2b,
    0x192b1908, 0x082b2b2b, 0x2b082b08, 0x082b2b2b, 0x2b082b2b, 0x082b2b2b, 0x08080819, 0x19080808,
    0x08081908, 0x19080808, 0x0808192b, 0x19080808, 0x08082b19, 0x19080808, 0x08190808, 0x19080808,
    0x0819082b, 0x19080808, 0x08191919, 0x19080808, 0x08192b08, 0x19080808, 0x08192b2b, 0x19080808,
    0x082b0819, 0x19080808, 0x082b1908, 0x19080808, 0x082b192b, 0x19080808, 0x19080808, 0x19080808,
    0x1908082b, 0x19080808, 0x19081919, 0x19080808, 0x19082b08, 0x19080808, 0x19082b2b, 0x19080808,
    0x19190819, 0x19080808, 0x19191908, 0x19080808, 0x1919192b, 0x19080808, 0x19192b19, 0x19080808,
    0x192b0808, 0x19080808, 0x192b082b, 0x19080808, 0x192b1919, 0x19080808, 0x2b080819, 0x19080808,
    0x2b081908, 0x19080808, 0x2b190808, 0x19080808, 0x2b191919, 0x19080808, 0x2b192b08, 0x19080808,
    0x2b2b0819, 0x19080808, 0x2b2b1908, 0x19080808, 0x08080808, 0x19080819, 0x0808082b, 0x19080819,
    0x08081919, 0x19080819, 0x08082b08, 0x19080819, 0x08190819, 0x19080819, 0x08191908, 0x19080819,
    0x0819192b, 0x19080819, 0x08192b19, 0x19080819, 0x082b0808, 0x19080819, 0x082b082b, 0x19080819,
    0x082b1919, 0x19080819, 0x19080819, 0x19080819, 0x19081908, 0x19080819, 0x1908192b, 0x19080819,
    0x19082b19, 0x19080819, 0x19190808, 0x19080819, 0x1919082b, 0x19080819, 0x19191919, 0x19080819,
    0x19192b08, 0x19080819, 0x192b0819, 0x19080819, 0x192b1908, 0x19080819, 0x2b080808, 0x19080819,
    0x2b08082b, 0x19080819, 0x2b081919, 0x19080819, 0x2b082b08, 0x19080819, 0x2b190819, 0x19080819,
    0x2b191908, 0x19080819, 0x2b2b0808, 0x19080819, 0x08080819, 0x1908082b, 0x08081908, 0x1908082b,
    0x08190808, 0x1908082b, 0x0819082b, 0x1908082b, 0x08191919, 0x1908082b, 0x08192b08, 0x1908082b,
    0x082b1908, 0x1908082b, 0x19080808, 0x1908082b, 0x19081919, 0x1908082b, 0x19082b08, 0x1908082b,
    0x19190819, 0x1908082b, 0x19191908, 0x1908082b, 0x192b0808, 0x1908082b, 0x2b080819, 0x1908082b,
    0x2b081908, 0x1908082b, 0x08080808, 0x19081908, 0x0808082b, 0x19081908, 0x08081919, 0x19081908,
    0x08082b08, 0x19081908, 0x08082b2b, 0x19081908, 0x08190819, 0x19081908, 0x08191908, 0x19081908,
    0x0819192b, 0x19081908, 0x08192b19, 0x19081908, 0x082b0808, 0x19081908, 0x082b082b, 0x19081908,
    0x082b1919, 0x19081908, 0x082b2b08, 0x19081908, 0x19080819, 0x19081908, 0x19081908, 0x19081908,
    0x1908192b, 0x19081908, 0x19082b19, 0x19081908, 0x19190808, 0x19081908, 0x1919082b, 0x19081908,
    0x19191919, 0x19081908, 0x19192b08, 0x19081908, 0x192b0819, 0x19081908, 0x192b1908, 0x19081908,
    0x2b080808, 0x19081908, 0x2b08082b, 0x19081908, 0x2b081919, 0x19081908, 0x2b082b08, 0x19081908,
    0x2b190819, 0x19081908, 0x2b191908, 0x19081908, 0x2b2b0808, 0x19081908, 0x08080819, 0x19081919,
    0x08081908, 0x19081919, 0x0808192b, 0x19081919, 0x08082b19, 0x19081919, 0x08190808, 0x19081919,
    0x0819082b, 0x19081919, 0x08191919, 0x19081919, 0x08192b08, 0x19081919, 0x082b0819, 0x19081919,
    0x082b1908, 0x19081919, 0x19080808, 0x19081919, 0x1908082b, 0x19081919, 0x19081919, 0x19081919,
    0x19082b08, 0x19081919, 0x19190819, 0x19081919, 0x19191908, 0x19081919, 0x192b0808, 0x19081919,
    0x192b2b2b, 0x19081919, 0x2b080819, 0x19081919, 0x2b081908, 0x19081919, 0x2b190808, 0x19081919,
    0x08080808, 0x1908192b, 0x0808082b, 0x1908192b, 0x08081919, 0x1908192b, 0x08082b08, 0x1908192b,
    0x08190819, 0x1908192b, 0x08191908, 0x1908192b, 0x082b0808, 0x1908192b, 0x19080819, 0x1908192b,
    0x19081908, 0x1908192b, 0x19190808, 0x1908192b, 0x2b080808, 0x1908192b, 0x2b2b1919, 0x1908192b,
    0x08080819, 0x19082b08, 0x08081908, 0x19082b08, 0x08082b19, 0x19082b08, 0x08190808, 0x19082b08,
    0x0819082b, 0x19082b08, 0x08191919, 0x19082b08, 0x08192b08, 0x19082b08, 0x082b0819, 0x19082b08,
    0x082b1908, 0x19082b08, 0x19080808, 0x19082b08, 0x1908082b, 0x19082b08, 0x19081919, 0x19082b08,
    0x19082b08, 0x19082b08, 0x19190819, 0x19082b08, 0x19191908, 0x19082b08, 0x192b0808, 0x19082b08,
    0x2b081908, 0x19082b08, 0x2b190808, 0x19082b08, 0x08080808, 0x19082b19, 0x0808082b, 0x19082b19,
    0x08081919, 0x19082b19, 0x08082b08, 0x19082b19, 0x08190819, 0x19082b19, 0x08191908, 0x19082b19,
    0x082b0808, 0x19082b19, 0x19080819, 0x19082b19, 0x19081908, 0x19082b19, 0x19190808, 0x19082b19,
    0x2b080808, 0x19082b19, 0x2b19192b, 0x19082b19, 0x08080819, 0x19082b2b, 0x08081908, 0x19082b2b,
    0x08190808, 0x19082b2b, 0x19080808, 0x19082b2b, 0x08080808, 0x19190808, 0x0808082b, 0x19190808,
    0x08081919, 0x19190808, 0x08082b08, 0x19190808, 0x08190819, 0x19190808, 0x08191908, 0x19190808,
    0x0819192b, 0x19190808, 0x08192b19, 0x19190808, 0x082b0808, 0x19190808, 0x082b082b, 0x19190808,
    0x082b1919, 0x19190808, 0x082b2b08, 0x19190808, 0x19080819, 0x19190808, 0x19081908, 0x19190808,
    0x1908192b, 0x19190808, 0x19082b19, 0x19190808, 0x19190808, 0x19190808, 0x1919082b, 0x19190808,
    0x19191919, 0x19190808, 0x19192b08, 0x19190808, 0x192b0819, 0x19190808, 0x192b1908, 0x19190808,
    0x2b080808, 0x19190808, 0x2b08082b, 0x19190808, 0x2b081919, 0x19190808, 0x2b082b08, 0x19190808,
    0x2b190819, 0x19190808, 0x2b191908, 0x19190808, 0x08080819, 0x19190819, 0x08081908, 0x19190819,
    0x0808192b, 0x19190819, 0x08082b19, 0x19190819, 0x08190808, 0x19190819, 0x0819082b, 0x19190819,
    0x08191919, 0x19190819, 0x08192b08, 0x19190819, 0x082b0819, 0x19190819, 0x082b1908, 0x19190819,
    0x19080808, 0x19190819, 0x1908082b, 0x19190819, 0x19081919, 0x19190819, 0x19082b08, 0x19190819,
    0x19190819, 0x19190819, 0x19191908, 0x19190819, 0x192b0808, 0x19190819, 0x2b080819, 0x19190819,
    0x2b081908, 0x19190819, 0x2b190808, 0x19190819, 0x08080808, 0x1919082b, 0x08081919, 0x1919082b,
    0x08082b08, 0x1919082b, 0x08190819, 0x1919082b, 0x08191908, 0x1919082b, 0x082b0808, 0x1919082b,
    0x19080819, 0x1919082b, 0x19081908, 0x1919082b, 0x19190808, 0x1919082b, 0x192b2b19, 0x1919082b,
    0x2b080808, 0x1919082b, 0x08080819, 0x19191908, 0x08081908, 0x19191908, 0x0808192b, 0x19191908,
    0x08082b19, 0x19191908, 0x08190808, 0x19191908, 0x0819082b, 0x19191908, 0x08191919, 0x19191908,
    0x08192b08, 0x19191908, 0x082b0819, 0x19191908, 0x082b1908, 0x19191908, 0x19080808, 0x19191908,
    0x1908082b, 0x19191908, 0x19081919, 0x19191908, 0x19082b08, 0x19191908, 0x19190819, 0x19191908,
    0x19191908, 0x19191908, 0x192b0808, 0x19191908, 0x2b080819, 0x19191908, 0x2b081908, 0x19191908,
    0x2b190808, 0x19191908, 0x08080808, 0x19191919, 0x0808082b, 0x19191919, 0x08081919, 0x19191919,
    0x08082b08, 0x19191919, 0x08190819, 0x19191919, 0x08191908, 0x19191919, 0x082b0808, 0x19191919,
    0x19080819, 0x19191919, 0x19081908, 0x19191919, 0x19190808, 0x19191919, 0x2b080808, 0x19191919,
    0x08080819, 0x1919192b, 0x08081908, 0x1919192b, 0x08190808, 0x1919192b, 0x082b192b, 0x1919192b,
    0x19080808, 0x1919192b, 0x08080808, 0x19192b08, 0x0808082b, 0x19192b08, 0x08081919, 0x19192b08,
    0x08082b08, 0x19192b08, 0x08190819, 0x19192b08, 0x08191908, 0x19192b08, 0x082b0808, 0x19192b08,
    0x19080819, 0x19192b08, 0x19081908, 0x19192b08, 0x19190808, 0x19192b08, 0x19192b2b, 0x19192b08,
    0x2b080808, 0x19192b08, 0x08080819, 0x19192b19, 0x08081908, 0x19192b19, 0x08190808, 0x19192b19,
    0x19080808, 0x19192b19, 0x08080808, 0x19192b2b, 0x08192b19, 0x19192b2b, 0x2b081919, 0x19192b2b,
    0x2b2b2b08, 0x19192b2b, 0x08080819, 0x192b0808, 0x08081908, 0x192b0808, 0x0808192b, 0x192b0808,
    0x08190808, 0x192b0808, 0x0819082b, 0x192b0808, 0x08191919, 0x192b0808, 0x08192b08, 0x192b0808,
    0x082b0819, 0x192b0808, 0x082b1908, 0x192b0808, 0x19080808, 0x192b0808, 0x19081919, 0x192b0808,
    0x19082b08, 0x192b0808, 0x19190819, 0x192b0808, 0x19191908, 0x192b0808, 0x192b0808, 0x192b0808,
    0x2b081908, 0x192b0808, 0x2b190808, 0x192b0808, 0x08080808, 0x192b0819, 0x0808082b, 0x192b0819,
    0x08081919, 0x192b0819, 0x08082b08, 0x192b0819, 0x08190819, 0x192b0819, 0x08191908, 0x192b0819,
    0x082b0808, 0x192b0819, 0x19080819, 0x192b0819, 0x19081908, 0x192b0819, 0x19190808, 0x192b0819,
    0x2b080808, 0x192b0819, 0x2b192b19, 0x192b0819, 0x08081908, 0x192b082b, 0x08190808, 0x192b082b,
    0x19080808, 0x192b082b, 0x1919192b, 0x192b082b, 0x2b2b0819, 0x192b082b, 0x08080808, 0x192b1908,
    0x08081919, 0x192b1908, 0x08082b08, 0x192b1908, 0x08190819, 0x192b1908, 0x08191908, 0x192b1908,
    0x082b0808, 0x192b1908, 0x19080819, 0x192b1908, 0x19081908, 0x192b1908, 0x19190808, 0x192b1908,
    0x2b080808, 0x192b1908, 0x08080819, 0x192b1919, 0x08081908, 0x192b1919, 0x08190808, 0x192b1919,
    0x19080808, 0x192b1919, 0x19082b2b, 0x192b1919, 0x192b2b08, 0x192b1919, 0x2b19082b, 0x192b1919,
    0x08080808, 0x192b192b, 0x2b191908, 0x192b192b, 0x08080819, 0x192b2b08, 0x08081908, 0x192b2b08,
    0x08190808, 0x192b2b08, 0x192b1919, 0x192b2b08, 0x2b192b08, 0x192b2b08, 0x08080808, 0x192b2b19,
    0x082b2b2b, 0x192b2b19, 0x1908082b, 0x192b2b2b, 0x2b2b0819, 0x192b2b2b, 0x08080808, 0x2b080808,
    0x0808082b, 0x2b080808, 0x08081919, 0x2b080808, 0x08082b08, 0x2b080808, 0x08190819, 0x2b080808,
    0x08191908, 0x2b080808, 0x08192b19, 0x2b080808, 0x082b0808, 0x2b080808, 0x082b1919, 0x2b080808,
    0x19080819, 0x2b080808, 0x19081908, 0x2b080808, 0x19190808, 0x2b080808, 0x1919082b, 0x2b080808,
    0x19191919, 0x2b080808, 0x19192b08, 0x2b080808, 0x192b0819, 0x2b080808, 0x2b080808, 0x2b080808,
    0x2b081919, 0x2b080808, 0x2b190819, 0x2b080808, 0x2b191908, 0x2b080808, 0x08080819, 0x2b080819,
    0x08081908, 0x2b080819, 0x08082b19, 0x2b080819, 0x08190808, 0x2b080819, 0x0819082b, 0x2b080819,
    0x08191919, 0x2b080819, 0x08192b08, 0x2b080819, 0x082b0819, 0x2b080819, 0x082b1908, 0x2b080819,
    0x19080808, 0x2b080819, 0x1908082b, 0x2b080819, 0x19081919, 0x2b080819, 0x19082b08, 0x2b080819,
    0x19190819, 0x2b080819, 0x19191908, 0x2b080819, 0x2b080819, 0x2b080819, 0x2b081908, 0x2b080819,
    0x2b190808, 0x2b080819, 0x2b2b2b19, 0x2b080819, 0x08080808, 0x2b08082b, 0x08081919, 0x2b08082b,
    0x08082b2b, 0x2b08082b, 0x08190819, 0x2b08082b, 0x08191908, 0x2b08082b, 0x19080819, 0x2b08082b,
    0x19081908, 0x2b08082b, 0x19190808, 0x2b08082b, 0x08080819, 0x2b081908, 0x08081908, 0x2b081908,
    0x0808192b, 0x2b081908, 0x08082b19, 0x2b081908, 0x08190808, 0x2b081908, 0x0819082b, 0x2b081908,
    0x08191919, 0x2b081908, 0x08192b08, 0x2b081908, 0x082b0819, 0x2b081908, 0x19080808, 0x2b081908,
    0x1908082b, 0x2b081908, 0x19081919, 0x2b081908, 0x19082b08, 0x2b081908, 0x19190819, 0x2b081908,
    0x19191908, 0x2b081908, 0x192b0808, 0x2b081908, 0x2b080819, 0x2b081908, 0x2b081908, 0x2b081908,
    0x2b190808, 0x2b081908, 0x08080808, 0x2b081919, 0x0808082b, 0x2b081919, 0x08081919, 0x2b081919,
    0x08082b08, 0x2b081919, 0x08190819, 0x2b081919, 0x08191908, 0x2b081919, 0x082b0808, 0x2b081919,
    0x19080819, 0x2b081919, 0x19081908, 0x2b081919, 0x19190808, 0x2b081919, 0x2b080808, 0x2b081919,
    0x2b082b2b, 0x2b081919, 0x08080819, 0x2b08192b, 0x08081908, 0x2b08192b, 0x08190808, 0x2b08192b,
    0x082b2b19, 0x2b08192b, 0x19080808, 0x2b08192b, 0x08080808, 0x2b082b08, 0x08081919, 0x2b082b08,
    0x08190819, 0x2b082b08, 0x08191908, 0x2b082b08, 0x19080819, 0x2b082b08, 0x19081908, 0x2b082b08,
    0x19190808, 0x2b082b08, 0x2b2b082b, 0x2b082b08, 0x08080819, 0x2b082b19, 0x08081908, 0x2b082b19,
    0x19080808, 0x2b082b19, 0x192b1919, 0x2b082b19, 0x082b082b, 0x2b082b2b, 0x19192b08, 0x2b082b2b,
    0x19192b2b, 0x2b082b2b, 0x2b08082b, 0x2b082b2b, 0x2b2b082b, 0x2b082b2b, 0x08080819, 0x2b190808,
    0x08081908, 0x2b190808, 0x08082b19, 0x2b190808, 0x08190808, 0x2b190808, 0x0819082b, 0x2b190808,
    0x08191919, 0x2b190808, 0x08192b08, 0x2b190808, 0x082b1908, 0x2b190808, 0x19080808, 0x2b190808,
    0x1908082b, 0x2b190808, 0x19081919, 0x2b190808, 0x19082b08, 0x2b190808, 0x19190819, 0x2b190808,
    0x19191908, 0x2b190808, 0x192b0808, 0x2b190808, 0x2b080819, 0x2b190808, 0x2b081908, 0x2b190808,
    0x2b190808, 0x2b190808, 0x08080808, 0x2b190819, 0x08081919, 0x2b190819, 0x08190819, 0x2b190819,
    0x08191908, 0x2b190819, 0x19080819, 0x2b190819, 0x19081908, 0x2b190819, 0x19190808, 0x2b190819,
    0x19192b2b, 0x2b190819, 0x08080819, 0x2b19082b, 0x08081908, 0x2b19082b, 0x08190808, 0x2b19082b,
    0x19080808, 0x2b19082b, 0x2b2b192b, 0x2b19082b, 0x08080808, 0x2b191908, 0x0808082b, 0x2b191908,
    0x08081919, 0x2b191908, 0x08082b08, 0x2b191908, 0x08190819, 0x2b191908, 0x08191908, 0x2b191908,
    0x082b0808, 0x2b191908, 0x19080819, 0x2b191908, 0x19081908, 0x2b191908, 0x19190808, 0x2b191908,
    0x2b080808, 0x2b191908, 0x2b19192b, 0x2b191908, 0x08080819, 0x2b191919, 0x08081908, 0x2b191919,
    0x08190808, 0x2b191919, 0x19080808, 0x2b191919, 0x2b192b08, 0x2b191919, 0x2b2b0819, 0x2b191919,
    0x08080808, 0x2b19192b, 0x1908192b, 0x2b19192b, 0x192b1908, 0x2b19192b, 0x08080819, 0x2b192b08,
    0x08081908, 0x2b192b08, 0x08190808, 0x2b192b08, 0x082b192b, 0x2b192b08, 0x19080808, 0x2b192b08,
    0x2b2b2b19, 0x2b192b08, 0x08080808, 0x2b192b19, 0x19082b19, 0x2b192b19, 0x1919082b, 0x2b192b19,
    0x2b190808, 0x2b192b2b, 0x08080808, 0x2b2b0808, 0x08081919, 0x2b2b0808, 0x08082b2b, 0x2b2b0808,
    0x08191908, 0x2b2b0808, 0x082b082b, 0x2b2b0808, 0x082b2b2b, 0x2b2b0808, 0x19080819, 0x2b2b0808,
    0x19081908, 0x2b2b0808, 0x19190808, 0x2b2b0808, 0x2b2b082b, 0x2b2b0808, 0x2b2b2b2b, 0x2b2b0808,
    0x19080808, 0x2b2b0819, 0x192b1919, 0x2b2b0819, 0x0808082b, 0x2b2b082b, 0x08082b2b, 0x2b2b082b,
    0x082b082b, 0x2b2b082b, 0x082b2b08, 0x2b2b082b, 0x082b2b2b, 0x2b2b082b, 0x2b08082b, 0x2b2b082b,
    0x2b082b08, 0x2b2b082b, 0x2b082b2b, 0x2b2b082b, 0x2b2b2b08, 0x2b2b082b, 0x08080819, 0x2b2b1908,
    0x08081908, 0x2b2b1908, 0x08190808, 0x2b2b1908, 0x19080808, 0x2b2b1908, 0x2b082b19, 0x2b2b1908,
    0x2b2b1908, 0x2b2b1908, 0x08080808, 0x2b2b1919, 0x08192b19, 0x2b2b1919, 0x19190819, 0x2b2b192b,
    0x08082b2b, 0x2b2b2b08, 0x082b2b08, 0x2b2b2b08, 0x2b2b082b, 0x2b2b2b08, 0x19191908, 0x2b2b2b19,
    0x2b08192b, 0x2b2b2b19, 0x08082b08, 0x2b2b2b2b, 0x08082b2b, 0x2b2b2b2b, 0x082b0808, 0x2b2b2b2b,
    0x082b082b, 0x2b2b2b2b, 0x082b2b08, 0x2b2b2b2b, 0x2b082b08, 0x2b2b2b2b, 0x2b2b2b2b, 0x2b2b2b2b
);

struct iq2_s {
    d: f16,
    qs: array<f16, 32>,
    qh: array<f16, 4>,
    scales: array<f16, 4>
};

fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block = src0[src0_idx_base + offset];
    let d = f32(block.d);
    var src1_i = src1_idx_base + offset * 256;
    var qs_vals : array<u32, 16>;
    for (var i: u32 = 0; i < 16; i++) {
        qs_vals[i] = bitcast<u32>(vec2(block.qs[i * 2], block.qs[i * 2 + 1]));
    }
    var qh_vals = array<u32, 2>(
        bitcast<u32>(vec2(block.qh[0], block.qh[1])),
        bitcast<u32>(vec2(block.qh[2], block.qh[3]))
    );
    var scale_vals = array<u32, 2>(
        bitcast<u32>(vec2(block.scales[0], block.scales[1])),
        bitcast<u32>(vec2(block.scales[2], block.scales[3]))
    );
    var sum = 0.0;
    for (var ib: u32 = 0; ib < 8; ib ++) {
        let s = get_byte(scale_vals[ib / 4], ib % 4);
        let db = array<f32, 2>(
            d * (0.5 + f32(s & 0xF)) * 0.25,
            d * (0.5 + f32(s >> 4)) * 0.25
        );
        let qs_w = qs_vals[ib];
        for (var l: u32 = 0; l < 4; l++) {
            let qh_b = (get_byte(qh_vals[ib / 4], ib % 4) << (8 - 2 * l)) & 0x300;
            let ig = (get_byte(qs_w, l) | qh_b) * 8;
            let signs = get_byte(qs_vals[ib + 8], l);
            let dl = db[l/2];
            for (var j: u32 = 0; j < 8; j++) {
                let g = get_byte(iq2s_grid[(ig + j) / 4], (ig + j) % 4);
                let m = select(1.0, -1.0, (get_byte(kmask_iq2xs[j / 4], j % 4) & signs) != 0);
                sum += dl * f32(g) * m * src1[src1_i];
                src1_i++;
            }
        }
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<iq2_s>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/256; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_iq3_xxs_f32 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

const kmask_iq2xs : array<u32, 2> = array<u32, 2>(
    0x08040201u, // 1, 2, 4, 8
    0x80402010u  // 16, 32, 64, 128
);

const ksigns_iq2xs: array<u32, 32> = array<u32, 32>(
    0x03828100,0x87060584,0x8b0a0988,0x0f8e8d0c,
    0x93121190,0x17969514,0x1b9a9918,0x9f1e1d9c,
    0xa32221a0,0x27a6a524,0x2baaa928,0xaf2e2dac,
    0x33b2b130,0xb73635b4,0xbb3a39b8,0x3fbebd3c,
    0xc34241c0,0x47c6c544,0x4bcac948,0xcf4e4dcc,
    0x53d2d150,0xd75655d4,0xdb5a59d8,0x5fdedd5c,
    0x63e2e160,0xe76665e4,0xeb6a69e8,0x6feeed6c,
    0xf37271f0,0x77f6f574,0x7bfaf978,0xff7e7dfc
);

const iq3xxs_grid = array<u32, 256>(
    0x04040404, 0x04040414, 0x04040424, 0x04040c0c, 0x04040c1c, 0x04040c3e, 0x04041404, 0x04041414,
    0x04041c0c, 0x04042414, 0x04043e1c, 0x04043e2c, 0x040c040c, 0x040c041c, 0x040c0c04, 0x040c0c14,
    0x040c140c, 0x040c142c, 0x040c1c04, 0x040c1c14, 0x040c240c, 0x040c2c24, 0x040c3e04, 0x04140404,
    0x04140414, 0x04140424, 0x04140c0c, 0x04141404, 0x04141414, 0x04141c0c, 0x04141c1c, 0x04141c3e,
    0x04142c0c, 0x04142c3e, 0x04143e2c, 0x041c040c, 0x041c043e, 0x041c0c04, 0x041c0c14, 0x041c142c,
    0x041c3e04, 0x04240c1c, 0x04241c3e, 0x04242424, 0x04242c3e, 0x04243e1c, 0x04243e2c, 0x042c040c,
    0x042c043e, 0x042c1c14, 0x042c2c14, 0x04341c2c, 0x04343424, 0x043e0c04, 0x043e0c24, 0x043e0c34,
    0x043e241c, 0x043e340c, 0x0c04040c, 0x0c04041c, 0x0c040c04, 0x0c040c14, 0x0c04140c, 0x0c04141c,
    0x0c041c04, 0x0c041c14, 0x0c041c24, 0x0c04243e, 0x0c042c04, 0x0c0c0404, 0x0c0c0414, 0x0c0c0c0c,
    0x0c0c1404, 0x0c0c1414, 0x0c14040c, 0x0c14041c, 0x0c140c04, 0x0c140c14, 0x0c14140c, 0x0c141c04,
    0x0c143e14, 0x0c1c0404, 0x0c1c0414, 0x0c1c1404, 0x0c1c1c0c, 0x0c1c2434, 0x0c1c3434, 0x0c24040c,
    0x0c24042c, 0x0c242c04, 0x0c2c1404, 0x0c2c1424, 0x0c2c2434, 0x0c2c3e0c, 0x0c34042c, 0x0c3e1414,
    0x0c3e2404, 0x14040404, 0x14040414, 0x14040c0c, 0x14040c1c, 0x14041404, 0x14041414, 0x14041434,
    0x14041c0c, 0x14042414, 0x140c040c, 0x140c041c, 0x140c042c, 0x140c0c04, 0x140c0c14, 0x140c140c,
    0x140c1c04, 0x140c341c, 0x140c343e, 0x140c3e04, 0x14140404, 0x14140414, 0x14140c0c, 0x14140c3e,
    0x14141404, 0x14141414, 0x14141c3e, 0x14142404, 0x14142c2c, 0x141c040c, 0x141c0c04, 0x141c0c24,
    0x141c3e04, 0x141c3e24, 0x14241c2c, 0x14242c1c, 0x142c041c, 0x142c143e, 0x142c240c, 0x142c3e24,
    0x143e040c, 0x143e041c, 0x143e0c34, 0x143e242c, 0x1c04040c, 0x1c040c04, 0x1c040c14, 0x1c04140c,
    0x1c04141c, 0x1c042c04, 0x1c04342c, 0x1c043e14, 0x1c0c0404, 0x1c0c0414, 0x1c0c1404, 0x1c0c1c0c,
    0x1c0c2424, 0x1c0c2434, 0x1c14040c, 0x1c14041c, 0x1c140c04, 0x1c14142c, 0x1c142c14, 0x1c143e14,
    0x1c1c0c0c, 0x1c1c1c1c, 0x1c241c04, 0x1c24243e, 0x1c243e14, 0x1c2c0404, 0x1c2c0434, 0x1c2c1414,
    0x1c2c2c2c, 0x1c340c24, 0x1c341c34, 0x1c34341c, 0x1c3e1c1c, 0x1c3e3404, 0x24040424, 0x24040c3e,
    0x24041c2c, 0x24041c3e, 0x24042c1c, 0x24042c3e, 0x240c3e24, 0x24141404, 0x24141c3e, 0x24142404,
    0x24143404, 0x24143434, 0x241c043e, 0x241c242c, 0x24240424, 0x24242c0c, 0x24243424, 0x242c142c,
    0x242c241c, 0x242c3e04, 0x243e042c, 0x243e0c04, 0x243e0c14, 0x243e1c04, 0x2c040c14, 0x2c04240c,
    0x2c043e04, 0x2c0c0404, 0x2c0c0434, 0x2c0c1434, 0x2c0c2c2c, 0x2c140c24, 0x2c141c14, 0x2c143e14,
    0x2c1c0414, 0x2c1c2c1c, 0x2c240c04, 0x2c24141c, 0x2c24143e, 0x2c243e14, 0x2c2c0414, 0x2c2c1c0c,
    0x2c342c04, 0x2c3e1424, 0x2c3e2414, 0x34041424, 0x34042424, 0x34042434, 0x34043424, 0x340c140c,
    0x340c340c, 0x34140c3e, 0x34143424, 0x341c1c04, 0x341c1c34, 0x34242424, 0x342c042c, 0x342c2c14,
    0x34341c1c, 0x343e041c, 0x343e140c, 0x3e04041c, 0x3e04042c, 0x3e04043e, 0x3e040c04, 0x3e041c14,
    0x3e042c14, 0x3e0c1434, 0x3e0c2404, 0x3e140c14, 0x3e14242c, 0x3e142c14, 0x3e1c0404, 0x3e1c0c2c,
    0x3e1c1c1c, 0x3e1c3404, 0x3e24140c, 0x3e24240c, 0x3e2c0404, 0x3e2c0414, 0x3e2c1424, 0x3e341c04
);

struct iq3_xxs {
    d: f16,
    qs: array<f16, 48>
};

fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block = src0[src0_idx_base + offset];
    let d = f32(block.d);
    var src1_i = src1_idx_base + offset * 256;
    var sum = 0.0;
    for (var ib: u32 = 0; ib < 16; ib += 2) {
        let sc_sign = bitcast<u32>(vec2(block.qs[ib + 32], block.qs[ib + 33]));
        let db = d * (0.5 + f32(sc_sign >> 28)) * 0.5;
        for (var l: u32 = 0; l < 4; l++) {
            let is = (sc_sign >> (7 * l)) & 127;
            let signs = get_byte(ksigns_iq2xs[is / 4], is % 4);
            let ig_val = bitcast<u32>(vec2(block.qs[ib * 2 + l], 0.0));
            let ig1 = get_byte(ig_val, 0);
            let ig2 = get_byte(ig_val, 1);
            for (var j: u32 = 0; j < 4; j++) {
                let g1 = get_byte(iq3xxs_grid[ig1], j);
                let g2 = get_byte(iq3xxs_grid[ig2], j);
                let m1 = select(1.0, -1.0, (get_byte(kmask_iq2xs[0], j) & signs) != 0);
                let m2 = select(1.0, -1.0, (get_byte(kmask_iq2xs[1], j) & signs) != 0);
                sum += db * f32(g1) * m1 * src1[src1_i];
                sum += db * f32(g2) * m2 * src1[src1_i + 4];
                src1_i++;
            }
            src1_i += 4;
        }
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<iq3_xxs>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/256; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_iq3_s_f32 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

const kmask_iq2xs : array<u32, 2> = array<u32, 2>(
    0x08040201u, // 1, 2, 4, 8
    0x80402010u  // 16, 32, 64, 128
);

const ksigns_iq2xs: array<u32, 32> = array<u32, 32>(
    0x03828100,0x87060584,0x8b0a0988,0x0f8e8d0c,
    0x93121190,0x17969514,0x1b9a9918,0x9f1e1d9c,
    0xa32221a0,0x27a6a524,0x2baaa928,0xaf2e2dac,
    0x33b2b130,0xb73635b4,0xbb3a39b8,0x3fbebd3c,
    0xc34241c0,0x47c6c544,0x4bcac948,0xcf4e4dcc,
    0x53d2d150,0xd75655d4,0xdb5a59d8,0x5fdedd5c,
    0x63e2e160,0xe76665e4,0xeb6a69e8,0x6feeed6c,
    0xf37271f0,0x77f6f574,0x7bfaf978,0xff7e7dfc
);

const iq3s_grid = array<u32, 512>(
    0x01010101, 0x01010103, 0x01010105, 0x0101010b, 0x0101010f, 0x01010301, 0x01010303, 0x01010305,
    0x01010309, 0x0101030d, 0x01010501, 0x01010503, 0x0101050b, 0x01010707, 0x01010901, 0x01010905,
    0x0101090b, 0x0101090f, 0x01010b03, 0x01010b07, 0x01010d01, 0x01010d05, 0x01010f03, 0x01010f09,
    0x01010f0f, 0x01030101, 0x01030103, 0x01030105, 0x01030109, 0x01030301, 0x01030303, 0x0103030b,
    0x01030501, 0x01030507, 0x0103050f, 0x01030703, 0x0103070b, 0x01030909, 0x01030d03, 0x01030d0b,
    0x01030f05, 0x01050101, 0x01050103, 0x0105010b, 0x0105010f, 0x01050301, 0x01050307, 0x0105030d,
    0x01050503, 0x0105050b, 0x01050701, 0x01050709, 0x01050905, 0x0105090b, 0x0105090f, 0x01050b03,
    0x01050b07, 0x01050f01, 0x01050f07, 0x01070107, 0x01070303, 0x0107030b, 0x01070501, 0x01070505,
    0x01070703, 0x01070707, 0x0107070d, 0x01070909, 0x01070b01, 0x01070b05, 0x01070d0f, 0x01070f03,
    0x01070f0b, 0x01090101, 0x01090307, 0x0109030f, 0x01090503, 0x01090509, 0x01090705, 0x01090901,
    0x01090907, 0x01090b03, 0x01090f01, 0x010b0105, 0x010b0109, 0x010b0501, 0x010b0505, 0x010b050d,
    0x010b0707, 0x010b0903, 0x010b090b, 0x010b090f, 0x010b0d0d, 0x010b0f07, 0x010d010d, 0x010d0303,
    0x010d0307, 0x010d0703, 0x010d0b05, 0x010d0f03, 0x010f0101, 0x010f0105, 0x010f0109, 0x010f0501,
    0x010f0505, 0x010f050d, 0x010f0707, 0x010f0b01, 0x010f0b09, 0x03010101, 0x03010103, 0x03010105,
    0x03010109, 0x03010301, 0x03010303, 0x03010307, 0x0301030b, 0x0301030f, 0x03010501, 0x03010505,
    0x03010703, 0x03010709, 0x0301070d, 0x03010b09, 0x03010b0d, 0x03010d03, 0x03010f05, 0x03030101,
    0x03030103, 0x03030107, 0x0303010d, 0x03030301, 0x03030309, 0x03030503, 0x03030701, 0x03030707,
    0x03030903, 0x03030b01, 0x03030b05, 0x03030f01, 0x03030f0d, 0x03050101, 0x03050305, 0x0305030b,
    0x0305030f, 0x03050501, 0x03050509, 0x03050705, 0x03050901, 0x03050907, 0x03050b0b, 0x03050d01,
    0x03050f05, 0x03070103, 0x03070109, 0x0307010f, 0x03070301, 0x03070307, 0x03070503, 0x0307050f,
    0x03070701, 0x03070709, 0x03070903, 0x03070d05, 0x03070f01, 0x03090107, 0x0309010b, 0x03090305,
    0x03090309, 0x03090703, 0x03090707, 0x03090905, 0x0309090d, 0x03090b01, 0x03090b09, 0x030b0103,
    0x030b0301, 0x030b0307, 0x030b0503, 0x030b0701, 0x030b0705, 0x030b0b03, 0x030d0501, 0x030d0509,
    0x030d050f, 0x030d0909, 0x030d090d, 0x030f0103, 0x030f0107, 0x030f0301, 0x030f0305, 0x030f0503,
    0x030f070b, 0x030f0903, 0x030f0d05, 0x030f0f01, 0x05010101, 0x05010103, 0x05010107, 0x0501010b,
    0x0501010f, 0x05010301, 0x05010305, 0x05010309, 0x0501030d, 0x05010503, 0x05010507, 0x0501050f,
    0x05010701, 0x05010705, 0x05010903, 0x05010907, 0x0501090b, 0x05010b01, 0x05010b05, 0x05010d0f,
    0x05010f01, 0x05010f07, 0x05010f0b, 0x05030101, 0x05030105, 0x05030301, 0x05030307, 0x0503030f,
    0x05030505, 0x0503050b, 0x05030703, 0x05030709, 0x05030905, 0x05030b03, 0x05050103, 0x05050109,
    0x0505010f, 0x05050503, 0x05050507, 0x05050701, 0x0505070f, 0x05050903, 0x05050b07, 0x05050b0f,
    0x05050f03, 0x05050f09, 0x05070101, 0x05070105, 0x0507010b, 0x05070303, 0x05070505, 0x05070509,
    0x05070703, 0x05070707, 0x05070905, 0x05070b01, 0x05070d0d, 0x05090103, 0x0509010f, 0x05090501,
    0x05090507, 0x05090705, 0x0509070b, 0x05090903, 0x05090f05, 0x05090f0b, 0x050b0109, 0x050b0303,
    0x050b0505, 0x050b070f, 0x050b0901, 0x050b0b07, 0x050b0f01, 0x050d0101, 0x050d0105, 0x050d010f,
    0x050d0503, 0x050d0b0b, 0x050d0d03, 0x050f010b, 0x050f0303, 0x050f050d, 0x050f0701, 0x050f0907,
    0x050f0b01, 0x07010105, 0x07010303, 0x07010307, 0x0701030b, 0x0701030f, 0x07010505, 0x07010703,
    0x07010707, 0x0701070b, 0x07010905, 0x07010909, 0x0701090f, 0x07010b03, 0x07010d07, 0x07010f03,
    0x07030103, 0x07030107, 0x0703010b, 0x07030309, 0x07030503, 0x07030507, 0x07030901, 0x07030d01,
    0x07030f05, 0x07030f0d, 0x07050101, 0x07050305, 0x07050501, 0x07050705, 0x07050709, 0x07050b01,
    0x07070103, 0x07070301, 0x07070309, 0x07070503, 0x07070507, 0x0707050f, 0x07070701, 0x07070903,
    0x07070907, 0x0707090f, 0x07070b0b, 0x07070f07, 0x07090107, 0x07090303, 0x0709030d, 0x07090505,
    0x07090703, 0x07090b05, 0x07090d01, 0x07090d09, 0x070b0103, 0x070b0301, 0x070b0305, 0x070b050b,
    0x070b0705, 0x070b0909, 0x070b0b0d, 0x070b0f07, 0x070d030d, 0x070d0903, 0x070f0103, 0x070f0107,
    0x070f0501, 0x070f0505, 0x070f070b, 0x09010101, 0x09010109, 0x09010305, 0x09010501, 0x09010509,
    0x0901050f, 0x09010705, 0x09010903, 0x09010b01, 0x09010f01, 0x09030105, 0x0903010f, 0x09030303,
    0x09030307, 0x09030505, 0x09030701, 0x0903070b, 0x09030907, 0x09030b03, 0x09030b0b, 0x09050103,
    0x09050107, 0x09050301, 0x0905030b, 0x09050503, 0x09050707, 0x09050901, 0x09050b0f, 0x09050d05,
    0x09050f01, 0x09070109, 0x09070303, 0x09070307, 0x09070501, 0x09070505, 0x09070703, 0x0907070b,
    0x09090101, 0x09090105, 0x09090509, 0x0909070f, 0x09090901, 0x09090f03, 0x090b010b, 0x090b010f,
    0x090b0503, 0x090b0d05, 0x090d0307, 0x090d0709, 0x090d0d01, 0x090f0301, 0x090f030b, 0x090f0701,
    0x090f0907, 0x090f0b03, 0x0b010105, 0x0b010301, 0x0b010309, 0x0b010505, 0x0b010901, 0x0b010909,
    0x0b01090f, 0x0b010b05, 0x0b010d0d, 0x0b010f09, 0x0b030103, 0x0b030107, 0x0b03010b, 0x0b030305,
    0x0b030503, 0x0b030705, 0x0b030f05, 0x0b050101, 0x0b050303, 0x0b050507, 0x0b050701, 0x0b05070d,
    0x0b050b07, 0x0b070105, 0x0b07010f, 0x0b070301, 0x0b07050f, 0x0b070909, 0x0b070b03, 0x0b070d0b,
    0x0b070f07, 0x0b090103, 0x0b090109, 0x0b090501, 0x0b090705, 0x0b09090d, 0x0b0b0305, 0x0b0b050d,
    0x0b0b0b03, 0x0b0b0b07, 0x0b0d0905, 0x0b0f0105, 0x0b0f0109, 0x0b0f0505, 0x0d010303, 0x0d010307,
    0x0d01030b, 0x0d010703, 0x0d010707, 0x0d010d01, 0x0d030101, 0x0d030501, 0x0d03050f, 0x0d030d09,
    0x0d050305, 0x0d050709, 0x0d050905, 0x0d050b0b, 0x0d050d05, 0x0d050f01, 0x0d070101, 0x0d070309,
    0x0d070503, 0x0d070901, 0x0d09050b, 0x0d090907, 0x0d090d05, 0x0d0b0101, 0x0d0b0107, 0x0d0b0709,
    0x0d0b0d01, 0x0d0d010b, 0x0d0d0901, 0x0d0f0303, 0x0d0f0307, 0x0f010101, 0x0f010109, 0x0f01010f,
    0x0f010501, 0x0f010505, 0x0f01070d, 0x0f010901, 0x0f010b09, 0x0f010d05, 0x0f030105, 0x0f030303,
    0x0f030509, 0x0f030907, 0x0f03090b, 0x0f050103, 0x0f050109, 0x0f050301, 0x0f05030d, 0x0f050503,
    0x0f050701, 0x0f050b03, 0x0f070105, 0x0f070705, 0x0f07070b, 0x0f070b07, 0x0f090103, 0x0f09010b,
    0x0f090307, 0x0f090501, 0x0f090b01, 0x0f0b0505, 0x0f0b0905, 0x0f0d0105, 0x0f0d0703, 0x0f0f0101
);

struct iq3_s {
    d: f16,
    qs: array<f16, 32>,
    qh: array<f16, 4>,
    signs: array<f16, 16>,
    scales: array<f16, 2>
};

fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block = src0[src0_idx_base + offset];
    let d = f32(block.d);
    var src1_i = src1_idx_base + offset * 256;
    var qh_vals = array<u32, 2>(
        bitcast<u32>(vec2(block.qh[0], block.qh[1])),
        bitcast<u32>(vec2(block.qh[2], block.qh[3]))
    );
    var sign_vals: array<u32, 8>;
    for (var i: u32 = 0; i < 8; i++) {
        sign_vals[i] = bitcast<u32>(vec2(block.signs[i * 2], block.signs[i * 2 + 1]));
    }
    var scale_vals = bitcast<u32>(vec2(block.scales[0], block.scales[1]));
    var sum = 0.0;
    for (var ib: u32 = 0; ib < 4; ib++) {
        let s = get_byte(scale_vals, ib);
        let db = array<f32, 2>(
            d * (1.0 + 2.0 * f32(s & 0xF)),
            d * (1.0 + 2.0 * f32(s >> 4))
        );
        for (var k: u32 = 0; k < 2; k++) {
            let dl = db[k];
            let qh_byte = get_byte(qh_vals[ib / 2], (ib % 2) * 2 + k);
            let sign_w = sign_vals[ib * 2 + k];
            for (var l: u32 = 0; l < 4; l++) {
                let signs = get_byte(sign_w, l);
                let ig_val = bitcast<u32>(vec2(block.qs[ib * 8 + k * 4 + l], 0.0));
                let ig1 = get_byte(ig_val, 0) | ((qh_byte << ((8 - (2 * l)))) & 256);
                let ig2 = get_byte(ig_val, 1) | ((qh_byte << ((7 - (2 * l)))) & 256);
                for (var j: u32 = 0; j < 4; j++) {
                    let g1 = get_byte(iq3s_grid[ig1], j);
                    let g2 = get_byte(iq3s_grid[ig2], j);
                    let m1 = select(1.0, -1.0, (get_byte(kmask_iq2xs[0], j) & signs) != 0);
                    let m2 = select(1.0, -1.0, (get_byte(kmask_iq2xs[1], j) & signs) != 0);
                    sum += dl * f32(g1) * m1 * src1[src1_i];
                    sum += dl * f32(g2) * m2 * src1[src1_i + 4];
                    src1_i++;
                }
                src1_i += 4;
            }
        }
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<iq3_s>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/256; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_iq1_s_f32 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

const IQ1_DELTA: f32 = 0.125;

const iq1_grid = array<u32, 1024>(
    0xfffdffff, 0xfff7fff0, 0xffccfff5, 0xffdfffc0, 0xffd7ffdd, 0xff30ffd5, 0xff03ff0c, 0xff10ff01,
    0xff7dff7f, 0xff75ff77, 0xff5fff40, 0xff57ff5d, 0xfcf3ff55, 0xfcccfcf0, 0xfcc1fcc3, 0xfcc5fcc4,
    0xfc3cfcd0, 0xfc34fc31, 0xfc00fc0d, 0xfc1cfc05, 0xfc11fc13, 0xfc70fc17, 0xfc43fc4c, 0xfc50fc41,
    0xfdfdfdff, 0xfdf5fdf7, 0xfddffdc0, 0xfdd7fddd, 0xfd30fdd5, 0xfd04fd0c, 0xfd14fd13, 0xfd7dfd7f,
    0xfd75fd77, 0xfd40fd4c, 0xfd5ffd44, 0xfd57fd5d, 0xf3ccfd55, 0xf3c1f3c3, 0xf33cf3d0, 0xf300f334,
    0xf313f305, 0xf34cf310, 0xf350f344, 0xf0f3f0fc, 0xf0f1f0f0, 0xf0c7f0c0, 0xf0d4f0c5, 0xf030f03f,
    0xf00ff035, 0xf003f00c, 0xf001f000, 0xf01ff004, 0xf010f01d, 0xf015f017, 0xf04cf07c, 0xf047f040,
    0xf05cf045, 0xf050f053, 0xf054f051, 0xf1c4f1c3, 0xf133f13c, 0xf10df10f, 0xf107f100, 0xf11cf11f,
    0xf114f111, 0xf14cf170, 0xf144f143, 0xf7fdf7ff, 0xf7f5f7f7, 0xf7dff7c0, 0xf7d7f7dd, 0xf730f7d5,
    0xf701f70c, 0xf77ff710, 0xf777f77d, 0xf740f775, 0xf75df75f, 0xf755f757, 0xf4ccf4f0, 0xf4c4f4c3,
    0xf4d0f4d3, 0xf40ff43c, 0xf400f40c, 0xf413f41c, 0xf44cf414, 0xf441f443, 0xf450f444, 0xf5fdf5ff,
    0xf5f5f5f7, 0xf5dff5c0, 0xf5d7f5dd, 0xf530f5d5, 0xf504f50c, 0xf510f51c, 0xf57df57f, 0xf577f570,
    0xf540f575, 0xf55df55f, 0xf555f557, 0xcfcccfcf, 0xcfc4cfc3, 0xcfd0cfd3, 0xcf33cf3c, 0xcf00cf0f,
    0xcf1ccf07, 0xcf10cf13, 0xcf4ccf14, 0xcf41cf43, 0xcf50cf5c, 0xccf3ccfc, 0xccf4ccf1, 0xcccdcccf,
    0xccc7ccc0, 0xccd3ccdc, 0xcc30ccd4, 0xcc0fcc35, 0xcc0dcc0c, 0xcc00cc03, 0xcc04cc01, 0xcc10cc1f,
    0xcc4dcc73, 0xcc5ccc40, 0xcdcccc53, 0xcdc1cdc3, 0xcd3fcdd0, 0xcd34cd31, 0xcd00cd0d, 0xcd05cd07,
    0xcd11cd13, 0xcd4ccd70, 0xcd41cd43, 0xc3fccd50, 0xc3f4c3f1, 0xc3c0c3c3, 0xc3c4c3c7, 0xc3d1c3dc,
    0xc330c33c, 0xc337c331, 0xc30cc335, 0xc300c303, 0xc304c301, 0xc310c31d, 0xc373c317, 0xc34fc374,
    0xc340c343, 0xc344c347, 0xc35cc345, 0xc350c353, 0xc0fdc354, 0xc0f5c0f0, 0xc0c3c0cc, 0xc0c1c0c0,
    0xc0dfc0c4, 0xc0d0c0dd, 0xc0d5c0d7, 0xc033c03c, 0xc031c030, 0xc00dc00c, 0xc000c003, 0xc004c001,
    0xc01cc005, 0xc010c013, 0xc014c011, 0xc07dc07f, 0xc070c073, 0xc075c077, 0xc04cc04f, 0xc040c043,
    0xc044c041, 0xc05fc045, 0xc050c05d, 0xc1f3c1fc, 0xc1f1c1f0, 0xc1c1c1c0, 0xc1c5c1c7, 0xc1d1c1dc,
    0xc13dc13f, 0xc130c133, 0xc135c137, 0xc100c10c, 0xc107c101, 0xc11cc104, 0xc110c113, 0xc114c117,
    0xc171c115, 0xc14dc175, 0xc153c140, 0xc7ccc154, 0xc7d0c7c1, 0xc733c73c, 0xc734c731, 0xc700c70f,
    0xc705c707, 0xc71cc71f, 0xc711c713, 0xc770c714, 0xc743c74c, 0xc4cfc750, 0xc4c0c4cd, 0xc4dcc4c5,
    0xc43dc4d0, 0xc430c433, 0xc40cc437, 0xc400c403, 0xc404c401, 0xc41fc405, 0xc415c410, 0xc44cc474,
    0xc440c44d, 0xc45cc447, 0xc454c451, 0xc5c1c5f4, 0xc5d1c5d3, 0xc531c533, 0xc50fc534, 0xc500c50d,
    0xc51cc507, 0xc514c511, 0xc54cc570, 0xc545c541, 0xdffddfff, 0xdff5dff7, 0xdfdfdfc0, 0xdfd0dfdd,
    0xdfd5dfd7, 0xdf0cdf30, 0xdf1cdf04, 0xdf7fdf10, 0xdf77df7d, 0xdf40df75, 0xdf5ddf5f, 0xdf57df50,
    0xdcf0df55, 0xdcc3dccc, 0xdcd0dcc4, 0xdc33dc3d, 0xdc00dc34, 0xdc05dc07, 0xdc13dc1c, 0xdc11dc10,
    0xdc4fdc70, 0xdc44dc41, 0xddfcdc50, 0xddf5ddf7, 0xddc0ddcc, 0xdddddddf, 0xddd5ddd7, 0xdd0cdd30,
    0xdd04dd01, 0xdd7cdd10, 0xdd75dd77, 0xdd40dd4c, 0xdd5ddd5f, 0xdd55dd57, 0xd3c3d3f0, 0xd3c4d3c1,
    0xd333d3d0, 0xd331d330, 0xd30dd334, 0xd307d300, 0xd311d305, 0xd34cd370, 0xd344d343, 0xd350d35c,
    0xd0c0d0f4, 0xd0d4d0dc, 0xd030d03f, 0xd00cd037, 0xd000d003, 0xd01dd004, 0xd017d010, 0xd04fd074,
    0xd040d043, 0xd045d047, 0xd053d05c, 0xd054d051, 0xd1cfd1f0, 0xd1c4d1cd, 0xd13cd1d0, 0xd100d134,
    0xd11cd11f, 0xd173d114, 0xd14fd171, 0xd7ffd145, 0xd7f7d7fd, 0xd7c0d7f5, 0xd7ddd7df, 0xd7d5d7d7,
    0xd70cd730, 0xd710d703, 0xd77dd77f, 0xd775d777, 0xd75dd75f, 0xd755d757, 0xd4ccd4f4, 0xd4c4d4c3,
    0xd431d4d0, 0xd40dd434, 0xd41cd400, 0xd411d413, 0xd470d414, 0xd441d44f, 0xd453d444, 0xd5ffd450,
    0xd5f7d5fd, 0xd5dfd5f5, 0xd5d7d5dd, 0xd530d5d5, 0xd501d50c, 0xd510d504, 0xd57dd57f, 0xd575d577,
    0xd55fd540, 0xd557d55d, 0x3ff0d555, 0x3fc13fcc, 0x3f343fd0, 0x3f003f0d, 0x3f053f07, 0x3f133f1c,
    0x3f433f11, 0x3f5c3f44, 0x3cff3f51, 0x3cf33cfc, 0x3cf43cf1, 0x3cc03ccd, 0x3cc73cc1, 0x3cdc3cc5,
    0x3cd43cd1, 0x3c373c30, 0x3c0c3c35, 0x3c003c03, 0x3c043c01, 0x3c103c05, 0x3c153c17, 0x3c733c7c,
    0x3c4f3c71, 0x3c403c4d, 0x3c5c3c5f, 0x3df03c5d, 0x3dc33dcc, 0x3dd03dc1, 0x3d0d3d3c, 0x3d053d00,
    0x3d143d13, 0x3d433d74, 0x33fc3d50, 0x33c433c0, 0x333033d4, 0x33353337, 0x3303330c, 0x33013300,
    0x331d331c, 0x33173310, 0x337c3315, 0x33743371, 0x334d334f, 0x335f3340, 0x3354335c, 0x30fd30fc,
    0x30f530f0, 0x30c330cc, 0x30c130c0, 0x30df30c4, 0x30d530d0, 0x3033303c, 0x30313030, 0x300f3034,
    0x3003300c, 0x30013000, 0x30043007, 0x3013301c, 0x30113010, 0x307d3014, 0x30703073, 0x304c3077,
    0x30403043, 0x30443041, 0x30503045, 0x30553057, 0x31f031fc, 0x31c331f4, 0x31c731c0, 0x31dc31c5,
    0x31d431d3, 0x313d313f, 0x31373130, 0x310c310f, 0x3100310d, 0x31043101, 0x3110311d, 0x317c3117,
    0x31753170, 0x31403143, 0x3153315c, 0x37f03151, 0x37c037cc, 0x37d037c5, 0x3734373d, 0x3700370f,
    0x371c3707, 0x37113713, 0x37703714, 0x3743374c, 0x37443741, 0x34fc3750, 0x34f134f0, 0x34cf34f5,
    0x34c034c3, 0x34dc34c7, 0x34d134d3, 0x3430343f, 0x340c3435, 0x3403340d, 0x34013400, 0x341f3404,
    0x3410341d, 0x34153411, 0x34743471, 0x3440344d, 0x34473441, 0x3453345c, 0x34543451, 0x353335c1,
    0x35343531, 0x35073500, 0x35133505, 0x35433514, 0x0ffc3550, 0x0ff00ff3, 0x0ff40ff1, 0x0fc00fcd,
    0x0fdc0fc5, 0x0fd40fd3, 0x0f300f3f, 0x0f0c0f37, 0x0f000f03, 0x0f040f01, 0x0f170f10, 0x0f740f71,
    0x0f470f40, 0x0f5c0f5f, 0x0f540f51, 0x0cf70cf0, 0x0cf50cf4, 0x0cc30ccc, 0x0cc10cc0, 0x0cc40cc7,
    0x0cd00cdf, 0x0cd70cd1, 0x0c3c0cd5, 0x0c300c33, 0x0c340c31, 0x0c0c0c0f, 0x0c030c0d, 0x0c010c00,
    0x0c040c07, 0x0c1c0c05, 0x0c100c13, 0x0c140c11, 0x0c700c7d, 0x0c430c4c, 0x0c410c40, 0x0c5f0c44,
    0x0c550c50, 0x0df10dfc, 0x0dc00dcd, 0x0ddc0dc5, 0x0d3d0dd3, 0x0d350d30, 0x0d030d0c, 0x0d010d00,
    0x0d1d0d04, 0x0d700d10, 0x0d4d0d4f, 0x0d440d40, 0x0d530d45, 0x03f003f3, 0x03c303cc, 0x03c103c0,
    0x03c403c7, 0x03d003dc, 0x03d503d7, 0x0333033c, 0x03310330, 0x03350334, 0x030c030f, 0x03000303,
    0x03070301, 0x03050304, 0x031d031c, 0x03100313, 0x03140311, 0x0377037f, 0x034c0375, 0x03400343,
    0x03440341, 0x0353035c, 0x03550350, 0x00fd00fc, 0x00f000f3, 0x00f400f1, 0x00cc00cf, 0x00c300cd,
    0x00c100c0, 0x00c500c4, 0x00d300dc, 0x00d100d0, 0x003f00d4, 0x003d003c, 0x00300033, 0x00370031,
    0x000f0034, 0x000d000c, 0x00000003, 0x00070001, 0x00050004, 0x001c001f, 0x00100013, 0x00170011,
    0x00150014, 0x0073007c, 0x00740070, 0x004f0075, 0x0043004c, 0x00410040, 0x00440047, 0x0053005c,
    0x00510050, 0x01ff0054, 0x01fd01fc, 0x01f101f3, 0x01f401f7, 0x01c301cc, 0x01c701c0, 0x01df01c4,
    0x01dd01dc, 0x01d001d3, 0x01d701d1, 0x013c01d4, 0x01310130, 0x01340137, 0x010f0135, 0x010d010c,
    0x01000103, 0x01070101, 0x01050104, 0x0113011c, 0x01140110, 0x0170017d, 0x01770171, 0x01750174,
    0x0140014c, 0x015d0145, 0x01510150, 0x01540157, 0x07f007f3, 0x07f407f1, 0x07c007cf, 0x07dc07c7,
    0x073007d5, 0x07350737, 0x0703070c, 0x07010700, 0x07040707, 0x071d071f, 0x07100713, 0x0774077d,
    0x074d074f, 0x07470740, 0x0754075c, 0x04fd04fc, 0x04f504f0, 0x04c304cc, 0x04c104c0, 0x04d004c4,
    0x0433043c, 0x04310430, 0x040f0434, 0x040d040c, 0x04000403, 0x04070401, 0x04050404, 0x0413041c,
    0x04110410, 0x047c0414, 0x04740470, 0x0443044c, 0x04410440, 0x04440447, 0x05f30450, 0x05c005f7,
    0x05df05c5, 0x05d105d0, 0x053005d4, 0x05340537, 0x0500050c, 0x05070501, 0x051d0504, 0x05170510,
    0x057c0515, 0x054d0575, 0x05410540, 0x05450547, 0x1ff0055c, 0x1fc11fc3, 0x1fd01fc4, 0x1f0f1f33,
    0x1f011f00, 0x1f051f07, 0x1f131f1c, 0x1f141f11, 0x1f411f7c, 0x1cfc1f50, 0x1cf11cf3, 0x1ccd1cf4,
    0x1cdc1cc0, 0x1cd11cdd, 0x1c301cd4, 0x1c0c1c34, 0x1c011c00, 0x1c101c04, 0x1c151c11, 0x1c751c73,
    0x1c401c4d, 0x1c511c5c, 0x1dcc1c54, 0x1dc41dc1, 0x1d3c1d3f, 0x1d001d31, 0x1d071d01, 0x1d701d1f,
    0x1d411d4c, 0x13cc1d50, 0x13c013cd, 0x13c513c1, 0x13d113dc, 0x133f13d4, 0x1330133d, 0x13351337,
    0x1303130c, 0x13011300, 0x13051304, 0x131d131f, 0x13731310, 0x13741370, 0x134d134f, 0x13401343,
    0x13471341, 0x135c1345, 0x13541353, 0x10f710f0, 0x10cc10f5, 0x10c110c0, 0x103310c4, 0x10311030,
    0x100f1034, 0x1003100c, 0x10011000, 0x101c1004, 0x10101013, 0x10141011, 0x10741071, 0x104c1075,
    0x10411040, 0x10451044, 0x1050105d, 0x10571051, 0x11f411fd, 0x11df11c0, 0x11d711d1, 0x113f11d4,
    0x11371130, 0x110c1135, 0x11001103, 0x11071101, 0x111f1105, 0x11171110, 0x117d117f, 0x11751170,
    0x11411143, 0x11441147, 0x1153115f, 0x11551151, 0x17c417c1, 0x173c17d0, 0x1700170d, 0x171c1705,
    0x17701714, 0x1747174c, 0x14fc1751, 0x14cf14f3, 0x14dc14c0, 0x14d114d3, 0x143f14d4, 0x1430143c,
    0x14371431, 0x1403140c, 0x14011400, 0x141f1404, 0x14151410, 0x1473147d, 0x14401475, 0x1453145c,
    0x14541450, 0x15c115cc, 0x153c15c7, 0x15341533, 0x1500150f, 0x15051507, 0x15101513, 0x15711514,
    0x15471543, 0x15511545, 0x7ffd7fff, 0x7ff57ff7, 0x7fdd7fdf, 0x7fd57fd7, 0x7f0f7f30, 0x7f037f0c,
    0x7f047f01, 0x7f7f7f10, 0x7f777f7d, 0x7f407f75, 0x7f5d7f5f, 0x7f557f57, 0x7ccc7cf0, 0x7cc17cc3,
    0x7cd07cc4, 0x7c337c3c, 0x7c0f7c34, 0x7c007c0d, 0x7c077c01, 0x7c137c04, 0x7c147c11, 0x7c747c70,
    0x7c417c43, 0x7c507c44, 0x7dfd7dff, 0x7df57df7, 0x7ddf7dc0, 0x7dd77ddd, 0x7d0c7dd5, 0x7d047d03,
    0x7d7f7d10, 0x7d777d7d, 0x7d407d75, 0x7d5d7d5f, 0x7d557d57, 0x73c473c3, 0x7333733c, 0x7300730c,
    0x731c7305, 0x73147313, 0x73447343, 0x70f470fc, 0x70c070cd, 0x70d170c5, 0x703f70d4, 0x7030703c,
    0x700c7037, 0x70007003, 0x70047001, 0x70107005, 0x70177011, 0x707c7015, 0x70717073, 0x704f7074,
    0x7040704d, 0x70517047, 0x71c171cc, 0x71d071c4, 0x7133713c, 0x71357134, 0x7100710f, 0x71057104,
    0x7111711c, 0x71707115, 0x7145714c, 0x77ff7153, 0x77f777fd, 0x77c077f5, 0x77dd77df, 0x77d577d7,
    0x7730773c, 0x7703770c, 0x77107704, 0x777f7714, 0x7777777d, 0x77407775, 0x775d775f, 0x77557757,
    0x74f174f0, 0x74c374cc, 0x74d074c1, 0x7433743c, 0x74347431, 0x740d740f, 0x74057400, 0x7413741c,
    0x74417470, 0x74507444, 0x75fd75ff, 0x75f575f7, 0x75df75c0, 0x75d775dd, 0x753075d5, 0x7503750c,
    0x757f7501, 0x7577757d, 0x75407575, 0x755d755f, 0x75557557, 0x4fcc4ff0, 0x4fc74fc1, 0x4fd04fc4,
    0x4f314f3c, 0x4f004f34, 0x4f054f07, 0x4f154f14, 0x4f4c4f70, 0x4f414f43, 0x4f504f44, 0x4cf34cfc,
    0x4cf44cf1, 0x4cc04ccf, 0x4cc54cc7, 0x4cd34cdc, 0x4cd44cd1, 0x4c304c3f, 0x4c0c4c0f, 0x4c004c03,
    0x4c044c01, 0x4c104c1d, 0x4c714c73, 0x4c404c4d, 0x4c5c4c47, 0x4c514c53, 0x4df04c54, 0x4dc34dcc,
    0x4dd04dc4, 0x4d314d33, 0x4d0f4d34, 0x4d004d0d, 0x4d114d07, 0x4d704d14, 0x4d414d43, 0x43fc4d54,
    0x43f143f3, 0x43c043cf, 0x43d143c7, 0x4335433f, 0x4303430c, 0x43014300, 0x43044307, 0x431c431f,
    0x4310431d, 0x43714373, 0x4343434d, 0x43474340, 0x4354435c, 0x40f040ff, 0x40f540f7, 0x40cc40cf,
    0x40c040c3, 0x40c440c1, 0x40d040dc, 0x40d540d4, 0x4033403c, 0x40314030, 0x400f4034, 0x400d400c,
    0x40004003, 0x40074001, 0x40054004, 0x4013401c, 0x40114010, 0x407c4014, 0x40774070, 0x404d404c,
    0x40404043, 0x40444041, 0x405f4045, 0x4050405d, 0x40554057, 0x41f341fc, 0x41c041cf, 0x41df41c4,
    0x41d441d1, 0x41374130, 0x410c4134, 0x4100410d, 0x41044101, 0x41174110, 0x4173417d, 0x41754174,
    0x4143414d, 0x41534140, 0x41544151, 0x47c147f0, 0x47d047c4, 0x4731473c, 0x470d470f, 0x47014700,
    0x47134705, 0x47704710, 0x4741474c, 0x47504744, 0x44f144f3, 0x44cf44f4, 0x44c044cd, 0x44c544c7,
    0x44dc44df, 0x44d144d3, 0x443d443f, 0x44374430, 0x440c4435, 0x44004403, 0x44044401, 0x4410441d,
    0x44154411, 0x4473447c, 0x444d444f, 0x44454440, 0x4451445c, 0x45c045f0, 0x453345d0, 0x45344531,
    0x4500450f, 0x451c4507, 0x454c4570, 0x45404543, 0x5fff4541, 0x5ff75ffd, 0x5fc05ff5, 0x5fdd5fdf,
    0x5fd55fd7, 0x5f0c5f30, 0x5f015f03, 0x5f7f5f04, 0x5f775f7d, 0x5f405f75, 0x5f5d5f5f, 0x5f555f57,
    0x5cf45cf0, 0x5cc35ccc, 0x5cc45cc1, 0x5c315cc5, 0x5c0c5c34, 0x5c075c00, 0x5c1c5c05, 0x5c705c13,
    0x5c4d5c4f, 0x5c445c41, 0x5df75dfd, 0x5dcf5df5, 0x5ddd5dc4, 0x5dd55dd7, 0x5d0c5d30, 0x5d045d01,
    0x5d7f5d10, 0x5d775d7d, 0x5d405d75, 0x5d5d5d5f, 0x5d555d57, 0x53d053c4, 0x5333533c, 0x5303530f,
    0x53075300, 0x531c5305, 0x53115310, 0x53145317, 0x50f15370, 0x50cf50f4, 0x50c050cd, 0x50d150c7,
    0x503d50d4, 0x500c5030, 0x50005003, 0x50045001, 0x50155010, 0x5073507c, 0x50715070, 0x504d5074,
    0x50475040, 0x51cc51f0, 0x51c551c1, 0x51d051dc, 0x51315133, 0x510d5135, 0x51015100, 0x511f5107,
    0x5171511d, 0x5140514f, 0x51445141, 0x5153515c, 0x57ff5151, 0x57f757fd, 0x57df57f5, 0x57d757dd,
    0x570c57d5, 0x57015703, 0x577f5704, 0x5777577d, 0x57405775, 0x575d575f, 0x57555757, 0x54c354f0,
    0x54dc54c4, 0x543c54d0, 0x5400540f, 0x541c5405, 0x54145411, 0x5441544f, 0x55fd55ff, 0x55f555f7,
    0x55dd55df, 0x55d555d7, 0x5503550c, 0x557f5501, 0x5577557d, 0x55405575, 0x555d555f, 0x55555557
);

struct iq1_s {
    d: f16,
    qs: array<f16, 16>,
    qh: array<f16, 8>
};

fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block = src0[src0_idx_base + offset];
    let d = f32(block.d);
    var src1_i = src1_idx_base + offset * 256;
    var sum = 0.0;
    for (var ib: u32 = 0; ib < 8; ib++) {
        let qh = bitcast<u32>(vec2(block.qh[ib], 0.0));
        let dl = d * (2 * f32((qh >> 12) & 7) + 1);
        let delta = select(IQ1_DELTA, -IQ1_DELTA, (qh & 0x8000) != 0);
        let qs_w = bitcast<u32>(vec2(block.qs[ib * 2], block.qs[ib * 2 + 1]));
        for (var l: u32 = 0; l < 4; l++) {
            let ig = (get_byte(qs_w, l) | (((qh >> (3 * l)) & 7) << 8)) * 8;
            for (var j: u32 = 0; j < 8; j++) {
                let gw = iq1_grid[(ig + j) / 16];
                let g = (gw >> (((ig + j) % 16) * 2)) & 3;
                let gs = bitcast<i32>(g << 30) >> 30;
                sum += dl * (f32(gs) + delta) * src1[src1_i];
                src1_i++;
            }
        }
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<iq1_s>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/256; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_iq1_m_f32 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

const IQ1_DELTA: f32 = 0.125;

const iq1_grid = array<u32, 1024>(
    0xfffdffff, 0xfff7fff0, 0xffccfff5, 0xffdfffc0, 0xffd7ffdd, 0xff30ffd5, 0xff03ff0c, 0xff10ff01,
    0xff7dff7f, 0xff75ff77, 0xff5fff40, 0xff57ff5d, 0xfcf3ff55, 0xfcccfcf0, 0xfcc1fcc3, 0xfcc5fcc4,
    0xfc3cfcd0, 0xfc34fc31, 0xfc00fc0d, 0xfc1cfc05, 0xfc11fc13, 0xfc70fc17, 0xfc43fc4c, 0xfc50fc41,
    0xfdfdfdff, 0xfdf5fdf7, 0xfddffdc0, 0xfdd7fddd, 0xfd30fdd5, 0xfd04fd0c, 0xfd14fd13, 0xfd7dfd7f,
    0xfd75fd77, 0xfd40fd4c, 0xfd5ffd44, 0xfd57fd5d, 0xf3ccfd55, 0xf3c1f3c3, 0xf33cf3d0, 0xf300f334,
    0xf313f305, 0xf34cf310, 0xf350f344, 0xf0f3f0fc, 0xf0f1f0f0, 0xf0c7f0c0, 0xf0d4f0c5, 0xf030f03f,
    0xf00ff035, 0xf003f00c, 0xf001f000, 0xf01ff004, 0xf010f01d, 0xf015f017, 0xf04cf07c, 0xf047f040,
    0xf05cf045, 0xf050f053, 0xf054f051, 0xf1c4f1c3, 0xf133f13c, 0xf10df10f, 0xf107f100, 0xf11cf11f,
    0xf114f111, 0xf14cf170, 0xf144f143, 0xf7fdf7ff, 0xf7f5f7f7, 0xf7dff7c0, 0xf7d7f7dd, 0xf730f7d5,
    0xf701f70c, 0xf77ff710, 0xf777f77d, 0xf740f775, 0xf75df75f, 0xf755f757, 0xf4ccf4f0, 0xf4c4f4c3,
    0xf4d0f4d3, 0xf40ff43c, 0xf400f40c, 0xf413f41c, 0xf44cf414, 0xf441f443, 0xf450f444, 0xf5fdf5ff,
    0xf5f5f5f7, 0xf5dff5c0, 0xf5d7f5dd, 0xf530f5d5, 0xf504f50c, 0xf510f51c, 0xf57df57f, 0xf577f570,
    0xf540f575, 0xf55df55f, 0xf555f557, 0xcfcccfcf, 0xcfc4cfc3, 0xcfd0cfd3, 0xcf33cf3c, 0xcf00cf0f,
    0xcf1ccf07, 0xcf10cf13, 0xcf4ccf14, 0xcf41cf43, 0xcf50cf5c, 0xccf3ccfc, 0xccf4ccf1, 0xcccdcccf,
    0xccc7ccc0, 0xccd3ccdc, 0xcc30ccd4, 0xcc0fcc35, 0xcc0dcc0c, 0xcc00cc03, 0xcc04cc01, 0xcc10cc1f,
    0xcc4dcc73, 0xcc5ccc40, 0xcdcccc53, 0xcdc1cdc3, 0xcd3fcdd0, 0xcd34cd31, 0xcd00cd0d, 0xcd05cd07,
    0xcd11cd13, 0xcd4ccd70, 0xcd41cd43, 0xc3fccd50, 0xc3f4c3f1, 0xc3c0c3c3, 0xc3c4c3c7, 0xc3d1c3dc,
    0xc330c33c, 0xc337c331, 0xc30cc335, 0xc300c303, 0xc304c301, 0xc310c31d, 0xc373c317, 0xc34fc374,
    0xc340c343, 0xc344c347, 0xc35cc345, 0xc350c353, 0xc0fdc354, 0xc0f5c0f0, 0xc0c3c0cc, 0xc0c1c0c0,
    0xc0dfc0c4, 0xc0d0c0dd, 0xc0d5c0d7, 0xc033c03c, 0xc031c030, 0xc00dc00c, 0xc000c003, 0xc004c001,
    0xc01cc005, 0xc010c013, 0xc014c011, 0xc07dc07f, 0xc070c073, 0xc075c077, 0xc04cc04f, 0xc040c043,
    0xc044c041, 0xc05fc045, 0xc050c05d, 0xc1f3c1fc, 0xc1f1c1f0, 0xc1c1c1c0, 0xc1c5c1c7, 0xc1d1c1dc,
    0xc13dc13f, 0xc130c133, 0xc135c137, 0xc100c10c, 0xc107c101, 0xc11cc104, 0xc110c113, 0xc114c117,
    0xc171c115, 0xc14dc175, 0xc153c140, 0xc7ccc154, 0xc7d0c7c1, 0xc733c73c, 0xc734c731, 0xc700c70f,
    0xc705c707, 0xc71cc71f, 0xc711c713, 0xc770c714, 0xc743c74c, 0xc4cfc750, 0xc4c0c4cd, 0xc4dcc4c5,
    0xc43dc4d0, 0xc430c433, 0xc40cc437, 0xc400c403, 0xc404c401, 0xc41fc405, 0xc415c410, 0xc44cc474,
    0xc440c44d, 0xc45cc447, 0xc454c451, 0xc5c1c5f4, 0xc5d1c5d3, 0xc531c533, 0xc50fc534, 0xc500c50d,
    0xc51cc507, 0xc514c511, 0xc54cc570, 0xc545c541, 0xdffddfff, 0xdff5dff7, 0xdfdfdfc0, 0xdfd0dfdd,
    0xdfd5dfd7, 0xdf0cdf30, 0xdf1cdf04, 0xdf7fdf10, 0xdf77df7d, 0xdf40df75, 0xdf5ddf5f, 0xdf57df50,
    0xdcf0df55, 0xdcc3dccc, 0xdcd0dcc4, 0xdc33dc3d, 0xdc00dc34, 0xdc05dc07, 0xdc13dc1c, 0xdc11dc10,
    0xdc4fdc70, 0xdc44dc41, 0xddfcdc50, 0xddf5ddf7, 0xddc0ddcc, 0xdddddddf, 0xddd5ddd7, 0xdd0cdd30,
    0xdd04dd01, 0xdd7cdd10, 0xdd75dd77, 0xdd40dd4c, 0xdd5ddd5f, 0xdd55dd57, 0xd3c3d3f0, 0xd3c4d3c1,
    0xd333d3d0, 0xd331d330, 0xd30dd334, 0xd307d300, 0xd311d305, 0xd34cd370, 0xd344d343, 0xd350d35c,
    0xd0c0d0f4, 0xd0d4d0dc, 0xd030d03f, 0xd00cd037, 0xd000d003, 0xd01dd004, 0xd017d010, 0xd04fd074,
    0xd040d043, 0xd045d047, 0xd053d05c, 0xd054d051, 0xd1cfd1f0, 0xd1c4d1cd, 0xd13cd1d0, 0xd100d134,
    0xd11cd11f, 0xd173d114, 0xd14fd171, 0xd7ffd145, 0xd7f7d7fd, 0xd7c0d7f5, 0xd7ddd7df, 0xd7d5d7d7,
    0xd70cd730, 0xd710d703, 0xd77dd77f, 0xd775d777, 0xd75dd75f, 0xd755d757, 0xd4ccd4f4, 0xd4c4d4c3,
    0xd431d4d0, 0xd40dd434, 0xd41cd400, 0xd411d413, 0xd470d414, 0xd441d44f, 0xd453d444, 0xd5ffd450,
    0xd5f7d5fd, 0xd5dfd5f5, 0xd5d7d5dd, 0xd530d5d5, 0xd501d50c, 0xd510d504, 0xd57dd57f, 0xd575d577,
    0xd55fd540, 0xd557d55d, 0x3ff0d555, 0x3fc13fcc, 0x3f343fd0, 0x3f003f0d, 0x3f053f07, 0x3f133f1c,
    0x3f433f11, 0x3f5c3f44, 0x3cff3f51, 0x3cf33cfc, 0x3cf43cf1, 0x3cc03ccd, 0x3cc73cc1, 0x3cdc3cc5,
    0x3cd43cd1, 0x3c373c30, 0x3c0c3c35, 0x3c003c03, 0x3c043c01, 0x3c103c05, 0x3c153c17, 0x3c733c7c,
    0x3c4f3c71, 0x3c403c4d, 0x3c5c3c5f, 0x3df03c5d, 0x3dc33dcc, 0x3dd03dc1, 0x3d0d3d3c, 0x3d053d00,
    0x3d143d13, 0x3d433d74, 0x33fc3d50, 0x33c433c0, 0x333033d4, 0x33353337, 0x3303330c, 0x33013300,
    0x331d331c, 0x33173310, 0x337c3315, 0x33743371, 0x334d334f, 0x335f3340, 0x3354335c, 0x30fd30fc,
    0x30f530f0, 0x30c330cc, 0x30c130c0, 0x30df30c4, 0x30d530d0, 0x3033303c, 0x30313030, 0x300f3034,
    0x3003300c, 0x30013000, 0x30043007, 0x3013301c, 0x30113010, 0x307d3014, 0x30703073, 0x304c3077,
    0x30403043, 0x30443041, 0x30503045, 0x30553057, 0x31f031fc, 0x31c331f4, 0x31c731c0, 0x31dc31c5,
    0x31d431d3, 0x313d313f, 0x31373130, 0x310c310f, 0x3100310d, 0x31043101, 0x3110311d, 0x317c3117,
    0x31753170, 0x31403143, 0x3153315c, 0x37f03151, 0x37c037cc, 0x37d037c5, 0x3734373d, 0x3700370f,
    0x371c3707, 0x37113713, 0x37703714, 0x3743374c, 0x37443741, 0x34fc3750, 0x34f134f0, 0x34cf34f5,
    0x34c034c3, 0x34dc34c7, 0x34d134d3, 0x3430343f, 0x340c3435, 0x3403340d, 0x34013400, 0x341f3404,
    0x3410341d, 0x34153411, 0x34743471, 0x3440344d, 0x34473441, 0x3453345c, 0x34543451, 0x353335c1,
    0x35343531, 0x35073500, 0x35133505, 0x35433514, 0x0ffc3550, 0x0ff00ff3, 0x0ff40ff1, 0x0fc00fcd,
    0x0fdc0fc5, 0x0fd40fd3, 0x0f300f3f, 0x0f0c0f37, 0x0f000f03, 0x0f040f01, 0x0f170f10, 0x0f740f71,
    0x0f470f40, 0x0f5c0f5f, 0x0f540f51, 0x0cf70cf0, 0x0cf50cf4, 0x0cc30ccc, 0x0cc10cc0, 0x0cc40cc7,
    0x0cd00cdf, 0x0cd70cd1, 0x0c3c0cd5, 0x0c300c33, 0x0c340c31, 0x0c0c0c0f, 0x0c030c0d, 0x0c010c00,
    0x0c040c07, 0x0c1c0c05, 0x0c100c13, 0x0c140c11, 0x0c700c7d, 0x0c430c4c, 0x0c410c40, 0x0c5f0c44,
    0x0c550c50, 0x0df10dfc, 0x0dc00dcd, 0x0ddc0dc5, 0x0d3d0dd3, 0x0d350d30, 0x0d030d0c, 0x0d010d00,
    0x0d1d0d04, 0x0d700d10, 0x0d4d0d4f, 0x0d440d40, 0x0d530d45, 0x03f003f3, 0x03c303cc, 0x03c103c0,
    0x03c403c7, 0x03d003dc, 0x03d503d7, 0x0333033c, 0x03310330, 0x03350334, 0x030c030f, 0x03000303,
    0x03070301, 0x03050304, 0x031d031c, 0x03100313, 0x03140311, 0x0377037f, 0x034c0375, 0x03400343,
    0x03440341, 0x0353035c, 0x03550350, 0x00fd00fc, 0x00f000f3, 0x00f400f1, 0x00cc00cf, 0x00c300cd,
    0x00c100c0, 0x00c500c4, 0x00d300dc, 0x00d100d0, 0x003f00d4, 0x003d003c, 0x00300033, 0x00370031,
    0x000f0034, 0x000d000c, 0x00000003, 0x00070001, 0x00050004, 0x001c001f, 0x00100013, 0x00170011,
    0x00150014, 0x0073007c, 0x00740070, 0x004f0075, 0x0043004c, 0x00410040, 0x00440047, 0x0053005c,
    0x00510050, 0x01ff0054, 0x01fd01fc, 0x01f101f3, 0x01f401f7, 0x01c301cc, 0x01c701c0, 0x01df01c4,
    0x01dd01dc, 0x01d001d3, 0x01d701d1, 0x013c01d4, 0x01310130, 0x01340137, 0x010f0135, 0x010d010c,
    0x01000103, 0x01070101, 0x01050104, 0x0113011c, 0x01140110, 0x0170017d, 0x01770171, 0x01750174,
    0x0140014c, 0x015d0145, 0x01510150, 0x01540157, 0x07f007f3, 0x07f407f1, 0x07c007cf, 0x07dc07c7,
    0x073007d5, 0x07350737, 0x0703070c, 0x07010700, 0x07040707, 0x071d071f, 0x07100713, 0x0774077d,
    0x074d074f, 0x07470740, 0x0754075c, 0x04fd04fc, 0x04f504f0, 0x04c304cc, 0x04c104c0, 0x04d004c4,
    0x0433043c, 0x04310430, 0x040f0434, 0x040d040c, 0x04000403, 0x04070401, 0x04050404, 0x0413041c,
    0x04110410, 0x047c0414, 0x04740470, 0x0443044c, 0x04410440, 0x04440447, 0x05f30450, 0x05c005f7,
    0x05df05c5, 0x05d105d0, 0x053005d4, 0x05340537, 0x0500050c, 0x05070501, 0x051d0504, 0x05170510,
    0x057c0515, 0x054d0575, 0x05410540, 0x05450547, 0x1ff0055c, 0x1fc11fc3, 0x1fd01fc4, 0x1f0f1f33,
    0x1f011f00, 0x1f051f07, 0x1f131f1c, 0x1f141f11, 0x1f411f7c, 0x1cfc1f50, 0x1cf11cf3, 0x1ccd1cf4,
    0x1cdc1cc0, 0x1cd11cdd, 0x1c301cd4, 0x1c0c1c34, 0x1c011c00, 0x1c101c04, 0x1c151c11, 0x1c751c73,
    0x1c401c4d, 0x1c511c5c, 0x1dcc1c54, 0x1dc41dc1, 0x1d3c1d3f, 0x1d001d31, 0x1d071d01, 0x1d701d1f,
    0x1d411d4c, 0x13cc1d50, 0x13c013cd, 0x13c513c1, 0x13d113dc, 0x133f13d4, 0x1330133d, 0x13351337,
    0x1303130c, 0x13011300, 0x13051304, 0x131d131f, 0x13731310, 0x13741370, 0x134d134f, 0x13401343,
    0x13471341, 0x135c1345, 0x13541353, 0x10f710f0, 0x10cc10f5, 0x10c110c0, 0x103310c4, 0x10311030,
    0x100f1034, 0x1003100c, 0x10011000, 0x101c1004, 0x10101013, 0x10141011, 0x10741071, 0x104c1075,
    0x10411040, 0x10451044, 0x1050105d, 0x10571051, 0x11f411fd, 0x11df11c0, 0x11d711d1, 0x113f11d4,
    0x11371130, 0x110c1135, 0x11001103, 0x11071101, 0x111f1105, 0x11171110, 0x117d117f, 0x11751170,
    0x11411143, 0x11441147, 0x1153115f, 0x11551151, 0x17c417c1, 0x173c17d0, 0x1700170d, 0x171c1705,
    0x17701714, 0x1747174c, 0x14fc1751, 0x14cf14f3, 0x14dc14c0, 0x14d114d3, 0x143f14d4, 0x1430143c,
    0x14371431, 0x1403140c, 0x14011400, 0x141f1404, 0x14151410, 0x1473147d, 0x14401475, 0x1453145c,
    0x14541450, 0x15c115cc, 0x153c15c7, 0x15341533, 0x1500150f, 0x15051507, 0x15101513, 0x15711514,
    0x15471543, 0x15511545, 0x7ffd7fff, 0x7ff57ff7, 0x7fdd7fdf, 0x7fd57fd7, 0x7f0f7f30, 0x7f037f0c,
    0x7f047f01, 0x7f7f7f10, 0x7f777f7d, 0x7f407f75, 0x7f5d7f5f, 0x7f557f57, 0x7ccc7cf0, 0x7cc17cc3,
    0x7cd07cc4, 0x7c337c3c, 0x7c0f7c34, 0x7c007c0d, 0x7c077c01, 0x7c137c04, 0x7c147c11, 0x7c747c70,
    0x7c417c43, 0x7c507c44, 0x7dfd7dff, 0x7df57df7, 0x7ddf7dc0, 0x7dd77ddd, 0x7d0c7dd5, 0x7d047d03,
    0x7d7f7d10, 0x7d777d7d, 0x7d407d75, 0x7d5d7d5f, 0x7d557d57, 0x73c473c3, 0x7333733c, 0x7300730c,
    0x731c7305, 0x73147313, 0x73447343, 0x70f470fc, 0x70c070cd, 0x70d170c5, 0x703f70d4, 0x7030703c,
    0x700c7037, 0x70007003, 0x70047001, 0x70107005, 0x70177011, 0x707c7015, 0x70717073, 0x704f7074,
    0x7040704d, 0x70517047, 0x71c171cc, 0x71d071c4, 0x7133713c, 0x71357134, 0x7100710f, 0x71057104,
    0x7111711c, 0x71707115, 0x7145714c, 0x77ff7153, 0x77f777fd, 0x77c077f5, 0x77dd77df, 0x77d577d7,
    0x7730773c, 0x7703770c, 0x77107704, 0x777f7714, 0x7777777d, 0x77407775, 0x775d775f, 0x77557757,
    0x74f174f0, 0x74c374cc, 0x74d074c1, 0x7433743c, 0x74347431, 0x740d740f, 0x74057400, 0x7413741c,
    0x74417470, 0x74507444, 0x75fd75ff, 0x75f575f7, 0x75df75c0, 0x75d775dd, 0x753075d5, 0x7503750c,
    0x757f7501, 0x7577757d, 0x75407575, 0x755d755f, 0x75557557, 0x4fcc4ff0, 0x4fc74fc1, 0x4fd04fc4,
    0x4f314f3c, 0x4f004f34, 0x4f054f07, 0x4f154f14, 0x4f4c4f70, 0x4f414f43, 0x4f504f44, 0x4cf34cfc,
    0x4cf44cf1, 0x4cc04ccf, 0x4cc54cc7, 0x4cd34cdc, 0x4cd44cd1, 0x4c304c3f, 0x4c0c4c0f, 0x4c004c03,
    0x4c044c01, 0x4c104c1d, 0x4c714c73, 0x4c404c4d, 0x4c5c4c47, 0x4c514c53, 0x4df04c54, 0x4dc34dcc,
    0x4dd04dc4, 0x4d314d33, 0x4d0f4d34, 0x4d004d0d, 0x4d114d07, 0x4d704d14, 0x4d414d43, 0x43fc4d54,
    0x43f143f3, 0x43c043cf, 0x43d143c7, 0x4335433f, 0x4303430c, 0x43014300, 0x43044307, 0x431c431f,
    0x4310431d, 0x43714373, 0x4343434d, 0x43474340, 0x4354435c, 0x40f040ff, 0x40f540f7, 0x40cc40cf,
    0x40c040c3, 0x40c440c1, 0x40d040dc, 0x40d540d4, 0x4033403c, 0x40314030, 0x400f4034, 0x400d400c,
    0x40004003, 0x40074001, 0x40054004, 0x4013401c, 0x40114010, 0x407c4014, 0x40774070, 0x404d404c,
    0x40404043, 0x40444041, 0x405f4045, 0x4050405d, 0x40554057, 0x41f341fc, 0x41c041cf, 0x41df41c4,
    0x41d441d1, 0x41374130, 0x410c4134, 0x4100410d, 0x41044101, 0x41174110, 0x4173417d, 0x41754174,
    0x4143414d, 0x41534140, 0x41544151, 0x47c147f0, 0x47d047c4, 0x4731473c, 0x470d470f, 0x47014700,
    0x47134705, 0x47704710, 0x4741474c, 0x47504744, 0x44f144f3, 0x44cf44f4, 0x44c044cd, 0x44c544c7,
    0x44dc44df, 0x44d144d3, 0x443d443f, 0x44374430, 0x440c4435, 0x44004403, 0x44044401, 0x4410441d,
    0x44154411, 0x4473447c, 0x444d444f, 0x44454440, 0x4451445c, 0x45c045f0, 0x453345d0, 0x45344531,
    0x4500450f, 0x451c4507, 0x454c4570, 0x45404543, 0x5fff4541, 0x5ff75ffd, 0x5fc05ff5, 0x5fdd5fdf,
    0x5fd55fd7, 0x5f0c5f30, 0x5f015f03, 0x5f7f5f04, 0x5f775f7d, 0x5f405f75, 0x5f5d5f5f, 0x5f555f57,
    0x5cf45cf0, 0x5cc35ccc, 0x5cc45cc1, 0x5c315cc5, 0x5c0c5c34, 0x5c075c00, 0x5c1c5c05, 0x5c705c13,
    0x5c4d5c4f, 0x5c445c41, 0x5df75dfd, 0x5dcf5df5, 0x5ddd5dc4, 0x5dd55dd7, 0x5d0c5d30, 0x5d045d01,
    0x5d7f5d10, 0x5d775d7d, 0x5d405d75, 0x5d5d5d5f, 0x5d555d57, 0x53d053c4, 0x5333533c, 0x5303530f,
    0x53075300, 0x531c5305, 0x53115310, 0x53145317, 0x50f15370, 0x50cf50f4, 0x50c050cd, 0x50d150c7,
    0x503d50d4, 0x500c5030, 0x50005003, 0x50045001, 0x50155010, 0x5073507c, 0x50715070, 0x504d5074,
    0x50475040, 0x51cc51f0, 0x51c551c1, 0x51d051dc, 0x51315133, 0x510d5135, 0x51015100, 0x511f5107,
    0x5171511d, 0x5140514f, 0x51445141, 0x5153515c, 0x57ff5151, 0x57f757fd, 0x57df57f5, 0x57d757dd,
    0x570c57d5, 0x57015703, 0x577f5704, 0x5777577d, 0x57405775, 0x575d575f, 0x57555757, 0x54c354f0,
    0x54dc54c4, 0x543c54d0, 0x5400540f, 0x541c5405, 0x54145411, 0x5441544f, 0x55fd55ff, 0x55f555f7,
    0x55dd55df, 0x55d555d7, 0x5503550c, 0x557f5501, 0x5577557d, 0x55405575, 0x555d555f, 0x55555557
);

struct iq1_m {
    qs: array<u32, 8>,
    qh: array<u32, 4>,
    scales: array<u32, 2>
};

fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block = src0[src0_idx_base + offset];

    let scale = ((block.scales[0] >> 12) & 0xF) | ((block.scales[0] >> 24) & 0x00F0) | ((block.scales[1] >> 4) & 0x0F00) | ((block.scales[1] >> 16) & 0xF000);
    let d = f32(bitcast<vec2<f16>>(scale).x);
    var src1_i = src1_idx_base + offset * 256;
    var sum = 0.0;
    for (var ib: u32 = 0; ib < 8; ib++) {
        let sw = (block.scales[ib / 4] >> (16 * ((ib / 2) % 2))) & 0xFFFF;
        let s1 : u32 = (sw >> (6 * (ib % 2))) & 0x7;
        let s2 : u32 = (sw >> (6 * (ib % 2) + 3)) & 0x7;
        var dl = array<f32, 2>(
            d * f32(2 * s1 + 1),
            d * f32(2 * s2 + 1)
        );

        let qh = block.qh[ib / 2] >> (16 * (ib % 2));
        var idx = array<u32, 4>(
            get_byte(block.qs[ib], 0) | ((qh << 8) & 0x700),
            get_byte(block.qs[ib], 1) | ((qh << 4) & 0x700),
            get_byte(block.qs[ib], 2) | ((qh) & 0x700),
            get_byte(block.qs[ib], 3) | ((qh >> 4) & 0x700)
        );
        var delta = array<f32, 4>(
            select(IQ1_DELTA, -IQ1_DELTA, (qh & 0x08) != 0),
            select(IQ1_DELTA, -IQ1_DELTA, (qh & 0x80) != 0),
            select(IQ1_DELTA, -IQ1_DELTA, ((qh >> 8) & 0x08) != 0),
            select(IQ1_DELTA, -IQ1_DELTA, ((qh >> 8) & 0x80) != 0)
        );
        for (var l: u32 = 0; l < 4; l++) {
            let ig = idx[l] * 8;
            for (var j: u32 = 0; j < 8; j++) {
                let gw = iq1_grid[(ig + j) / 16];
                let g = (gw >> (((ig + j) % 16) * 2)) & 3;
                let gs = bitcast<i32>(g << 30) >> 30;
                sum += dl[l/2] * (f32(gs) + delta[l]) * src1[src1_i];
                src1_i++;
            }
        }
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<iq1_m>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/256; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_iq4_nl_f32 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

const kvalues_iq4nl = array<i32, 16>(
    -127, -104, -83, -65, -49, -35, -22, -10, 1, 13, 25, 38, 53, 69, 89, 113
);

struct iq4_nl {
    d: f16,
    qs: array<f16, 8>,
};

fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block = src0[src0_idx_base + offset];
    let d = f32(block.d);
    var src1_i = src1_idx_base + offset * 32;
    var sum = 0.0;
    var qs: array<u32, 4>;
    for (var i: u32 = 0; i < 4; i++) {
        qs[i] = bitcast<u32>(vec2(block.qs[i * 2], block.qs[i * 2 + 1]));
    }
    for (var j: u32 = 0; j < 16; j++) {
        let qsb = get_byte(qs[j / 4], j % 4);
        sum += d * f32(kvalues_iq4nl[qsb & 0xF]) * src1[src1_i];
        sum += d * f32(kvalues_iq4nl[qsb >> 4]) * src1[src1_i + 16];
        src1_i++;
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<iq4_nl>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/32; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_iq4_xs_f32 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

const kvalues_iq4nl = array<i32, 16>(
    -127, -104, -83, -65, -49, -35, -22, -10, 1, 13, 25, 38, 53, 69, 89, 113
);

struct iq4_xs {
    d: f16,
    scales_h: f16,
    scales_l: u32,
    qs: array<u32, 32>
};

fn multiply_add(src0_idx_base: u32, src1_idx_base: u32, offset: u32) -> f32 {
    let block = src0[src0_idx_base + offset];
    let d = f32(block.d);
    let scales_h = bitcast<u32>(vec2(block.scales_h, 0.0));
    var src1_i = src1_idx_base + offset * 256;
    var sum = 0.0;
    for (var ib: u32 = 0; ib < 8; ib++) {
        let ls = ((get_byte(block.scales_l, ib / 2) >> (4 * (ib % 2))) & 0xF) | (((scales_h >> (2 * ib)) & 3) << 4);
        let dl = d * (f32(ls) - 32.0);
        for (var j: u32 = 0; j < 16; j++) {
            let iqs = ib * 16 + j;
            let qsb = get_byte(block.qs[iqs / 4], iqs % 4);
            sum += dl * f32(kvalues_iq4nl[qsb & 0xF]) * src1[src1_i];
            sum += dl * f32(kvalues_iq4nl[qsb >> 4]) * src1[src1_i + 16];
            src1_i++;
        }
        src1_i += 16;
    }
    return sum;
}



struct MulMatParams {
    offset_src0: u32, // in elements/blocks
    offset_src1: u32, // in elements/blocks
    offset_dst: u32, // in elements/blocks
    m: u32,
    n: u32,
    k: u32,
    // all strides are in elements/blocks
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,

    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<iq4_xs>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns

@group(0) @binding(3) var<uniform> params: MulMatParams;

@compute @workgroup_size(256)
fn main(@builtin(global_invocation_id) global_id: vec3<u32>) {
    let total = params.m * params.n * params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    if (global_id.x >= total) {
        return;
    }

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = global_id.x / dst3_stride;
    let src03_idx = dst3_idx / params.broadcast3; // src0 may be broadcast along the third dimension
    let src13_idx = dst3_idx; // src1 is not broadcast
    let dst3_rem = global_id.x % dst3_stride;

    let dst2_idx = dst3_rem / dst2_stride;
    let src02_idx = dst2_idx / params.broadcast2; // src0 may also be broadcast along the second dimension
    let src12_idx = dst2_idx; // src1 is not broadcast

    let dst2_rem = dst3_rem % dst2_stride;

    let row = dst2_rem / params.m; // output row
    let col = dst2_rem % params.m; // output column

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + col * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12 + row * params.stride_11;

    var sum = 0.0;
    for (var i: u32 = 0u; i < params.k/256; i = i + 1u) {
        sum += multiply_add(src0_idx_base, src1_idx_base, i);
    }
    dst[params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + row * params.m + col] = sum;
})";

const char* wgsl_mul_mat_reg_tile_f32_f32_vec = R"(enable f16;

struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<vec4<f32>>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<vec4<f32>>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<vec4<f32>>; // M rows, N columns (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

fn store_val(acc: array<array<f16, TILE_N>, TILE_M>, tn: u32, tm: u32) -> vec4<f32> {
    return vec4<f32>(f32(acc[tm][tn]), f32(acc[tm + 1][tn]), f32(acc[tm + 2][tn]), f32(acc[tm + 3][tn]));
}

fn store_shmem(val: vec4<f16>, idx: u32) {
    shmem[idx] = val.x;
    shmem[idx + 1] = val.y;
    shmem[idx + 2] = val.z;
    shmem[idx + 3] = val.w;
}

fn init_shmem_src0(thread_id: u32, batch_offset: u32, offset_m: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 4; elem_idx < TILE_SRC0_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 4) {
        let tile_m = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_m = offset_m + tile_m;
        let global_k = k_outer + tile_k;
        let src0_idx = batch_offset + global_m * params.stride_01 + global_k;
        let src0_val = select( // taking a slight performance hit to avoid oob
            vec4<f32>(0.0),
            src0[src0_idx/4],
            global_m < params.m && global_k < params.k);
        store_shmem(vec4<f16>(src0_val), elem_idx);
    }
}

fn init_shmem_src1(thread_id: u32, batch_offset: u32, offset_n: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 4; elem_idx < TILE_SRC1_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 4) {
        let tile_n = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_n = offset_n + tile_n;
        let global_k = k_outer + tile_k;
        let src1_idx = batch_offset + global_n * params.stride_11 + global_k;
        let src1_val = select(
            vec4<f32>(0.0),
            src1[src1_idx/4],
            global_n < params.n && global_k < params.k);
        store_shmem(vec4<f16>(src1_val), TILE_SRC0_SHMEM + elem_idx);
    }
}



fn get_local_n(thread_id: u32) -> u32 {
    return thread_id / WORKGROUP_SIZE_M;
}
fn get_local_m(thread_id: u32) -> u32 {
    return thread_id % WORKGROUP_SIZE_M;
}

// TILE_M must be multiple of 4 for vec4 loads
const TILE_M = {{WEBGPU_TILE_M}}u;
const TILE_N = {{WEBGPU_TILE_N}}u;

override WORKGROUP_SIZE_M: u32;
override WORKGROUP_SIZE_N: u32;
override TILE_K: u32;

override TOTAL_WORKGROUP_SIZE = WORKGROUP_SIZE_M * WORKGROUP_SIZE_N;
override TILE_SRC0_SHMEM = TILE_K * WORKGROUP_SIZE_M * TILE_M;
override TILE_SRC1_SHMEM = TILE_K * WORKGROUP_SIZE_N * TILE_N;

var<workgroup> shmem: array<f16, TILE_SRC0_SHMEM + TILE_SRC1_SHMEM>;

@compute @workgroup_size(TOTAL_WORKGROUP_SIZE)
fn main(@builtin(workgroup_id) wg_id: vec3<u32>,
        @builtin(local_invocation_id) local_id: vec3<u32>) {

    let thread_id = local_id.x;
    let local_m = get_local_m(thread_id);
    let local_n = get_local_n(thread_id);

    let wg_n_count = (params.n + WORKGROUP_SIZE_N * TILE_N - 1u) / (WORKGROUP_SIZE_N * TILE_N);
    let wg_m_count = (params.m + WORKGROUP_SIZE_M * TILE_M - 1u) / (WORKGROUP_SIZE_M * TILE_M);
    let wg_per_matrix = wg_m_count * wg_n_count;

    let batch_idx = wg_id.x / wg_per_matrix;

    let wg_in_batch = wg_id.x % wg_per_matrix;
    let wg_m = wg_in_batch % wg_m_count;
    let wg_n = wg_in_batch / wg_m_count;

    let output_row_base = wg_m * WORKGROUP_SIZE_M * TILE_M + local_m * TILE_M;
    let output_col_base = wg_n * WORKGROUP_SIZE_N * TILE_N + local_n * TILE_N;

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_batch_offset = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02;
    let src1_batch_offset = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;

    let offset_m = wg_m * WORKGROUP_SIZE_M * TILE_M;
    let offset_n = wg_n * WORKGROUP_SIZE_N * TILE_N;

    var acc: array<array<f16, TILE_N>, TILE_M>;

    for (var k_outer = 0u; k_outer < params.k; k_outer += TILE_K) {

        // see mul_mat_decls.tmpl
        init_shmem_src0(thread_id, src0_batch_offset, offset_m, k_outer);
        init_shmem_src1(thread_id, src1_batch_offset, offset_n, k_outer);

        workgroupBarrier();

        let k_end = min(TILE_K, params.k - k_outer);

        for (var k_inner = 0u; k_inner < k_end; k_inner++) {
            var src0_tile: array<f16, TILE_M>;
            for (var tm = 0u; tm < TILE_M; tm++) {
                let src0_m = local_m * TILE_M + tm;
                let src0_idx = k_inner + src0_m * TILE_K;
                src0_tile[tm] = shmem[src0_idx];
            }
            for (var tn = 0u; tn < TILE_N; tn++) {
                let src1_n = local_n * TILE_N + tn;
                let src1_idx = src1_n * TILE_K + k_inner;
                let src1_val = shmem[TILE_SRC0_SHMEM + src1_idx];
                for (var tm = 0u; tm < TILE_M; tm++) {
                      acc[tm][tn] += src0_tile[tm] * src1_val;
                }
            }
        }

        workgroupBarrier();
    }

    let dst_batch_offset = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride;

    for (var tn = 0u; tn < TILE_N; tn++) {
        let global_col = output_col_base + tn;
        if (global_col < params.n) {
            for (var tm = 0u; tm < TILE_M; tm += 4) {
                let global_row = output_row_base + tm;
                if (global_row < params.m) {
                    let dst_idx = dst_batch_offset + global_col * params.m + global_row;
                    dst[dst_idx/4] = store_val(acc, tn, tm);
                }
            }
        }
    }
})";

const char* wgsl_mul_mat_reg_tile_f32_f32 = R"(enable f16;

struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<f32>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

fn store_val(acc: array<array<f16, TILE_N>, TILE_M>, tn: u32, tm: u32) -> f32 {
    return f32(acc[tm][tn]);
}

fn store_shmem(val: f16, idx: u32) {
    shmem[idx] = val;
}

fn init_shmem_src0(thread_id: u32, batch_offset: u32, offset_m: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 1; elem_idx < TILE_SRC0_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 1) {
        let tile_m = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_m = offset_m + tile_m;
        let global_k = k_outer + tile_k;
        let src0_idx = batch_offset + global_m * params.stride_01 + global_k;
        let src0_val = select( // taking a slight performance hit to avoid oob
            f32(0.0),
            src0[src0_idx/1],
            global_m < params.m && global_k < params.k);
        store_shmem(f16(src0_val), elem_idx);
    }
}

fn init_shmem_src1(thread_id: u32, batch_offset: u32, offset_n: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 1; elem_idx < TILE_SRC1_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 1) {
        let tile_n = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_n = offset_n + tile_n;
        let global_k = k_outer + tile_k;
        let src1_idx = batch_offset + global_n * params.stride_11 + global_k;
        let src1_val = select(
            f32(0.0),
            src1[src1_idx/1],
            global_n < params.n && global_k < params.k);
        store_shmem(f16(src1_val), TILE_SRC0_SHMEM + elem_idx);
    }
}



fn get_local_n(thread_id: u32) -> u32 {
    return thread_id / WORKGROUP_SIZE_M;
}
fn get_local_m(thread_id: u32) -> u32 {
    return thread_id % WORKGROUP_SIZE_M;
}

// TILE_M must be multiple of 4 for vec4 loads
const TILE_M = {{WEBGPU_TILE_M}}u;
const TILE_N = {{WEBGPU_TILE_N}}u;

override WORKGROUP_SIZE_M: u32;
override WORKGROUP_SIZE_N: u32;
override TILE_K: u32;

override TOTAL_WORKGROUP_SIZE = WORKGROUP_SIZE_M * WORKGROUP_SIZE_N;
override TILE_SRC0_SHMEM = TILE_K * WORKGROUP_SIZE_M * TILE_M;
override TILE_SRC1_SHMEM = TILE_K * WORKGROUP_SIZE_N * TILE_N;

var<workgroup> shmem: array<f16, TILE_SRC0_SHMEM + TILE_SRC1_SHMEM>;

@compute @workgroup_size(TOTAL_WORKGROUP_SIZE)
fn main(@builtin(workgroup_id) wg_id: vec3<u32>,
        @builtin(local_invocation_id) local_id: vec3<u32>) {

    let thread_id = local_id.x;
    let local_m = get_local_m(thread_id);
    let local_n = get_local_n(thread_id);

    let wg_n_count = (params.n + WORKGROUP_SIZE_N * TILE_N - 1u) / (WORKGROUP_SIZE_N * TILE_N);
    let wg_m_count = (params.m + WORKGROUP_SIZE_M * TILE_M - 1u) / (WORKGROUP_SIZE_M * TILE_M);
    let wg_per_matrix = wg_m_count * wg_n_count;

    let batch_idx = wg_id.x / wg_per_matrix;

    let wg_in_batch = wg_id.x % wg_per_matrix;
    let wg_m = wg_in_batch % wg_m_count;
    let wg_n = wg_in_batch / wg_m_count;

    let output_row_base = wg_m * WORKGROUP_SIZE_M * TILE_M + local_m * TILE_M;
    let output_col_base = wg_n * WORKGROUP_SIZE_N * TILE_N + local_n * TILE_N;

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_batch_offset = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02;
    let src1_batch_offset = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;

    let offset_m = wg_m * WORKGROUP_SIZE_M * TILE_M;
    let offset_n = wg_n * WORKGROUP_SIZE_N * TILE_N;

    var acc: array<array<f16, TILE_N>, TILE_M>;

    for (var k_outer = 0u; k_outer < params.k; k_outer += TILE_K) {

        // see mul_mat_decls.tmpl
        init_shmem_src0(thread_id, src0_batch_offset, offset_m, k_outer);
        init_shmem_src1(thread_id, src1_batch_offset, offset_n, k_outer);

        workgroupBarrier();

        let k_end = min(TILE_K, params.k - k_outer);

        for (var k_inner = 0u; k_inner < k_end; k_inner++) {
            var src0_tile: array<f16, TILE_M>;
            for (var tm = 0u; tm < TILE_M; tm++) {
                let src0_m = local_m * TILE_M + tm;
                let src0_idx = k_inner + src0_m * TILE_K;
                src0_tile[tm] = shmem[src0_idx];
            }
            for (var tn = 0u; tn < TILE_N; tn++) {
                let src1_n = local_n * TILE_N + tn;
                let src1_idx = src1_n * TILE_K + k_inner;
                let src1_val = shmem[TILE_SRC0_SHMEM + src1_idx];
                for (var tm = 0u; tm < TILE_M; tm++) {
                      acc[tm][tn] += src0_tile[tm] * src1_val;
                }
            }
        }

        workgroupBarrier();
    }

    let dst_batch_offset = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride;

    for (var tn = 0u; tn < TILE_N; tn++) {
        let global_col = output_col_base + tn;
        if (global_col < params.n) {
            for (var tm = 0u; tm < TILE_M; tm += 1) {
                let global_row = output_row_base + tm;
                if (global_row < params.m) {
                    let dst_idx = dst_batch_offset + global_col * params.m + global_row;
                    dst[dst_idx/1] = store_val(acc, tn, tm);
                }
            }
        }
    }
})";

const char* wgsl_mul_mat_reg_tile_f16_f32_vec = R"(enable f16;

struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<vec4<f16>>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<vec4<f32>>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<vec4<f32>>; // M rows, N columns (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

fn store_val(acc: array<array<f16, TILE_N>, TILE_M>, tn: u32, tm: u32) -> vec4<f32> {
    return vec4<f32>(f32(acc[tm][tn]), f32(acc[tm + 1][tn]), f32(acc[tm + 2][tn]), f32(acc[tm + 3][tn]));
}

fn store_shmem(val: vec4<f16>, idx: u32) {
    shmem[idx] = val.x;
    shmem[idx + 1] = val.y;
    shmem[idx + 2] = val.z;
    shmem[idx + 3] = val.w;
}

fn init_shmem_src0(thread_id: u32, batch_offset: u32, offset_m: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 4; elem_idx < TILE_SRC0_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 4) {
        let tile_m = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_m = offset_m + tile_m;
        let global_k = k_outer + tile_k;
        let src0_idx = batch_offset + global_m * params.stride_01 + global_k;
        let src0_val = select( // taking a slight performance hit to avoid oob
            vec4<f16>(0.0),
            src0[src0_idx/4],
            global_m < params.m && global_k < params.k);
        store_shmem(vec4<f16>(src0_val), elem_idx);
    }
}

fn init_shmem_src1(thread_id: u32, batch_offset: u32, offset_n: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 4; elem_idx < TILE_SRC1_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 4) {
        let tile_n = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_n = offset_n + tile_n;
        let global_k = k_outer + tile_k;
        let src1_idx = batch_offset + global_n * params.stride_11 + global_k;
        let src1_val = select(
            vec4<f32>(0.0),
            src1[src1_idx/4],
            global_n < params.n && global_k < params.k);
        store_shmem(vec4<f16>(src1_val), TILE_SRC0_SHMEM + elem_idx);
    }
}



fn get_local_n(thread_id: u32) -> u32 {
    return thread_id / WORKGROUP_SIZE_M;
}
fn get_local_m(thread_id: u32) -> u32 {
    return thread_id % WORKGROUP_SIZE_M;
}

// TILE_M must be multiple of 4 for vec4 loads
const TILE_M = {{WEBGPU_TILE_M}}u;
const TILE_N = {{WEBGPU_TILE_N}}u;

override WORKGROUP_SIZE_M: u32;
override WORKGROUP_SIZE_N: u32;
override TILE_K: u32;

override TOTAL_WORKGROUP_SIZE = WORKGROUP_SIZE_M * WORKGROUP_SIZE_N;
override TILE_SRC0_SHMEM = TILE_K * WORKGROUP_SIZE_M * TILE_M;
override TILE_SRC1_SHMEM = TILE_K * WORKGROUP_SIZE_N * TILE_N;

var<workgroup> shmem: array<f16, TILE_SRC0_SHMEM + TILE_SRC1_SHMEM>;

@compute @workgroup_size(TOTAL_WORKGROUP_SIZE)
fn main(@builtin(workgroup_id) wg_id: vec3<u32>,
        @builtin(local_invocation_id) local_id: vec3<u32>) {

    let thread_id = local_id.x;
    let local_m = get_local_m(thread_id);
    let local_n = get_local_n(thread_id);

    let wg_n_count = (params.n + WORKGROUP_SIZE_N * TILE_N - 1u) / (WORKGROUP_SIZE_N * TILE_N);
    let wg_m_count = (params.m + WORKGROUP_SIZE_M * TILE_M - 1u) / (WORKGROUP_SIZE_M * TILE_M);
    let wg_per_matrix = wg_m_count * wg_n_count;

    let batch_idx = wg_id.x / wg_per_matrix;

    let wg_in_batch = wg_id.x % wg_per_matrix;
    let wg_m = wg_in_batch % wg_m_count;
    let wg_n = wg_in_batch / wg_m_count;

    let output_row_base = wg_m * WORKGROUP_SIZE_M * TILE_M + local_m * TILE_M;
    let output_col_base = wg_n * WORKGROUP_SIZE_N * TILE_N + local_n * TILE_N;

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_batch_offset = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02;
    let src1_batch_offset = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;

    let offset_m = wg_m * WORKGROUP_SIZE_M * TILE_M;
    let offset_n = wg_n * WORKGROUP_SIZE_N * TILE_N;

    var acc: array<array<f16, TILE_N>, TILE_M>;

    for (var k_outer = 0u; k_outer < params.k; k_outer += TILE_K) {

        // see mul_mat_decls.tmpl
        init_shmem_src0(thread_id, src0_batch_offset, offset_m, k_outer);
        init_shmem_src1(thread_id, src1_batch_offset, offset_n, k_outer);

        workgroupBarrier();

        let k_end = min(TILE_K, params.k - k_outer);

        for (var k_inner = 0u; k_inner < k_end; k_inner++) {
            var src0_tile: array<f16, TILE_M>;
            for (var tm = 0u; tm < TILE_M; tm++) {
                let src0_m = local_m * TILE_M + tm;
                let src0_idx = k_inner + src0_m * TILE_K;
                src0_tile[tm] = shmem[src0_idx];
            }
            for (var tn = 0u; tn < TILE_N; tn++) {
                let src1_n = local_n * TILE_N + tn;
                let src1_idx = src1_n * TILE_K + k_inner;
                let src1_val = shmem[TILE_SRC0_SHMEM + src1_idx];
                for (var tm = 0u; tm < TILE_M; tm++) {
                      acc[tm][tn] += src0_tile[tm] * src1_val;
                }
            }
        }

        workgroupBarrier();
    }

    let dst_batch_offset = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride;

    for (var tn = 0u; tn < TILE_N; tn++) {
        let global_col = output_col_base + tn;
        if (global_col < params.n) {
            for (var tm = 0u; tm < TILE_M; tm += 4) {
                let global_row = output_row_base + tm;
                if (global_row < params.m) {
                    let dst_idx = dst_batch_offset + global_col * params.m + global_row;
                    dst[dst_idx/4] = store_val(acc, tn, tm);
                }
            }
        }
    }
})";

const char* wgsl_mul_mat_reg_tile_f16_f32 = R"(enable f16;

struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<f16>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

fn store_val(acc: array<array<f16, TILE_N>, TILE_M>, tn: u32, tm: u32) -> f32 {
    return f32(acc[tm][tn]);
}

fn store_shmem(val: f16, idx: u32) {
    shmem[idx] = val;
}

fn init_shmem_src0(thread_id: u32, batch_offset: u32, offset_m: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 1; elem_idx < TILE_SRC0_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 1) {
        let tile_m = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_m = offset_m + tile_m;
        let global_k = k_outer + tile_k;
        let src0_idx = batch_offset + global_m * params.stride_01 + global_k;
        let src0_val = select( // taking a slight performance hit to avoid oob
            f16(0.0),
            src0[src0_idx/1],
            global_m < params.m && global_k < params.k);
        store_shmem(f16(src0_val), elem_idx);
    }
}

fn init_shmem_src1(thread_id: u32, batch_offset: u32, offset_n: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 1; elem_idx < TILE_SRC1_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 1) {
        let tile_n = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_n = offset_n + tile_n;
        let global_k = k_outer + tile_k;
        let src1_idx = batch_offset + global_n * params.stride_11 + global_k;
        let src1_val = select(
            f32(0.0),
            src1[src1_idx/1],
            global_n < params.n && global_k < params.k);
        store_shmem(f16(src1_val), TILE_SRC0_SHMEM + elem_idx);
    }
}



fn get_local_n(thread_id: u32) -> u32 {
    return thread_id / WORKGROUP_SIZE_M;
}
fn get_local_m(thread_id: u32) -> u32 {
    return thread_id % WORKGROUP_SIZE_M;
}

// TILE_M must be multiple of 4 for vec4 loads
const TILE_M = {{WEBGPU_TILE_M}}u;
const TILE_N = {{WEBGPU_TILE_N}}u;

override WORKGROUP_SIZE_M: u32;
override WORKGROUP_SIZE_N: u32;
override TILE_K: u32;

override TOTAL_WORKGROUP_SIZE = WORKGROUP_SIZE_M * WORKGROUP_SIZE_N;
override TILE_SRC0_SHMEM = TILE_K * WORKGROUP_SIZE_M * TILE_M;
override TILE_SRC1_SHMEM = TILE_K * WORKGROUP_SIZE_N * TILE_N;

var<workgroup> shmem: array<f16, TILE_SRC0_SHMEM + TILE_SRC1_SHMEM>;

@compute @workgroup_size(TOTAL_WORKGROUP_SIZE)
fn main(@builtin(workgroup_id) wg_id: vec3<u32>,
        @builtin(local_invocation_id) local_id: vec3<u32>) {

    let thread_id = local_id.x;
    let local_m = get_local_m(thread_id);
    let local_n = get_local_n(thread_id);

    let wg_n_count = (params.n + WORKGROUP_SIZE_N * TILE_N - 1u) / (WORKGROUP_SIZE_N * TILE_N);
    let wg_m_count = (params.m + WORKGROUP_SIZE_M * TILE_M - 1u) / (WORKGROUP_SIZE_M * TILE_M);
    let wg_per_matrix = wg_m_count * wg_n_count;

    let batch_idx = wg_id.x / wg_per_matrix;

    let wg_in_batch = wg_id.x % wg_per_matrix;
    let wg_m = wg_in_batch % wg_m_count;
    let wg_n = wg_in_batch / wg_m_count;

    let output_row_base = wg_m * WORKGROUP_SIZE_M * TILE_M + local_m * TILE_M;
    let output_col_base = wg_n * WORKGROUP_SIZE_N * TILE_N + local_n * TILE_N;

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_batch_offset = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02;
    let src1_batch_offset = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;

    let offset_m = wg_m * WORKGROUP_SIZE_M * TILE_M;
    let offset_n = wg_n * WORKGROUP_SIZE_N * TILE_N;

    var acc: array<array<f16, TILE_N>, TILE_M>;

    for (var k_outer = 0u; k_outer < params.k; k_outer += TILE_K) {

        // see mul_mat_decls.tmpl
        init_shmem_src0(thread_id, src0_batch_offset, offset_m, k_outer);
        init_shmem_src1(thread_id, src1_batch_offset, offset_n, k_outer);

        workgroupBarrier();

        let k_end = min(TILE_K, params.k - k_outer);

        for (var k_inner = 0u; k_inner < k_end; k_inner++) {
            var src0_tile: array<f16, TILE_M>;
            for (var tm = 0u; tm < TILE_M; tm++) {
                let src0_m = local_m * TILE_M + tm;
                let src0_idx = k_inner + src0_m * TILE_K;
                src0_tile[tm] = shmem[src0_idx];
            }
            for (var tn = 0u; tn < TILE_N; tn++) {
                let src1_n = local_n * TILE_N + tn;
                let src1_idx = src1_n * TILE_K + k_inner;
                let src1_val = shmem[TILE_SRC0_SHMEM + src1_idx];
                for (var tm = 0u; tm < TILE_M; tm++) {
                      acc[tm][tn] += src0_tile[tm] * src1_val;
                }
            }
        }

        workgroupBarrier();
    }

    let dst_batch_offset = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride;

    for (var tn = 0u; tn < TILE_N; tn++) {
        let global_col = output_col_base + tn;
        if (global_col < params.n) {
            for (var tm = 0u; tm < TILE_M; tm += 1) {
                let global_row = output_row_base + tm;
                if (global_row < params.m) {
                    let dst_idx = dst_batch_offset + global_col * params.m + global_row;
                    dst[dst_idx/1] = store_val(acc, tn, tm);
                }
            }
        }
    }
})";

const char* wgsl_mul_mat_reg_tile_f16_f16_vec = R"(enable f16;

struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<vec4<f16>>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<vec4<f16>>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<vec4<f32>>; // M rows, N columns (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

fn store_val(acc: array<array<f16, TILE_N>, TILE_M>, tn: u32, tm: u32) -> vec4<f32> {
    return vec4<f32>(f32(acc[tm][tn]), f32(acc[tm + 1][tn]), f32(acc[tm + 2][tn]), f32(acc[tm + 3][tn]));
}

fn store_shmem(val: vec4<f16>, idx: u32) {
    shmem[idx] = val.x;
    shmem[idx + 1] = val.y;
    shmem[idx + 2] = val.z;
    shmem[idx + 3] = val.w;
}

fn init_shmem_src0(thread_id: u32, batch_offset: u32, offset_m: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 4; elem_idx < TILE_SRC0_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 4) {
        let tile_m = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_m = offset_m + tile_m;
        let global_k = k_outer + tile_k;
        let src0_idx = batch_offset + global_m * params.stride_01 + global_k;
        let src0_val = select( // taking a slight performance hit to avoid oob
            vec4<f16>(0.0),
            src0[src0_idx/4],
            global_m < params.m && global_k < params.k);
        store_shmem(vec4<f16>(src0_val), elem_idx);
    }
}

fn init_shmem_src1(thread_id: u32, batch_offset: u32, offset_n: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 4; elem_idx < TILE_SRC1_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 4) {
        let tile_n = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_n = offset_n + tile_n;
        let global_k = k_outer + tile_k;
        let src1_idx = batch_offset + global_n * params.stride_11 + global_k;
        let src1_val = select(
            vec4<f16>(0.0),
            src1[src1_idx/4],
            global_n < params.n && global_k < params.k);
        store_shmem(vec4<f16>(src1_val), TILE_SRC0_SHMEM + elem_idx);
    }
}



fn get_local_n(thread_id: u32) -> u32 {
    return thread_id / WORKGROUP_SIZE_M;
}
fn get_local_m(thread_id: u32) -> u32 {
    return thread_id % WORKGROUP_SIZE_M;
}

// TILE_M must be multiple of 4 for vec4 loads
const TILE_M = {{WEBGPU_TILE_M}}u;
const TILE_N = {{WEBGPU_TILE_N}}u;

override WORKGROUP_SIZE_M: u32;
override WORKGROUP_SIZE_N: u32;
override TILE_K: u32;

override TOTAL_WORKGROUP_SIZE = WORKGROUP_SIZE_M * WORKGROUP_SIZE_N;
override TILE_SRC0_SHMEM = TILE_K * WORKGROUP_SIZE_M * TILE_M;
override TILE_SRC1_SHMEM = TILE_K * WORKGROUP_SIZE_N * TILE_N;

var<workgroup> shmem: array<f16, TILE_SRC0_SHMEM + TILE_SRC1_SHMEM>;

@compute @workgroup_size(TOTAL_WORKGROUP_SIZE)
fn main(@builtin(workgroup_id) wg_id: vec3<u32>,
        @builtin(local_invocation_id) local_id: vec3<u32>) {

    let thread_id = local_id.x;
    let local_m = get_local_m(thread_id);
    let local_n = get_local_n(thread_id);

    let wg_n_count = (params.n + WORKGROUP_SIZE_N * TILE_N - 1u) / (WORKGROUP_SIZE_N * TILE_N);
    let wg_m_count = (params.m + WORKGROUP_SIZE_M * TILE_M - 1u) / (WORKGROUP_SIZE_M * TILE_M);
    let wg_per_matrix = wg_m_count * wg_n_count;

    let batch_idx = wg_id.x / wg_per_matrix;

    let wg_in_batch = wg_id.x % wg_per_matrix;
    let wg_m = wg_in_batch % wg_m_count;
    let wg_n = wg_in_batch / wg_m_count;

    let output_row_base = wg_m * WORKGROUP_SIZE_M * TILE_M + local_m * TILE_M;
    let output_col_base = wg_n * WORKGROUP_SIZE_N * TILE_N + local_n * TILE_N;

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_batch_offset = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02;
    let src1_batch_offset = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;

    let offset_m = wg_m * WORKGROUP_SIZE_M * TILE_M;
    let offset_n = wg_n * WORKGROUP_SIZE_N * TILE_N;

    var acc: array<array<f16, TILE_N>, TILE_M>;

    for (var k_outer = 0u; k_outer < params.k; k_outer += TILE_K) {

        // see mul_mat_decls.tmpl
        init_shmem_src0(thread_id, src0_batch_offset, offset_m, k_outer);
        init_shmem_src1(thread_id, src1_batch_offset, offset_n, k_outer);

        workgroupBarrier();

        let k_end = min(TILE_K, params.k - k_outer);

        for (var k_inner = 0u; k_inner < k_end; k_inner++) {
            var src0_tile: array<f16, TILE_M>;
            for (var tm = 0u; tm < TILE_M; tm++) {
                let src0_m = local_m * TILE_M + tm;
                let src0_idx = k_inner + src0_m * TILE_K;
                src0_tile[tm] = shmem[src0_idx];
            }
            for (var tn = 0u; tn < TILE_N; tn++) {
                let src1_n = local_n * TILE_N + tn;
                let src1_idx = src1_n * TILE_K + k_inner;
                let src1_val = shmem[TILE_SRC0_SHMEM + src1_idx];
                for (var tm = 0u; tm < TILE_M; tm++) {
                      acc[tm][tn] += src0_tile[tm] * src1_val;
                }
            }
        }

        workgroupBarrier();
    }

    let dst_batch_offset = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride;

    for (var tn = 0u; tn < TILE_N; tn++) {
        let global_col = output_col_base + tn;
        if (global_col < params.n) {
            for (var tm = 0u; tm < TILE_M; tm += 4) {
                let global_row = output_row_base + tm;
                if (global_row < params.m) {
                    let dst_idx = dst_batch_offset + global_col * params.m + global_row;
                    dst[dst_idx/4] = store_val(acc, tn, tm);
                }
            }
        }
    }
})";

const char* wgsl_mul_mat_reg_tile_f16_f16 = R"(enable f16;

struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<f16>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f16>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

fn store_val(acc: array<array<f16, TILE_N>, TILE_M>, tn: u32, tm: u32) -> f32 {
    return f32(acc[tm][tn]);
}

fn store_shmem(val: f16, idx: u32) {
    shmem[idx] = val;
}

fn init_shmem_src0(thread_id: u32, batch_offset: u32, offset_m: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 1; elem_idx < TILE_SRC0_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 1) {
        let tile_m = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_m = offset_m + tile_m;
        let global_k = k_outer + tile_k;
        let src0_idx = batch_offset + global_m * params.stride_01 + global_k;
        let src0_val = select( // taking a slight performance hit to avoid oob
            f16(0.0),
            src0[src0_idx/1],
            global_m < params.m && global_k < params.k);
        store_shmem(f16(src0_val), elem_idx);
    }
}

fn init_shmem_src1(thread_id: u32, batch_offset: u32, offset_n: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 1; elem_idx < TILE_SRC1_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 1) {
        let tile_n = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_n = offset_n + tile_n;
        let global_k = k_outer + tile_k;
        let src1_idx = batch_offset + global_n * params.stride_11 + global_k;
        let src1_val = select(
            f16(0.0),
            src1[src1_idx/1],
            global_n < params.n && global_k < params.k);
        store_shmem(f16(src1_val), TILE_SRC0_SHMEM + elem_idx);
    }
}



fn get_local_n(thread_id: u32) -> u32 {
    return thread_id / WORKGROUP_SIZE_M;
}
fn get_local_m(thread_id: u32) -> u32 {
    return thread_id % WORKGROUP_SIZE_M;
}

// TILE_M must be multiple of 4 for vec4 loads
const TILE_M = {{WEBGPU_TILE_M}}u;
const TILE_N = {{WEBGPU_TILE_N}}u;

override WORKGROUP_SIZE_M: u32;
override WORKGROUP_SIZE_N: u32;
override TILE_K: u32;

override TOTAL_WORKGROUP_SIZE = WORKGROUP_SIZE_M * WORKGROUP_SIZE_N;
override TILE_SRC0_SHMEM = TILE_K * WORKGROUP_SIZE_M * TILE_M;
override TILE_SRC1_SHMEM = TILE_K * WORKGROUP_SIZE_N * TILE_N;

var<workgroup> shmem: array<f16, TILE_SRC0_SHMEM + TILE_SRC1_SHMEM>;

@compute @workgroup_size(TOTAL_WORKGROUP_SIZE)
fn main(@builtin(workgroup_id) wg_id: vec3<u32>,
        @builtin(local_invocation_id) local_id: vec3<u32>) {

    let thread_id = local_id.x;
    let local_m = get_local_m(thread_id);
    let local_n = get_local_n(thread_id);

    let wg_n_count = (params.n + WORKGROUP_SIZE_N * TILE_N - 1u) / (WORKGROUP_SIZE_N * TILE_N);
    let wg_m_count = (params.m + WORKGROUP_SIZE_M * TILE_M - 1u) / (WORKGROUP_SIZE_M * TILE_M);
    let wg_per_matrix = wg_m_count * wg_n_count;

    let batch_idx = wg_id.x / wg_per_matrix;

    let wg_in_batch = wg_id.x % wg_per_matrix;
    let wg_m = wg_in_batch % wg_m_count;
    let wg_n = wg_in_batch / wg_m_count;

    let output_row_base = wg_m * WORKGROUP_SIZE_M * TILE_M + local_m * TILE_M;
    let output_col_base = wg_n * WORKGROUP_SIZE_N * TILE_N + local_n * TILE_N;

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_batch_offset = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02;
    let src1_batch_offset = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;

    let offset_m = wg_m * WORKGROUP_SIZE_M * TILE_M;
    let offset_n = wg_n * WORKGROUP_SIZE_N * TILE_N;

    var acc: array<array<f16, TILE_N>, TILE_M>;

    for (var k_outer = 0u; k_outer < params.k; k_outer += TILE_K) {

        // see mul_mat_decls.tmpl
        init_shmem_src0(thread_id, src0_batch_offset, offset_m, k_outer);
        init_shmem_src1(thread_id, src1_batch_offset, offset_n, k_outer);

        workgroupBarrier();

        let k_end = min(TILE_K, params.k - k_outer);

        for (var k_inner = 0u; k_inner < k_end; k_inner++) {
            var src0_tile: array<f16, TILE_M>;
            for (var tm = 0u; tm < TILE_M; tm++) {
                let src0_m = local_m * TILE_M + tm;
                let src0_idx = k_inner + src0_m * TILE_K;
                src0_tile[tm] = shmem[src0_idx];
            }
            for (var tn = 0u; tn < TILE_N; tn++) {
                let src1_n = local_n * TILE_N + tn;
                let src1_idx = src1_n * TILE_K + k_inner;
                let src1_val = shmem[TILE_SRC0_SHMEM + src1_idx];
                for (var tm = 0u; tm < TILE_M; tm++) {
                      acc[tm][tn] += src0_tile[tm] * src1_val;
                }
            }
        }

        workgroupBarrier();
    }

    let dst_batch_offset = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride;

    for (var tn = 0u; tn < TILE_N; tn++) {
        let global_col = output_col_base + tn;
        if (global_col < params.n) {
            for (var tm = 0u; tm < TILE_M; tm += 1) {
                let global_row = output_row_base + tm;
                if (global_row < params.m) {
                    let dst_idx = dst_batch_offset + global_col * params.m + global_row;
                    dst[dst_idx/1] = store_val(acc, tn, tm);
                }
            }
        }
    }
})";

const char* wgsl_mul_mat_reg_tile_q4_0_f32_vec = R"(enable f16;

struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<f16>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<vec4<f32>>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<vec4<f32>>; // M rows, N columns (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

fn store_val(acc: array<array<f16, TILE_N>, TILE_M>, tn: u32, tm: u32) -> vec4<f32> {
    return vec4<f32>(f32(acc[tm][tn]), f32(acc[tm + 1][tn]), f32(acc[tm + 2][tn]), f32(acc[tm + 3][tn]));
}

fn store_shmem(val: vec4<f16>, idx: u32) {
    shmem[idx] = val.x;
    shmem[idx + 1] = val.y;
    shmem[idx + 2] = val.z;
    shmem[idx + 3] = val.w;
}

const BLOCK_SIZE = 32u;
// the number of blocks per k-tile. Note that this currently only works if TILE_K is a multiple of BLOCK_SIZE, which may need to be rethought for larger quantized types.
override BLOCKS_K = TILE_K/BLOCK_SIZE;
const NQ = 16u;
const F16_PER_BLOCK = 9u; // 1 scale + 8x4 packed weights
const WEIGHTS_PER_F16 = 4u; // 4 weights per f16
const F16_PER_THREAD = NQ / WEIGHTS_PER_F16;

fn init_shmem_src0(thread_id: u32, batch_offset: u32, offset_m: u32, k_outer: u32) {
    for (var i = thread_id * NQ; i < TILE_SRC0_SHMEM; i += TOTAL_WORKGROUP_SIZE * NQ) {
        let blck_idx = i / BLOCK_SIZE;
        let block_offset = (i % BLOCK_SIZE) / WEIGHTS_PER_F16;
        let shmem_idx = blck_idx * BLOCK_SIZE + block_offset * 2u;

        let tile_m = blck_idx / BLOCKS_K;
        let global_m = offset_m + tile_m;
        let block_k = blck_idx % BLOCKS_K;
        let global_k = k_outer / BLOCK_SIZE + block_k;

        if (global_m < params.m && global_k < params.k / BLOCK_SIZE) {
            let src0_idx = batch_offset + global_m * params.stride_01 + global_k;
            let scale_idx = src0_idx * F16_PER_BLOCK;
            let d = src0[scale_idx];

            for (var j = 0u; j < F16_PER_THREAD; j += 2) {
                let q_0 = src0[scale_idx + 1u + block_offset + j];
                let q_1 = src0[scale_idx + 1u + block_offset + j + 1];

                let q_packed = bitcast<u32>(vec2(q_0, q_1));
                for (var k = 0u; k < 4u; k++) {
                    let q_byte = get_byte(q_packed, k);
                    let q_hi = (f16((q_byte >> 4) & 0xF) - 8.0) * d;
                    let q_lo = (f16(q_byte & 0xF) - 8.0) * d;
                    shmem[shmem_idx + j * 2 + k] = q_lo;
                    shmem[shmem_idx + j * 2 + k + 16u] = q_hi;
                }
            }
        }
    }
}

fn init_shmem_src1(thread_id: u32, batch_offset: u32, offset_n: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 4; elem_idx < TILE_SRC1_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 4) {
        let tile_n = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_n = offset_n + tile_n;
        let global_k = k_outer + tile_k;
        let src1_idx = batch_offset + global_n * params.stride_11 + global_k;
        let src1_val = select(
            vec4<f32>(0.0),
            src1[src1_idx/4],
            global_n < params.n && global_k < params.k);
        store_shmem(vec4<f16>(src1_val), TILE_SRC0_SHMEM + elem_idx);
    }
}



fn get_local_n(thread_id: u32) -> u32 {
    return thread_id / WORKGROUP_SIZE_M;
}
fn get_local_m(thread_id: u32) -> u32 {
    return thread_id % WORKGROUP_SIZE_M;
}

// TILE_M must be multiple of 4 for vec4 loads
const TILE_M = {{WEBGPU_TILE_M}}u;
const TILE_N = {{WEBGPU_TILE_N}}u;

override WORKGROUP_SIZE_M: u32;
override WORKGROUP_SIZE_N: u32;
override TILE_K: u32;

override TOTAL_WORKGROUP_SIZE = WORKGROUP_SIZE_M * WORKGROUP_SIZE_N;
override TILE_SRC0_SHMEM = TILE_K * WORKGROUP_SIZE_M * TILE_M;
override TILE_SRC1_SHMEM = TILE_K * WORKGROUP_SIZE_N * TILE_N;

var<workgroup> shmem: array<f16, TILE_SRC0_SHMEM + TILE_SRC1_SHMEM>;

@compute @workgroup_size(TOTAL_WORKGROUP_SIZE)
fn main(@builtin(workgroup_id) wg_id: vec3<u32>,
        @builtin(local_invocation_id) local_id: vec3<u32>) {

    let thread_id = local_id.x;
    let local_m = get_local_m(thread_id);
    let local_n = get_local_n(thread_id);

    let wg_n_count = (params.n + WORKGROUP_SIZE_N * TILE_N - 1u) / (WORKGROUP_SIZE_N * TILE_N);
    let wg_m_count = (params.m + WORKGROUP_SIZE_M * TILE_M - 1u) / (WORKGROUP_SIZE_M * TILE_M);
    let wg_per_matrix = wg_m_count * wg_n_count;

    let batch_idx = wg_id.x / wg_per_matrix;

    let wg_in_batch = wg_id.x % wg_per_matrix;
    let wg_m = wg_in_batch % wg_m_count;
    let wg_n = wg_in_batch / wg_m_count;

    let output_row_base = wg_m * WORKGROUP_SIZE_M * TILE_M + local_m * TILE_M;
    let output_col_base = wg_n * WORKGROUP_SIZE_N * TILE_N + local_n * TILE_N;

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_batch_offset = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02;
    let src1_batch_offset = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;

    let offset_m = wg_m * WORKGROUP_SIZE_M * TILE_M;
    let offset_n = wg_n * WORKGROUP_SIZE_N * TILE_N;

    var acc: array<array<f16, TILE_N>, TILE_M>;

    for (var k_outer = 0u; k_outer < params.k; k_outer += TILE_K) {

        // see mul_mat_decls.tmpl
        init_shmem_src0(thread_id, src0_batch_offset, offset_m, k_outer);
        init_shmem_src1(thread_id, src1_batch_offset, offset_n, k_outer);

        workgroupBarrier();

        let k_end = min(TILE_K, params.k - k_outer);

        for (var k_inner = 0u; k_inner < k_end; k_inner++) {
            var src0_tile: array<f16, TILE_M>;
            for (var tm = 0u; tm < TILE_M; tm++) {
                let src0_m = local_m * TILE_M + tm;
                let src0_idx = k_inner + src0_m * TILE_K;
                src0_tile[tm] = shmem[src0_idx];
            }
            for (var tn = 0u; tn < TILE_N; tn++) {
                let src1_n = local_n * TILE_N + tn;
                let src1_idx = src1_n * TILE_K + k_inner;
                let src1_val = shmem[TILE_SRC0_SHMEM + src1_idx];
                for (var tm = 0u; tm < TILE_M; tm++) {
                      acc[tm][tn] += src0_tile[tm] * src1_val;
                }
            }
        }

        workgroupBarrier();
    }

    let dst_batch_offset = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride;

    for (var tn = 0u; tn < TILE_N; tn++) {
        let global_col = output_col_base + tn;
        if (global_col < params.n) {
            for (var tm = 0u; tm < TILE_M; tm += 4) {
                let global_row = output_row_base + tm;
                if (global_row < params.m) {
                    let dst_idx = dst_batch_offset + global_col * params.m + global_row;
                    dst[dst_idx/4] = store_val(acc, tn, tm);
                }
            }
        }
    }
})";

const char* wgsl_mul_mat_reg_tile_q4_0_f32 = R"(enable f16;

struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<f16>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

fn store_val(acc: array<array<f16, TILE_N>, TILE_M>, tn: u32, tm: u32) -> f32 {
    return f32(acc[tm][tn]);
}

fn store_shmem(val: f16, idx: u32) {
    shmem[idx] = val;
}

const BLOCK_SIZE = 32u;
// the number of blocks per k-tile. Note that this currently only works if TILE_K is a multiple of BLOCK_SIZE, which may need to be rethought for larger quantized types.
override BLOCKS_K = TILE_K/BLOCK_SIZE;
const NQ = 16u;
const F16_PER_BLOCK = 9u; // 1 scale + 8x4 packed weights
const WEIGHTS_PER_F16 = 4u; // 4 weights per f16
const F16_PER_THREAD = NQ / WEIGHTS_PER_F16;

fn init_shmem_src0(thread_id: u32, batch_offset: u32, offset_m: u32, k_outer: u32) {
    for (var i = thread_id * NQ; i < TILE_SRC0_SHMEM; i += TOTAL_WORKGROUP_SIZE * NQ) {
        let blck_idx = i / BLOCK_SIZE;
        let block_offset = (i % BLOCK_SIZE) / WEIGHTS_PER_F16;
        let shmem_idx = blck_idx * BLOCK_SIZE + block_offset * 2u;

        let tile_m = blck_idx / BLOCKS_K;
        let global_m = offset_m + tile_m;
        let block_k = blck_idx % BLOCKS_K;
        let global_k = k_outer / BLOCK_SIZE + block_k;

        if (global_m < params.m && global_k < params.k / BLOCK_SIZE) {
            let src0_idx = batch_offset + global_m * params.stride_01 + global_k;
            let scale_idx = src0_idx * F16_PER_BLOCK;
            let d = src0[scale_idx];

            for (var j = 0u; j < F16_PER_THREAD; j += 2) {
                let q_0 = src0[scale_idx + 1u + block_offset + j];
                let q_1 = src0[scale_idx + 1u + block_offset + j + 1];

                let q_packed = bitcast<u32>(vec2(q_0, q_1));
                for (var k = 0u; k < 4u; k++) {
                    let q_byte = get_byte(q_packed, k);
                    let q_hi = (f16((q_byte >> 4) & 0xF) - 8.0) * d;
                    let q_lo = (f16(q_byte & 0xF) - 8.0) * d;
                    shmem[shmem_idx + j * 2 + k] = q_lo;
                    shmem[shmem_idx + j * 2 + k + 16u] = q_hi;
                }
            }
        }
    }
}

fn init_shmem_src1(thread_id: u32, batch_offset: u32, offset_n: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 1; elem_idx < TILE_SRC1_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 1) {
        let tile_n = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_n = offset_n + tile_n;
        let global_k = k_outer + tile_k;
        let src1_idx = batch_offset + global_n * params.stride_11 + global_k;
        let src1_val = select(
            f32(0.0),
            src1[src1_idx/1],
            global_n < params.n && global_k < params.k);
        store_shmem(f16(src1_val), TILE_SRC0_SHMEM + elem_idx);
    }
}



fn get_local_n(thread_id: u32) -> u32 {
    return thread_id / WORKGROUP_SIZE_M;
}
fn get_local_m(thread_id: u32) -> u32 {
    return thread_id % WORKGROUP_SIZE_M;
}

// TILE_M must be multiple of 4 for vec4 loads
const TILE_M = {{WEBGPU_TILE_M}}u;
const TILE_N = {{WEBGPU_TILE_N}}u;

override WORKGROUP_SIZE_M: u32;
override WORKGROUP_SIZE_N: u32;
override TILE_K: u32;

override TOTAL_WORKGROUP_SIZE = WORKGROUP_SIZE_M * WORKGROUP_SIZE_N;
override TILE_SRC0_SHMEM = TILE_K * WORKGROUP_SIZE_M * TILE_M;
override TILE_SRC1_SHMEM = TILE_K * WORKGROUP_SIZE_N * TILE_N;

var<workgroup> shmem: array<f16, TILE_SRC0_SHMEM + TILE_SRC1_SHMEM>;

@compute @workgroup_size(TOTAL_WORKGROUP_SIZE)
fn main(@builtin(workgroup_id) wg_id: vec3<u32>,
        @builtin(local_invocation_id) local_id: vec3<u32>) {

    let thread_id = local_id.x;
    let local_m = get_local_m(thread_id);
    let local_n = get_local_n(thread_id);

    let wg_n_count = (params.n + WORKGROUP_SIZE_N * TILE_N - 1u) / (WORKGROUP_SIZE_N * TILE_N);
    let wg_m_count = (params.m + WORKGROUP_SIZE_M * TILE_M - 1u) / (WORKGROUP_SIZE_M * TILE_M);
    let wg_per_matrix = wg_m_count * wg_n_count;

    let batch_idx = wg_id.x / wg_per_matrix;

    let wg_in_batch = wg_id.x % wg_per_matrix;
    let wg_m = wg_in_batch % wg_m_count;
    let wg_n = wg_in_batch / wg_m_count;

    let output_row_base = wg_m * WORKGROUP_SIZE_M * TILE_M + local_m * TILE_M;
    let output_col_base = wg_n * WORKGROUP_SIZE_N * TILE_N + local_n * TILE_N;

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_batch_offset = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02;
    let src1_batch_offset = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;

    let offset_m = wg_m * WORKGROUP_SIZE_M * TILE_M;
    let offset_n = wg_n * WORKGROUP_SIZE_N * TILE_N;

    var acc: array<array<f16, TILE_N>, TILE_M>;

    for (var k_outer = 0u; k_outer < params.k; k_outer += TILE_K) {

        // see mul_mat_decls.tmpl
        init_shmem_src0(thread_id, src0_batch_offset, offset_m, k_outer);
        init_shmem_src1(thread_id, src1_batch_offset, offset_n, k_outer);

        workgroupBarrier();

        let k_end = min(TILE_K, params.k - k_outer);

        for (var k_inner = 0u; k_inner < k_end; k_inner++) {
            var src0_tile: array<f16, TILE_M>;
            for (var tm = 0u; tm < TILE_M; tm++) {
                let src0_m = local_m * TILE_M + tm;
                let src0_idx = k_inner + src0_m * TILE_K;
                src0_tile[tm] = shmem[src0_idx];
            }
            for (var tn = 0u; tn < TILE_N; tn++) {
                let src1_n = local_n * TILE_N + tn;
                let src1_idx = src1_n * TILE_K + k_inner;
                let src1_val = shmem[TILE_SRC0_SHMEM + src1_idx];
                for (var tm = 0u; tm < TILE_M; tm++) {
                      acc[tm][tn] += src0_tile[tm] * src1_val;
                }
            }
        }

        workgroupBarrier();
    }

    let dst_batch_offset = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride;

    for (var tn = 0u; tn < TILE_N; tn++) {
        let global_col = output_col_base + tn;
        if (global_col < params.n) {
            for (var tm = 0u; tm < TILE_M; tm += 1) {
                let global_row = output_row_base + tm;
                if (global_row < params.m) {
                    let dst_idx = dst_batch_offset + global_col * params.m + global_row;
                    dst[dst_idx/1] = store_val(acc, tn, tm);
                }
            }
        }
    }
})";

const char* wgsl_mul_mat_subgroup_matrix_f32_f32_vec = R"(diagnostic(off, chromium.subgroup_matrix_uniformity);
enable f16;
enable subgroups;
enable chromium_experimental_subgroup_matrix;

struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<vec4<f32>>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<vec4<f32>>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<vec4<f32>>; // M rows, N columns (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

fn store_dst(shmem_idx: u32, dst_idx: u32) {
    dst[dst_idx] = vec4<f32>(
        f32(shmem[shmem_idx]),
        f32(shmem[shmem_idx + 1]),
        f32(shmem[shmem_idx + 2]),
        f32(shmem[shmem_idx + 3])
    );
}

fn store_shmem(val: vec4<f16>, idx: u32) {
    shmem[idx] = val.x;
    shmem[idx + 1] = val.y;
    shmem[idx + 2] = val.z;
    shmem[idx + 3] = val.w;
}

fn init_shmem_src0(thread_id: u32, batch_offset: u32, offset_m: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 4; elem_idx < TILE_SRC0_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 4) {
        let tile_m = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_m = offset_m + tile_m;
        let global_k = k_outer + tile_k;
        let src0_idx = batch_offset + global_m * params.stride_01 + global_k;
        let src0_val = select( // taking a slight performance hit to avoid oob
            vec4<f32>(0.0),
            src0[src0_idx/4],
            global_m < params.m && global_k < params.k);
        store_shmem(vec4<f16>(src0_val), elem_idx);
    }
}

fn init_shmem_src1(thread_id: u32, batch_offset: u32, offset_n: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 4; elem_idx < TILE_SRC1_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 4) {
        let tile_n = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_n = offset_n + tile_n;
        let global_k = k_outer + tile_k;
        let src1_idx = batch_offset + global_n * params.stride_11 + global_k;
        let src1_val = select(
            vec4<f32>(0.0),
            src1[src1_idx/4],
            global_n < params.n && global_k < params.k);
        store_shmem(vec4<f16>(src1_val), TILE_SRC0_SHMEM + elem_idx);
    }
}



// Note: These are string interpolated at build time, cannot use override constants due to limitations in
// current Dawn version type definitions/matrix load requirements for constant memory sizes.
const SUBGROUP_M = {{WEBGPU_SUBGROUP_M}}u;
const SUBGROUP_N = {{WEBGPU_SUBGROUP_N}}u;
// For portability we assume the max subgroup size, meaning some subgroups will be masked out if the
// runtime subgroup size is smaller.
const MAX_SUBGROUP_SIZE = {{WEBGPU_MAX_SUBGROUP_SIZE}}u;

const EXPECTED_SUBGROUPS = SUBGROUP_M * SUBGROUP_N;

const SUBGROUP_MATRIX_M_SIZE = {{WEBGPU_SG_MAT_M_SIZE}}u;
const SUBGROUP_MATRIX_N_SIZE = {{WEBGPU_SG_MAT_N_SIZE}}u;
const SUBGROUP_MATRIX_K_SIZE = {{WEBGPU_SG_MAT_K_SIZE}}u;

const SUBGROUP_MATRIX_M = {{WEBGPU_SUBGROUP_MATRIX_M}}u;
const SUBGROUP_MATRIX_N = {{WEBGPU_SUBGROUP_MATRIX_N}}u;

const TILE_K = {{WEBGPU_TILE_K}}u;

const WG_M_SG_TILE_SIZE = SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
const WG_N_SG_TILE_SIZE = SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

const TOTAL_WORKGROUP_SIZE = SUBGROUP_M * SUBGROUP_N * MAX_SUBGROUP_SIZE;
const TILE_SRC0_SHMEM = TILE_K * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
const TILE_SRC1_SHMEM = TILE_K * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

const SG_MAT_ACCUM_SHMEM = SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_M_SIZE * SUBGROUP_MATRIX_N_SIZE;

// We reuse shmem for accumulation matrices
const SHMEM_SIZE = max(TILE_SRC0_SHMEM + TILE_SRC1_SHMEM, SG_MAT_ACCUM_SHMEM);

var<workgroup> shmem: array<f16, SHMEM_SIZE>;

@compute @workgroup_size(TOTAL_WORKGROUP_SIZE)
fn main(@builtin(workgroup_id) wg_id: vec3<u32>,
        @builtin(local_invocation_id) local_id: vec3<u32>,
        @builtin(subgroup_id) subgroup_id: u32) {

    let thread_id = local_id.x;
    let subgroup_m = subgroup_id % SUBGROUP_M;
    let subgroup_n = subgroup_id / SUBGROUP_M;

    let wg_m_count = (params.m + WG_M_SG_TILE_SIZE - 1) / WG_M_SG_TILE_SIZE;
    let wg_n_count = (params.n + WG_N_SG_TILE_SIZE - 1) / WG_N_SG_TILE_SIZE;
    let wg_per_matrix = wg_m_count * wg_n_count;

    let batch_idx = wg_id.x / wg_per_matrix;

    let wg_in_batch = wg_id.x % wg_per_matrix;
    let wg_m = wg_in_batch % wg_m_count;
    let wg_n = wg_in_batch / wg_m_count;

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_batch_offset = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02;
    let src1_batch_offset = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;

    let offset_m = wg_m * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
    let offset_n = wg_n * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

    var acc_sg_mat : array<array<subgroup_matrix_result<f16, SUBGROUP_MATRIX_N_SIZE, SUBGROUP_MATRIX_M_SIZE>, SUBGROUP_MATRIX_N>, SUBGROUP_MATRIX_M>;

    for (var k_outer = 0u; k_outer < params.k; k_outer += TILE_K) {

        // see mul_mat_decls.tmpl
        init_shmem_src0(thread_id, src0_batch_offset, offset_m, k_outer);
        init_shmem_src1(thread_id, src1_batch_offset, offset_n, k_outer);

        workgroupBarrier();

        if (subgroup_id < EXPECTED_SUBGROUPS) {

            for (var k_inner = 0u; k_inner < TILE_K; k_inner += SUBGROUP_MATRIX_K_SIZE) {

                let src0_shmem_idx_base = subgroup_m * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE * TILE_K + k_inner;
                var src0_sg_mats: array<subgroup_matrix_left<f16, SUBGROUP_MATRIX_K_SIZE, SUBGROUP_MATRIX_M_SIZE>, SUBGROUP_MATRIX_M>;
                for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                    src0_sg_mats[m] = subgroupMatrixLoad<subgroup_matrix_left<f16, SUBGROUP_MATRIX_K_SIZE, SUBGROUP_MATRIX_M_SIZE>>(
                        &shmem,
                        src0_shmem_idx_base + m * SUBGROUP_MATRIX_M_SIZE * TILE_K,
                        false,
                        TILE_K
                    );
                }

                let src1_shmem_idx_base = TILE_SRC0_SHMEM + subgroup_n * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE * TILE_K + k_inner;
                for (var n = 0u; n < SUBGROUP_MATRIX_N; n++) {
                    let src1_sg_mat = subgroupMatrixLoad<subgroup_matrix_right<f16, SUBGROUP_MATRIX_N_SIZE, SUBGROUP_MATRIX_K_SIZE>>(
                        &shmem,
                        src1_shmem_idx_base + n * SUBGROUP_MATRIX_N_SIZE * TILE_K,
                        true,
                        TILE_K
                    );
                    for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                        acc_sg_mat[m][n] = subgroupMatrixMultiplyAccumulate(src0_sg_mats[m], src1_sg_mat, acc_sg_mat[m][n]);
                    }
                }
            }
        }

        workgroupBarrier();
    }

    let dst_batch_offset = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride;

    // Stage the subgroup matrix tiles into shared memory
    // This uses WG_M_SG_TILE_SIZE as the stride (number of columns in the workgroup tile).
    let WG_TILE_STRIDE = WG_M_SG_TILE_SIZE;
    let tile_row_base_local = subgroup_n * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;
    let tile_col_base_local = subgroup_m * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;

    if (subgroup_id < EXPECTED_SUBGROUPS) { // 2-5% performance hit :(
        for (var n = 0u; n < SUBGROUP_MATRIX_N; n++) {
            for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                let local_row = tile_row_base_local + n * SUBGROUP_MATRIX_N_SIZE;
                let local_col = tile_col_base_local + m * SUBGROUP_MATRIX_M_SIZE;
                let out_base = local_row * WG_TILE_STRIDE + local_col;
                subgroupMatrixStore(&shmem, out_base, acc_sg_mat[m][n], true, WG_TILE_STRIDE);
            }
        }
    }

    workgroupBarrier();

    // Cooperative write: iterate over the entire workgroup tile
    let tile_rows = WG_N_SG_TILE_SIZE;
    let tile_cols = WG_M_SG_TILE_SIZE;
    let total_tile_elems = tile_rows * tile_cols;
    let tile_dst_row_base = wg_m * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
    let tile_dst_col_base = wg_n * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

    for (var idx = thread_id * 4; idx < total_tile_elems; idx += TOTAL_WORKGROUP_SIZE * 4) {
        let local_row = idx % WG_TILE_STRIDE;
        let local_col = idx / WG_TILE_STRIDE;

        let global_row = tile_dst_row_base + local_row;
        let global_col = tile_dst_col_base + local_col;

        if (global_col < params.n && global_row < params.m) {
            let dst_idx = dst_batch_offset + global_col * params.m + global_row;
            store_dst(idx, dst_idx/4);
        }
    }
})";

const char* wgsl_mul_mat_subgroup_matrix_f32_f32 = R"(diagnostic(off, chromium.subgroup_matrix_uniformity);
enable f16;
enable subgroups;
enable chromium_experimental_subgroup_matrix;

struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<f32>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

fn store_dst(shmem_idx: u32, dst_idx: u32) {
    dst[dst_idx] = f32(shmem[shmem_idx]);
}

fn store_shmem(val: f16, idx: u32) {
    shmem[idx] = val;
}

fn init_shmem_src0(thread_id: u32, batch_offset: u32, offset_m: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 1; elem_idx < TILE_SRC0_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 1) {
        let tile_m = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_m = offset_m + tile_m;
        let global_k = k_outer + tile_k;
        let src0_idx = batch_offset + global_m * params.stride_01 + global_k;
        let src0_val = select( // taking a slight performance hit to avoid oob
            f32(0.0),
            src0[src0_idx/1],
            global_m < params.m && global_k < params.k);
        store_shmem(f16(src0_val), elem_idx);
    }
}

fn init_shmem_src1(thread_id: u32, batch_offset: u32, offset_n: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 1; elem_idx < TILE_SRC1_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 1) {
        let tile_n = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_n = offset_n + tile_n;
        let global_k = k_outer + tile_k;
        let src1_idx = batch_offset + global_n * params.stride_11 + global_k;
        let src1_val = select(
            f32(0.0),
            src1[src1_idx/1],
            global_n < params.n && global_k < params.k);
        store_shmem(f16(src1_val), TILE_SRC0_SHMEM + elem_idx);
    }
}



// Note: These are string interpolated at build time, cannot use override constants due to limitations in
// current Dawn version type definitions/matrix load requirements for constant memory sizes.
const SUBGROUP_M = {{WEBGPU_SUBGROUP_M}}u;
const SUBGROUP_N = {{WEBGPU_SUBGROUP_N}}u;
// For portability we assume the max subgroup size, meaning some subgroups will be masked out if the
// runtime subgroup size is smaller.
const MAX_SUBGROUP_SIZE = {{WEBGPU_MAX_SUBGROUP_SIZE}}u;

const EXPECTED_SUBGROUPS = SUBGROUP_M * SUBGROUP_N;

const SUBGROUP_MATRIX_M_SIZE = {{WEBGPU_SG_MAT_M_SIZE}}u;
const SUBGROUP_MATRIX_N_SIZE = {{WEBGPU_SG_MAT_N_SIZE}}u;
const SUBGROUP_MATRIX_K_SIZE = {{WEBGPU_SG_MAT_K_SIZE}}u;

const SUBGROUP_MATRIX_M = {{WEBGPU_SUBGROUP_MATRIX_M}}u;
const SUBGROUP_MATRIX_N = {{WEBGPU_SUBGROUP_MATRIX_N}}u;

const TILE_K = {{WEBGPU_TILE_K}}u;

const WG_M_SG_TILE_SIZE = SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
const WG_N_SG_TILE_SIZE = SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

const TOTAL_WORKGROUP_SIZE = SUBGROUP_M * SUBGROUP_N * MAX_SUBGROUP_SIZE;
const TILE_SRC0_SHMEM = TILE_K * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
const TILE_SRC1_SHMEM = TILE_K * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

const SG_MAT_ACCUM_SHMEM = SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_M_SIZE * SUBGROUP_MATRIX_N_SIZE;

// We reuse shmem for accumulation matrices
const SHMEM_SIZE = max(TILE_SRC0_SHMEM + TILE_SRC1_SHMEM, SG_MAT_ACCUM_SHMEM);

var<workgroup> shmem: array<f16, SHMEM_SIZE>;

@compute @workgroup_size(TOTAL_WORKGROUP_SIZE)
fn main(@builtin(workgroup_id) wg_id: vec3<u32>,
        @builtin(local_invocation_id) local_id: vec3<u32>,
        @builtin(subgroup_id) subgroup_id: u32) {

    let thread_id = local_id.x;
    let subgroup_m = subgroup_id % SUBGROUP_M;
    let subgroup_n = subgroup_id / SUBGROUP_M;

    let wg_m_count = (params.m + WG_M_SG_TILE_SIZE - 1) / WG_M_SG_TILE_SIZE;
    let wg_n_count = (params.n + WG_N_SG_TILE_SIZE - 1) / WG_N_SG_TILE_SIZE;
    let wg_per_matrix = wg_m_count * wg_n_count;

    let batch_idx = wg_id.x / wg_per_matrix;

    let wg_in_batch = wg_id.x % wg_per_matrix;
    let wg_m = wg_in_batch % wg_m_count;
    let wg_n = wg_in_batch / wg_m_count;

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_batch_offset = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02;
    let src1_batch_offset = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;

    let offset_m = wg_m * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
    let offset_n = wg_n * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

    var acc_sg_mat : array<array<subgroup_matrix_result<f16, SUBGROUP_MATRIX_N_SIZE, SUBGROUP_MATRIX_M_SIZE>, SUBGROUP_MATRIX_N>, SUBGROUP_MATRIX_M>;

    for (var k_outer = 0u; k_outer < params.k; k_outer += TILE_K) {

        // see mul_mat_decls.tmpl
        init_shmem_src0(thread_id, src0_batch_offset, offset_m, k_outer);
        init_shmem_src1(thread_id, src1_batch_offset, offset_n, k_outer);

        workgroupBarrier();

        if (subgroup_id < EXPECTED_SUBGROUPS) {

            for (var k_inner = 0u; k_inner < TILE_K; k_inner += SUBGROUP_MATRIX_K_SIZE) {

                let src0_shmem_idx_base = subgroup_m * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE * TILE_K + k_inner;
                var src0_sg_mats: array<subgroup_matrix_left<f16, SUBGROUP_MATRIX_K_SIZE, SUBGROUP_MATRIX_M_SIZE>, SUBGROUP_MATRIX_M>;
                for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                    src0_sg_mats[m] = subgroupMatrixLoad<subgroup_matrix_left<f16, SUBGROUP_MATRIX_K_SIZE, SUBGROUP_MATRIX_M_SIZE>>(
                        &shmem,
                        src0_shmem_idx_base + m * SUBGROUP_MATRIX_M_SIZE * TILE_K,
                        false,
                        TILE_K
                    );
                }

                let src1_shmem_idx_base = TILE_SRC0_SHMEM + subgroup_n * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE * TILE_K + k_inner;
                for (var n = 0u; n < SUBGROUP_MATRIX_N; n++) {
                    let src1_sg_mat = subgroupMatrixLoad<subgroup_matrix_right<f16, SUBGROUP_MATRIX_N_SIZE, SUBGROUP_MATRIX_K_SIZE>>(
                        &shmem,
                        src1_shmem_idx_base + n * SUBGROUP_MATRIX_N_SIZE * TILE_K,
                        true,
                        TILE_K
                    );
                    for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                        acc_sg_mat[m][n] = subgroupMatrixMultiplyAccumulate(src0_sg_mats[m], src1_sg_mat, acc_sg_mat[m][n]);
                    }
                }
            }
        }

        workgroupBarrier();
    }

    let dst_batch_offset = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride;

    // Stage the subgroup matrix tiles into shared memory
    // This uses WG_M_SG_TILE_SIZE as the stride (number of columns in the workgroup tile).
    let WG_TILE_STRIDE = WG_M_SG_TILE_SIZE;
    let tile_row_base_local = subgroup_n * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;
    let tile_col_base_local = subgroup_m * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;

    if (subgroup_id < EXPECTED_SUBGROUPS) { // 2-5% performance hit :(
        for (var n = 0u; n < SUBGROUP_MATRIX_N; n++) {
            for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                let local_row = tile_row_base_local + n * SUBGROUP_MATRIX_N_SIZE;
                let local_col = tile_col_base_local + m * SUBGROUP_MATRIX_M_SIZE;
                let out_base = local_row * WG_TILE_STRIDE + local_col;
                subgroupMatrixStore(&shmem, out_base, acc_sg_mat[m][n], true, WG_TILE_STRIDE);
            }
        }
    }

    workgroupBarrier();

    // Cooperative write: iterate over the entire workgroup tile
    let tile_rows = WG_N_SG_TILE_SIZE;
    let tile_cols = WG_M_SG_TILE_SIZE;
    let total_tile_elems = tile_rows * tile_cols;
    let tile_dst_row_base = wg_m * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
    let tile_dst_col_base = wg_n * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

    for (var idx = thread_id * 1; idx < total_tile_elems; idx += TOTAL_WORKGROUP_SIZE * 1) {
        let local_row = idx % WG_TILE_STRIDE;
        let local_col = idx / WG_TILE_STRIDE;

        let global_row = tile_dst_row_base + local_row;
        let global_col = tile_dst_col_base + local_col;

        if (global_col < params.n && global_row < params.m) {
            let dst_idx = dst_batch_offset + global_col * params.m + global_row;
            store_dst(idx, dst_idx/1);
        }
    }
})";

const char* wgsl_mul_mat_subgroup_matrix_f16_f32_vec = R"(diagnostic(off, chromium.subgroup_matrix_uniformity);
enable f16;
enable subgroups;
enable chromium_experimental_subgroup_matrix;

struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<vec4<f16>>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<vec4<f32>>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<vec4<f32>>; // M rows, N columns (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

fn store_dst(shmem_idx: u32, dst_idx: u32) {
    dst[dst_idx] = vec4<f32>(
        f32(shmem[shmem_idx]),
        f32(shmem[shmem_idx + 1]),
        f32(shmem[shmem_idx + 2]),
        f32(shmem[shmem_idx + 3])
    );
}

fn store_shmem(val: vec4<f16>, idx: u32) {
    shmem[idx] = val.x;
    shmem[idx + 1] = val.y;
    shmem[idx + 2] = val.z;
    shmem[idx + 3] = val.w;
}

fn init_shmem_src0(thread_id: u32, batch_offset: u32, offset_m: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 4; elem_idx < TILE_SRC0_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 4) {
        let tile_m = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_m = offset_m + tile_m;
        let global_k = k_outer + tile_k;
        let src0_idx = batch_offset + global_m * params.stride_01 + global_k;
        let src0_val = select( // taking a slight performance hit to avoid oob
            vec4<f16>(0.0),
            src0[src0_idx/4],
            global_m < params.m && global_k < params.k);
        store_shmem(vec4<f16>(src0_val), elem_idx);
    }
}

fn init_shmem_src1(thread_id: u32, batch_offset: u32, offset_n: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 4; elem_idx < TILE_SRC1_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 4) {
        let tile_n = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_n = offset_n + tile_n;
        let global_k = k_outer + tile_k;
        let src1_idx = batch_offset + global_n * params.stride_11 + global_k;
        let src1_val = select(
            vec4<f32>(0.0),
            src1[src1_idx/4],
            global_n < params.n && global_k < params.k);
        store_shmem(vec4<f16>(src1_val), TILE_SRC0_SHMEM + elem_idx);
    }
}



// Note: These are string interpolated at build time, cannot use override constants due to limitations in
// current Dawn version type definitions/matrix load requirements for constant memory sizes.
const SUBGROUP_M = {{WEBGPU_SUBGROUP_M}}u;
const SUBGROUP_N = {{WEBGPU_SUBGROUP_N}}u;
// For portability we assume the max subgroup size, meaning some subgroups will be masked out if the
// runtime subgroup size is smaller.
const MAX_SUBGROUP_SIZE = {{WEBGPU_MAX_SUBGROUP_SIZE}}u;

const EXPECTED_SUBGROUPS = SUBGROUP_M * SUBGROUP_N;

const SUBGROUP_MATRIX_M_SIZE = {{WEBGPU_SG_MAT_M_SIZE}}u;
const SUBGROUP_MATRIX_N_SIZE = {{WEBGPU_SG_MAT_N_SIZE}}u;
const SUBGROUP_MATRIX_K_SIZE = {{WEBGPU_SG_MAT_K_SIZE}}u;

const SUBGROUP_MATRIX_M = {{WEBGPU_SUBGROUP_MATRIX_M}}u;
const SUBGROUP_MATRIX_N = {{WEBGPU_SUBGROUP_MATRIX_N}}u;

const TILE_K = {{WEBGPU_TILE_K}}u;

const WG_M_SG_TILE_SIZE = SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
const WG_N_SG_TILE_SIZE = SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

const TOTAL_WORKGROUP_SIZE = SUBGROUP_M * SUBGROUP_N * MAX_SUBGROUP_SIZE;
const TILE_SRC0_SHMEM = TILE_K * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
const TILE_SRC1_SHMEM = TILE_K * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

const SG_MAT_ACCUM_SHMEM = SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_M_SIZE * SUBGROUP_MATRIX_N_SIZE;

// We reuse shmem for accumulation matrices
const SHMEM_SIZE = max(TILE_SRC0_SHMEM + TILE_SRC1_SHMEM, SG_MAT_ACCUM_SHMEM);

var<workgroup> shmem: array<f16, SHMEM_SIZE>;

@compute @workgroup_size(TOTAL_WORKGROUP_SIZE)
fn main(@builtin(workgroup_id) wg_id: vec3<u32>,
        @builtin(local_invocation_id) local_id: vec3<u32>,
        @builtin(subgroup_id) subgroup_id: u32) {

    let thread_id = local_id.x;
    let subgroup_m = subgroup_id % SUBGROUP_M;
    let subgroup_n = subgroup_id / SUBGROUP_M;

    let wg_m_count = (params.m + WG_M_SG_TILE_SIZE - 1) / WG_M_SG_TILE_SIZE;
    let wg_n_count = (params.n + WG_N_SG_TILE_SIZE - 1) / WG_N_SG_TILE_SIZE;
    let wg_per_matrix = wg_m_count * wg_n_count;

    let batch_idx = wg_id.x / wg_per_matrix;

    let wg_in_batch = wg_id.x % wg_per_matrix;
    let wg_m = wg_in_batch % wg_m_count;
    let wg_n = wg_in_batch / wg_m_count;

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_batch_offset = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02;
    let src1_batch_offset = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;

    let offset_m = wg_m * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
    let offset_n = wg_n * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

    var acc_sg_mat : array<array<subgroup_matrix_result<f16, SUBGROUP_MATRIX_N_SIZE, SUBGROUP_MATRIX_M_SIZE>, SUBGROUP_MATRIX_N>, SUBGROUP_MATRIX_M>;

    for (var k_outer = 0u; k_outer < params.k; k_outer += TILE_K) {

        // see mul_mat_decls.tmpl
        init_shmem_src0(thread_id, src0_batch_offset, offset_m, k_outer);
        init_shmem_src1(thread_id, src1_batch_offset, offset_n, k_outer);

        workgroupBarrier();

        if (subgroup_id < EXPECTED_SUBGROUPS) {

            for (var k_inner = 0u; k_inner < TILE_K; k_inner += SUBGROUP_MATRIX_K_SIZE) {

                let src0_shmem_idx_base = subgroup_m * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE * TILE_K + k_inner;
                var src0_sg_mats: array<subgroup_matrix_left<f16, SUBGROUP_MATRIX_K_SIZE, SUBGROUP_MATRIX_M_SIZE>, SUBGROUP_MATRIX_M>;
                for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                    src0_sg_mats[m] = subgroupMatrixLoad<subgroup_matrix_left<f16, SUBGROUP_MATRIX_K_SIZE, SUBGROUP_MATRIX_M_SIZE>>(
                        &shmem,
                        src0_shmem_idx_base + m * SUBGROUP_MATRIX_M_SIZE * TILE_K,
                        false,
                        TILE_K
                    );
                }

                let src1_shmem_idx_base = TILE_SRC0_SHMEM + subgroup_n * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE * TILE_K + k_inner;
                for (var n = 0u; n < SUBGROUP_MATRIX_N; n++) {
                    let src1_sg_mat = subgroupMatrixLoad<subgroup_matrix_right<f16, SUBGROUP_MATRIX_N_SIZE, SUBGROUP_MATRIX_K_SIZE>>(
                        &shmem,
                        src1_shmem_idx_base + n * SUBGROUP_MATRIX_N_SIZE * TILE_K,
                        true,
                        TILE_K
                    );
                    for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                        acc_sg_mat[m][n] = subgroupMatrixMultiplyAccumulate(src0_sg_mats[m], src1_sg_mat, acc_sg_mat[m][n]);
                    }
                }
            }
        }

        workgroupBarrier();
    }

    let dst_batch_offset = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride;

    // Stage the subgroup matrix tiles into shared memory
    // This uses WG_M_SG_TILE_SIZE as the stride (number of columns in the workgroup tile).
    let WG_TILE_STRIDE = WG_M_SG_TILE_SIZE;
    let tile_row_base_local = subgroup_n * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;
    let tile_col_base_local = subgroup_m * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;

    if (subgroup_id < EXPECTED_SUBGROUPS) { // 2-5% performance hit :(
        for (var n = 0u; n < SUBGROUP_MATRIX_N; n++) {
            for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                let local_row = tile_row_base_local + n * SUBGROUP_MATRIX_N_SIZE;
                let local_col = tile_col_base_local + m * SUBGROUP_MATRIX_M_SIZE;
                let out_base = local_row * WG_TILE_STRIDE + local_col;
                subgroupMatrixStore(&shmem, out_base, acc_sg_mat[m][n], true, WG_TILE_STRIDE);
            }
        }
    }

    workgroupBarrier();

    // Cooperative write: iterate over the entire workgroup tile
    let tile_rows = WG_N_SG_TILE_SIZE;
    let tile_cols = WG_M_SG_TILE_SIZE;
    let total_tile_elems = tile_rows * tile_cols;
    let tile_dst_row_base = wg_m * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
    let tile_dst_col_base = wg_n * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

    for (var idx = thread_id * 4; idx < total_tile_elems; idx += TOTAL_WORKGROUP_SIZE * 4) {
        let local_row = idx % WG_TILE_STRIDE;
        let local_col = idx / WG_TILE_STRIDE;

        let global_row = tile_dst_row_base + local_row;
        let global_col = tile_dst_col_base + local_col;

        if (global_col < params.n && global_row < params.m) {
            let dst_idx = dst_batch_offset + global_col * params.m + global_row;
            store_dst(idx, dst_idx/4);
        }
    }
})";

const char* wgsl_mul_mat_subgroup_matrix_f16_f32 = R"(diagnostic(off, chromium.subgroup_matrix_uniformity);
enable f16;
enable subgroups;
enable chromium_experimental_subgroup_matrix;

struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<f16>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

fn store_dst(shmem_idx: u32, dst_idx: u32) {
    dst[dst_idx] = f32(shmem[shmem_idx]);
}

fn store_shmem(val: f16, idx: u32) {
    shmem[idx] = val;
}

fn init_shmem_src0(thread_id: u32, batch_offset: u32, offset_m: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 1; elem_idx < TILE_SRC0_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 1) {
        let tile_m = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_m = offset_m + tile_m;
        let global_k = k_outer + tile_k;
        let src0_idx = batch_offset + global_m * params.stride_01 + global_k;
        let src0_val = select( // taking a slight performance hit to avoid oob
            f16(0.0),
            src0[src0_idx/1],
            global_m < params.m && global_k < params.k);
        store_shmem(f16(src0_val), elem_idx);
    }
}

fn init_shmem_src1(thread_id: u32, batch_offset: u32, offset_n: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 1; elem_idx < TILE_SRC1_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 1) {
        let tile_n = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_n = offset_n + tile_n;
        let global_k = k_outer + tile_k;
        let src1_idx = batch_offset + global_n * params.stride_11 + global_k;
        let src1_val = select(
            f32(0.0),
            src1[src1_idx/1],
            global_n < params.n && global_k < params.k);
        store_shmem(f16(src1_val), TILE_SRC0_SHMEM + elem_idx);
    }
}



// Note: These are string interpolated at build time, cannot use override constants due to limitations in
// current Dawn version type definitions/matrix load requirements for constant memory sizes.
const SUBGROUP_M = {{WEBGPU_SUBGROUP_M}}u;
const SUBGROUP_N = {{WEBGPU_SUBGROUP_N}}u;
// For portability we assume the max subgroup size, meaning some subgroups will be masked out if the
// runtime subgroup size is smaller.
const MAX_SUBGROUP_SIZE = {{WEBGPU_MAX_SUBGROUP_SIZE}}u;

const EXPECTED_SUBGROUPS = SUBGROUP_M * SUBGROUP_N;

const SUBGROUP_MATRIX_M_SIZE = {{WEBGPU_SG_MAT_M_SIZE}}u;
const SUBGROUP_MATRIX_N_SIZE = {{WEBGPU_SG_MAT_N_SIZE}}u;
const SUBGROUP_MATRIX_K_SIZE = {{WEBGPU_SG_MAT_K_SIZE}}u;

const SUBGROUP_MATRIX_M = {{WEBGPU_SUBGROUP_MATRIX_M}}u;
const SUBGROUP_MATRIX_N = {{WEBGPU_SUBGROUP_MATRIX_N}}u;

const TILE_K = {{WEBGPU_TILE_K}}u;

const WG_M_SG_TILE_SIZE = SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
const WG_N_SG_TILE_SIZE = SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

const TOTAL_WORKGROUP_SIZE = SUBGROUP_M * SUBGROUP_N * MAX_SUBGROUP_SIZE;
const TILE_SRC0_SHMEM = TILE_K * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
const TILE_SRC1_SHMEM = TILE_K * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

const SG_MAT_ACCUM_SHMEM = SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_M_SIZE * SUBGROUP_MATRIX_N_SIZE;

// We reuse shmem for accumulation matrices
const SHMEM_SIZE = max(TILE_SRC0_SHMEM + TILE_SRC1_SHMEM, SG_MAT_ACCUM_SHMEM);

var<workgroup> shmem: array<f16, SHMEM_SIZE>;

@compute @workgroup_size(TOTAL_WORKGROUP_SIZE)
fn main(@builtin(workgroup_id) wg_id: vec3<u32>,
        @builtin(local_invocation_id) local_id: vec3<u32>,
        @builtin(subgroup_id) subgroup_id: u32) {

    let thread_id = local_id.x;
    let subgroup_m = subgroup_id % SUBGROUP_M;
    let subgroup_n = subgroup_id / SUBGROUP_M;

    let wg_m_count = (params.m + WG_M_SG_TILE_SIZE - 1) / WG_M_SG_TILE_SIZE;
    let wg_n_count = (params.n + WG_N_SG_TILE_SIZE - 1) / WG_N_SG_TILE_SIZE;
    let wg_per_matrix = wg_m_count * wg_n_count;

    let batch_idx = wg_id.x / wg_per_matrix;

    let wg_in_batch = wg_id.x % wg_per_matrix;
    let wg_m = wg_in_batch % wg_m_count;
    let wg_n = wg_in_batch / wg_m_count;

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_batch_offset = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02;
    let src1_batch_offset = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;

    let offset_m = wg_m * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
    let offset_n = wg_n * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

    var acc_sg_mat : array<array<subgroup_matrix_result<f16, SUBGROUP_MATRIX_N_SIZE, SUBGROUP_MATRIX_M_SIZE>, SUBGROUP_MATRIX_N>, SUBGROUP_MATRIX_M>;

    for (var k_outer = 0u; k_outer < params.k; k_outer += TILE_K) {

        // see mul_mat_decls.tmpl
        init_shmem_src0(thread_id, src0_batch_offset, offset_m, k_outer);
        init_shmem_src1(thread_id, src1_batch_offset, offset_n, k_outer);

        workgroupBarrier();

        if (subgroup_id < EXPECTED_SUBGROUPS) {

            for (var k_inner = 0u; k_inner < TILE_K; k_inner += SUBGROUP_MATRIX_K_SIZE) {

                let src0_shmem_idx_base = subgroup_m * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE * TILE_K + k_inner;
                var src0_sg_mats: array<subgroup_matrix_left<f16, SUBGROUP_MATRIX_K_SIZE, SUBGROUP_MATRIX_M_SIZE>, SUBGROUP_MATRIX_M>;
                for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                    src0_sg_mats[m] = subgroupMatrixLoad<subgroup_matrix_left<f16, SUBGROUP_MATRIX_K_SIZE, SUBGROUP_MATRIX_M_SIZE>>(
                        &shmem,
                        src0_shmem_idx_base + m * SUBGROUP_MATRIX_M_SIZE * TILE_K,
                        false,
                        TILE_K
                    );
                }

                let src1_shmem_idx_base = TILE_SRC0_SHMEM + subgroup_n * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE * TILE_K + k_inner;
                for (var n = 0u; n < SUBGROUP_MATRIX_N; n++) {
                    let src1_sg_mat = subgroupMatrixLoad<subgroup_matrix_right<f16, SUBGROUP_MATRIX_N_SIZE, SUBGROUP_MATRIX_K_SIZE>>(
                        &shmem,
                        src1_shmem_idx_base + n * SUBGROUP_MATRIX_N_SIZE * TILE_K,
                        true,
                        TILE_K
                    );
                    for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                        acc_sg_mat[m][n] = subgroupMatrixMultiplyAccumulate(src0_sg_mats[m], src1_sg_mat, acc_sg_mat[m][n]);
                    }
                }
            }
        }

        workgroupBarrier();
    }

    let dst_batch_offset = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride;

    // Stage the subgroup matrix tiles into shared memory
    // This uses WG_M_SG_TILE_SIZE as the stride (number of columns in the workgroup tile).
    let WG_TILE_STRIDE = WG_M_SG_TILE_SIZE;
    let tile_row_base_local = subgroup_n * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;
    let tile_col_base_local = subgroup_m * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;

    if (subgroup_id < EXPECTED_SUBGROUPS) { // 2-5% performance hit :(
        for (var n = 0u; n < SUBGROUP_MATRIX_N; n++) {
            for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                let local_row = tile_row_base_local + n * SUBGROUP_MATRIX_N_SIZE;
                let local_col = tile_col_base_local + m * SUBGROUP_MATRIX_M_SIZE;
                let out_base = local_row * WG_TILE_STRIDE + local_col;
                subgroupMatrixStore(&shmem, out_base, acc_sg_mat[m][n], true, WG_TILE_STRIDE);
            }
        }
    }

    workgroupBarrier();

    // Cooperative write: iterate over the entire workgroup tile
    let tile_rows = WG_N_SG_TILE_SIZE;
    let tile_cols = WG_M_SG_TILE_SIZE;
    let total_tile_elems = tile_rows * tile_cols;
    let tile_dst_row_base = wg_m * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
    let tile_dst_col_base = wg_n * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

    for (var idx = thread_id * 1; idx < total_tile_elems; idx += TOTAL_WORKGROUP_SIZE * 1) {
        let local_row = idx % WG_TILE_STRIDE;
        let local_col = idx / WG_TILE_STRIDE;

        let global_row = tile_dst_row_base + local_row;
        let global_col = tile_dst_col_base + local_col;

        if (global_col < params.n && global_row < params.m) {
            let dst_idx = dst_batch_offset + global_col * params.m + global_row;
            store_dst(idx, dst_idx/1);
        }
    }
})";

const char* wgsl_mul_mat_subgroup_matrix_f16_f16_vec = R"(diagnostic(off, chromium.subgroup_matrix_uniformity);
enable f16;
enable subgroups;
enable chromium_experimental_subgroup_matrix;

struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<vec4<f16>>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<vec4<f16>>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<vec4<f32>>; // M rows, N columns (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

fn store_dst(shmem_idx: u32, dst_idx: u32) {
    dst[dst_idx] = vec4<f32>(
        f32(shmem[shmem_idx]),
        f32(shmem[shmem_idx + 1]),
        f32(shmem[shmem_idx + 2]),
        f32(shmem[shmem_idx + 3])
    );
}

fn store_shmem(val: vec4<f16>, idx: u32) {
    shmem[idx] = val.x;
    shmem[idx + 1] = val.y;
    shmem[idx + 2] = val.z;
    shmem[idx + 3] = val.w;
}

fn init_shmem_src0(thread_id: u32, batch_offset: u32, offset_m: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 4; elem_idx < TILE_SRC0_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 4) {
        let tile_m = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_m = offset_m + tile_m;
        let global_k = k_outer + tile_k;
        let src0_idx = batch_offset + global_m * params.stride_01 + global_k;
        let src0_val = select( // taking a slight performance hit to avoid oob
            vec4<f16>(0.0),
            src0[src0_idx/4],
            global_m < params.m && global_k < params.k);
        store_shmem(vec4<f16>(src0_val), elem_idx);
    }
}

fn init_shmem_src1(thread_id: u32, batch_offset: u32, offset_n: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 4; elem_idx < TILE_SRC1_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 4) {
        let tile_n = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_n = offset_n + tile_n;
        let global_k = k_outer + tile_k;
        let src1_idx = batch_offset + global_n * params.stride_11 + global_k;
        let src1_val = select(
            vec4<f16>(0.0),
            src1[src1_idx/4],
            global_n < params.n && global_k < params.k);
        store_shmem(vec4<f16>(src1_val), TILE_SRC0_SHMEM + elem_idx);
    }
}



// Note: These are string interpolated at build time, cannot use override constants due to limitations in
// current Dawn version type definitions/matrix load requirements for constant memory sizes.
const SUBGROUP_M = {{WEBGPU_SUBGROUP_M}}u;
const SUBGROUP_N = {{WEBGPU_SUBGROUP_N}}u;
// For portability we assume the max subgroup size, meaning some subgroups will be masked out if the
// runtime subgroup size is smaller.
const MAX_SUBGROUP_SIZE = {{WEBGPU_MAX_SUBGROUP_SIZE}}u;

const EXPECTED_SUBGROUPS = SUBGROUP_M * SUBGROUP_N;

const SUBGROUP_MATRIX_M_SIZE = {{WEBGPU_SG_MAT_M_SIZE}}u;
const SUBGROUP_MATRIX_N_SIZE = {{WEBGPU_SG_MAT_N_SIZE}}u;
const SUBGROUP_MATRIX_K_SIZE = {{WEBGPU_SG_MAT_K_SIZE}}u;

const SUBGROUP_MATRIX_M = {{WEBGPU_SUBGROUP_MATRIX_M}}u;
const SUBGROUP_MATRIX_N = {{WEBGPU_SUBGROUP_MATRIX_N}}u;

const TILE_K = {{WEBGPU_TILE_K}}u;

const WG_M_SG_TILE_SIZE = SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
const WG_N_SG_TILE_SIZE = SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

const TOTAL_WORKGROUP_SIZE = SUBGROUP_M * SUBGROUP_N * MAX_SUBGROUP_SIZE;
const TILE_SRC0_SHMEM = TILE_K * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
const TILE_SRC1_SHMEM = TILE_K * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

const SG_MAT_ACCUM_SHMEM = SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_M_SIZE * SUBGROUP_MATRIX_N_SIZE;

// We reuse shmem for accumulation matrices
const SHMEM_SIZE = max(TILE_SRC0_SHMEM + TILE_SRC1_SHMEM, SG_MAT_ACCUM_SHMEM);

var<workgroup> shmem: array<f16, SHMEM_SIZE>;

@compute @workgroup_size(TOTAL_WORKGROUP_SIZE)
fn main(@builtin(workgroup_id) wg_id: vec3<u32>,
        @builtin(local_invocation_id) local_id: vec3<u32>,
        @builtin(subgroup_id) subgroup_id: u32) {

    let thread_id = local_id.x;
    let subgroup_m = subgroup_id % SUBGROUP_M;
    let subgroup_n = subgroup_id / SUBGROUP_M;

    let wg_m_count = (params.m + WG_M_SG_TILE_SIZE - 1) / WG_M_SG_TILE_SIZE;
    let wg_n_count = (params.n + WG_N_SG_TILE_SIZE - 1) / WG_N_SG_TILE_SIZE;
    let wg_per_matrix = wg_m_count * wg_n_count;

    let batch_idx = wg_id.x / wg_per_matrix;

    let wg_in_batch = wg_id.x % wg_per_matrix;
    let wg_m = wg_in_batch % wg_m_count;
    let wg_n = wg_in_batch / wg_m_count;

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_batch_offset = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02;
    let src1_batch_offset = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;

    let offset_m = wg_m * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
    let offset_n = wg_n * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

    var acc_sg_mat : array<array<subgroup_matrix_result<f16, SUBGROUP_MATRIX_N_SIZE, SUBGROUP_MATRIX_M_SIZE>, SUBGROUP_MATRIX_N>, SUBGROUP_MATRIX_M>;

    for (var k_outer = 0u; k_outer < params.k; k_outer += TILE_K) {

        // see mul_mat_decls.tmpl
        init_shmem_src0(thread_id, src0_batch_offset, offset_m, k_outer);
        init_shmem_src1(thread_id, src1_batch_offset, offset_n, k_outer);

        workgroupBarrier();

        if (subgroup_id < EXPECTED_SUBGROUPS) {

            for (var k_inner = 0u; k_inner < TILE_K; k_inner += SUBGROUP_MATRIX_K_SIZE) {

                let src0_shmem_idx_base = subgroup_m * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE * TILE_K + k_inner;
                var src0_sg_mats: array<subgroup_matrix_left<f16, SUBGROUP_MATRIX_K_SIZE, SUBGROUP_MATRIX_M_SIZE>, SUBGROUP_MATRIX_M>;
                for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                    src0_sg_mats[m] = subgroupMatrixLoad<subgroup_matrix_left<f16, SUBGROUP_MATRIX_K_SIZE, SUBGROUP_MATRIX_M_SIZE>>(
                        &shmem,
                        src0_shmem_idx_base + m * SUBGROUP_MATRIX_M_SIZE * TILE_K,
                        false,
                        TILE_K
                    );
                }

                let src1_shmem_idx_base = TILE_SRC0_SHMEM + subgroup_n * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE * TILE_K + k_inner;
                for (var n = 0u; n < SUBGROUP_MATRIX_N; n++) {
                    let src1_sg_mat = subgroupMatrixLoad<subgroup_matrix_right<f16, SUBGROUP_MATRIX_N_SIZE, SUBGROUP_MATRIX_K_SIZE>>(
                        &shmem,
                        src1_shmem_idx_base + n * SUBGROUP_MATRIX_N_SIZE * TILE_K,
                        true,
                        TILE_K
                    );
                    for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                        acc_sg_mat[m][n] = subgroupMatrixMultiplyAccumulate(src0_sg_mats[m], src1_sg_mat, acc_sg_mat[m][n]);
                    }
                }
            }
        }

        workgroupBarrier();
    }

    let dst_batch_offset = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride;

    // Stage the subgroup matrix tiles into shared memory
    // This uses WG_M_SG_TILE_SIZE as the stride (number of columns in the workgroup tile).
    let WG_TILE_STRIDE = WG_M_SG_TILE_SIZE;
    let tile_row_base_local = subgroup_n * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;
    let tile_col_base_local = subgroup_m * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;

    if (subgroup_id < EXPECTED_SUBGROUPS) { // 2-5% performance hit :(
        for (var n = 0u; n < SUBGROUP_MATRIX_N; n++) {
            for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                let local_row = tile_row_base_local + n * SUBGROUP_MATRIX_N_SIZE;
                let local_col = tile_col_base_local + m * SUBGROUP_MATRIX_M_SIZE;
                let out_base = local_row * WG_TILE_STRIDE + local_col;
                subgroupMatrixStore(&shmem, out_base, acc_sg_mat[m][n], true, WG_TILE_STRIDE);
            }
        }
    }

    workgroupBarrier();

    // Cooperative write: iterate over the entire workgroup tile
    let tile_rows = WG_N_SG_TILE_SIZE;
    let tile_cols = WG_M_SG_TILE_SIZE;
    let total_tile_elems = tile_rows * tile_cols;
    let tile_dst_row_base = wg_m * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
    let tile_dst_col_base = wg_n * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

    for (var idx = thread_id * 4; idx < total_tile_elems; idx += TOTAL_WORKGROUP_SIZE * 4) {
        let local_row = idx % WG_TILE_STRIDE;
        let local_col = idx / WG_TILE_STRIDE;

        let global_row = tile_dst_row_base + local_row;
        let global_col = tile_dst_col_base + local_col;

        if (global_col < params.n && global_row < params.m) {
            let dst_idx = dst_batch_offset + global_col * params.m + global_row;
            store_dst(idx, dst_idx/4);
        }
    }
})";

const char* wgsl_mul_mat_subgroup_matrix_f16_f16 = R"(diagnostic(off, chromium.subgroup_matrix_uniformity);
enable f16;
enable subgroups;
enable chromium_experimental_subgroup_matrix;

struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<f16>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f16>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

fn store_dst(shmem_idx: u32, dst_idx: u32) {
    dst[dst_idx] = f32(shmem[shmem_idx]);
}

fn store_shmem(val: f16, idx: u32) {
    shmem[idx] = val;
}

fn init_shmem_src0(thread_id: u32, batch_offset: u32, offset_m: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 1; elem_idx < TILE_SRC0_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 1) {
        let tile_m = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_m = offset_m + tile_m;
        let global_k = k_outer + tile_k;
        let src0_idx = batch_offset + global_m * params.stride_01 + global_k;
        let src0_val = select( // taking a slight performance hit to avoid oob
            f16(0.0),
            src0[src0_idx/1],
            global_m < params.m && global_k < params.k);
        store_shmem(f16(src0_val), elem_idx);
    }
}

fn init_shmem_src1(thread_id: u32, batch_offset: u32, offset_n: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 1; elem_idx < TILE_SRC1_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 1) {
        let tile_n = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_n = offset_n + tile_n;
        let global_k = k_outer + tile_k;
        let src1_idx = batch_offset + global_n * params.stride_11 + global_k;
        let src1_val = select(
            f16(0.0),
            src1[src1_idx/1],
            global_n < params.n && global_k < params.k);
        store_shmem(f16(src1_val), TILE_SRC0_SHMEM + elem_idx);
    }
}



// Note: These are string interpolated at build time, cannot use override constants due to limitations in
// current Dawn version type definitions/matrix load requirements for constant memory sizes.
const SUBGROUP_M = {{WEBGPU_SUBGROUP_M}}u;
const SUBGROUP_N = {{WEBGPU_SUBGROUP_N}}u;
// For portability we assume the max subgroup size, meaning some subgroups will be masked out if the
// runtime subgroup size is smaller.
const MAX_SUBGROUP_SIZE = {{WEBGPU_MAX_SUBGROUP_SIZE}}u;

const EXPECTED_SUBGROUPS = SUBGROUP_M * SUBGROUP_N;

const SUBGROUP_MATRIX_M_SIZE = {{WEBGPU_SG_MAT_M_SIZE}}u;
const SUBGROUP_MATRIX_N_SIZE = {{WEBGPU_SG_MAT_N_SIZE}}u;
const SUBGROUP_MATRIX_K_SIZE = {{WEBGPU_SG_MAT_K_SIZE}}u;

const SUBGROUP_MATRIX_M = {{WEBGPU_SUBGROUP_MATRIX_M}}u;
const SUBGROUP_MATRIX_N = {{WEBGPU_SUBGROUP_MATRIX_N}}u;

const TILE_K = {{WEBGPU_TILE_K}}u;

const WG_M_SG_TILE_SIZE = SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
const WG_N_SG_TILE_SIZE = SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

const TOTAL_WORKGROUP_SIZE = SUBGROUP_M * SUBGROUP_N * MAX_SUBGROUP_SIZE;
const TILE_SRC0_SHMEM = TILE_K * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
const TILE_SRC1_SHMEM = TILE_K * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

const SG_MAT_ACCUM_SHMEM = SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_M_SIZE * SUBGROUP_MATRIX_N_SIZE;

// We reuse shmem for accumulation matrices
const SHMEM_SIZE = max(TILE_SRC0_SHMEM + TILE_SRC1_SHMEM, SG_MAT_ACCUM_SHMEM);

var<workgroup> shmem: array<f16, SHMEM_SIZE>;

@compute @workgroup_size(TOTAL_WORKGROUP_SIZE)
fn main(@builtin(workgroup_id) wg_id: vec3<u32>,
        @builtin(local_invocation_id) local_id: vec3<u32>,
        @builtin(subgroup_id) subgroup_id: u32) {

    let thread_id = local_id.x;
    let subgroup_m = subgroup_id % SUBGROUP_M;
    let subgroup_n = subgroup_id / SUBGROUP_M;

    let wg_m_count = (params.m + WG_M_SG_TILE_SIZE - 1) / WG_M_SG_TILE_SIZE;
    let wg_n_count = (params.n + WG_N_SG_TILE_SIZE - 1) / WG_N_SG_TILE_SIZE;
    let wg_per_matrix = wg_m_count * wg_n_count;

    let batch_idx = wg_id.x / wg_per_matrix;

    let wg_in_batch = wg_id.x % wg_per_matrix;
    let wg_m = wg_in_batch % wg_m_count;
    let wg_n = wg_in_batch / wg_m_count;

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_batch_offset = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02;
    let src1_batch_offset = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;

    let offset_m = wg_m * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
    let offset_n = wg_n * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

    var acc_sg_mat : array<array<subgroup_matrix_result<f16, SUBGROUP_MATRIX_N_SIZE, SUBGROUP_MATRIX_M_SIZE>, SUBGROUP_MATRIX_N>, SUBGROUP_MATRIX_M>;

    for (var k_outer = 0u; k_outer < params.k; k_outer += TILE_K) {

        // see mul_mat_decls.tmpl
        init_shmem_src0(thread_id, src0_batch_offset, offset_m, k_outer);
        init_shmem_src1(thread_id, src1_batch_offset, offset_n, k_outer);

        workgroupBarrier();

        if (subgroup_id < EXPECTED_SUBGROUPS) {

            for (var k_inner = 0u; k_inner < TILE_K; k_inner += SUBGROUP_MATRIX_K_SIZE) {

                let src0_shmem_idx_base = subgroup_m * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE * TILE_K + k_inner;
                var src0_sg_mats: array<subgroup_matrix_left<f16, SUBGROUP_MATRIX_K_SIZE, SUBGROUP_MATRIX_M_SIZE>, SUBGROUP_MATRIX_M>;
                for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                    src0_sg_mats[m] = subgroupMatrixLoad<subgroup_matrix_left<f16, SUBGROUP_MATRIX_K_SIZE, SUBGROUP_MATRIX_M_SIZE>>(
                        &shmem,
                        src0_shmem_idx_base + m * SUBGROUP_MATRIX_M_SIZE * TILE_K,
                        false,
                        TILE_K
                    );
                }

                let src1_shmem_idx_base = TILE_SRC0_SHMEM + subgroup_n * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE * TILE_K + k_inner;
                for (var n = 0u; n < SUBGROUP_MATRIX_N; n++) {
                    let src1_sg_mat = subgroupMatrixLoad<subgroup_matrix_right<f16, SUBGROUP_MATRIX_N_SIZE, SUBGROUP_MATRIX_K_SIZE>>(
                        &shmem,
                        src1_shmem_idx_base + n * SUBGROUP_MATRIX_N_SIZE * TILE_K,
                        true,
                        TILE_K
                    );
                    for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                        acc_sg_mat[m][n] = subgroupMatrixMultiplyAccumulate(src0_sg_mats[m], src1_sg_mat, acc_sg_mat[m][n]);
                    }
                }
            }
        }

        workgroupBarrier();
    }

    let dst_batch_offset = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride;

    // Stage the subgroup matrix tiles into shared memory
    // This uses WG_M_SG_TILE_SIZE as the stride (number of columns in the workgroup tile).
    let WG_TILE_STRIDE = WG_M_SG_TILE_SIZE;
    let tile_row_base_local = subgroup_n * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;
    let tile_col_base_local = subgroup_m * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;

    if (subgroup_id < EXPECTED_SUBGROUPS) { // 2-5% performance hit :(
        for (var n = 0u; n < SUBGROUP_MATRIX_N; n++) {
            for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                let local_row = tile_row_base_local + n * SUBGROUP_MATRIX_N_SIZE;
                let local_col = tile_col_base_local + m * SUBGROUP_MATRIX_M_SIZE;
                let out_base = local_row * WG_TILE_STRIDE + local_col;
                subgroupMatrixStore(&shmem, out_base, acc_sg_mat[m][n], true, WG_TILE_STRIDE);
            }
        }
    }

    workgroupBarrier();

    // Cooperative write: iterate over the entire workgroup tile
    let tile_rows = WG_N_SG_TILE_SIZE;
    let tile_cols = WG_M_SG_TILE_SIZE;
    let total_tile_elems = tile_rows * tile_cols;
    let tile_dst_row_base = wg_m * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
    let tile_dst_col_base = wg_n * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

    for (var idx = thread_id * 1; idx < total_tile_elems; idx += TOTAL_WORKGROUP_SIZE * 1) {
        let local_row = idx % WG_TILE_STRIDE;
        let local_col = idx / WG_TILE_STRIDE;

        let global_row = tile_dst_row_base + local_row;
        let global_col = tile_dst_col_base + local_col;

        if (global_col < params.n && global_row < params.m) {
            let dst_idx = dst_batch_offset + global_col * params.m + global_row;
            store_dst(idx, dst_idx/1);
        }
    }
})";

const char* wgsl_mul_mat_subgroup_matrix_q4_0_f32_vec = R"(diagnostic(off, chromium.subgroup_matrix_uniformity);
enable f16;
enable subgroups;
enable chromium_experimental_subgroup_matrix;

struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<f16>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<vec4<f32>>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<vec4<f32>>; // M rows, N columns (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

fn store_dst(shmem_idx: u32, dst_idx: u32) {
    dst[dst_idx] = vec4<f32>(
        f32(shmem[shmem_idx]),
        f32(shmem[shmem_idx + 1]),
        f32(shmem[shmem_idx + 2]),
        f32(shmem[shmem_idx + 3])
    );
}

fn store_shmem(val: vec4<f16>, idx: u32) {
    shmem[idx] = val.x;
    shmem[idx + 1] = val.y;
    shmem[idx + 2] = val.z;
    shmem[idx + 3] = val.w;
}

const BLOCK_SIZE = 32u;
// the number of blocks per k-tile. Note that this currently only works if TILE_K is a multiple of BLOCK_SIZE, which may need to be rethought for larger quantized types.
override BLOCKS_K = TILE_K/BLOCK_SIZE;
const NQ = 16u;
const F16_PER_BLOCK = 9u; // 1 scale + 8x4 packed weights
const WEIGHTS_PER_F16 = 4u; // 4 weights per f16
const F16_PER_THREAD = NQ / WEIGHTS_PER_F16;

fn init_shmem_src0(thread_id: u32, batch_offset: u32, offset_m: u32, k_outer: u32) {
    for (var i = thread_id * NQ; i < TILE_SRC0_SHMEM; i += TOTAL_WORKGROUP_SIZE * NQ) {
        let blck_idx = i / BLOCK_SIZE;
        let block_offset = (i % BLOCK_SIZE) / WEIGHTS_PER_F16;
        let shmem_idx = blck_idx * BLOCK_SIZE + block_offset * 2u;

        let tile_m = blck_idx / BLOCKS_K;
        let global_m = offset_m + tile_m;
        let block_k = blck_idx % BLOCKS_K;
        let global_k = k_outer / BLOCK_SIZE + block_k;

        if (global_m < params.m && global_k < params.k / BLOCK_SIZE) {
            let src0_idx = batch_offset + global_m * params.stride_01 + global_k;
            let scale_idx = src0_idx * F16_PER_BLOCK;
            let d = src0[scale_idx];

            for (var j = 0u; j < F16_PER_THREAD; j += 2) {
                let q_0 = src0[scale_idx + 1u + block_offset + j];
                let q_1 = src0[scale_idx + 1u + block_offset + j + 1];

                let q_packed = bitcast<u32>(vec2(q_0, q_1));
                for (var k = 0u; k < 4u; k++) {
                    let q_byte = get_byte(q_packed, k);
                    let q_hi = (f16((q_byte >> 4) & 0xF) - 8.0) * d;
                    let q_lo = (f16(q_byte & 0xF) - 8.0) * d;
                    shmem[shmem_idx + j * 2 + k] = q_lo;
                    shmem[shmem_idx + j * 2 + k + 16u] = q_hi;
                }
            }
        }
    }
}

fn init_shmem_src1(thread_id: u32, batch_offset: u32, offset_n: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 4; elem_idx < TILE_SRC1_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 4) {
        let tile_n = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_n = offset_n + tile_n;
        let global_k = k_outer + tile_k;
        let src1_idx = batch_offset + global_n * params.stride_11 + global_k;
        let src1_val = select(
            vec4<f32>(0.0),
            src1[src1_idx/4],
            global_n < params.n && global_k < params.k);
        store_shmem(vec4<f16>(src1_val), TILE_SRC0_SHMEM + elem_idx);
    }
}



// Note: These are string interpolated at build time, cannot use override constants due to limitations in
// current Dawn version type definitions/matrix load requirements for constant memory sizes.
const SUBGROUP_M = {{WEBGPU_SUBGROUP_M}}u;
const SUBGROUP_N = {{WEBGPU_SUBGROUP_N}}u;
// For portability we assume the max subgroup size, meaning some subgroups will be masked out if the
// runtime subgroup size is smaller.
const MAX_SUBGROUP_SIZE = {{WEBGPU_MAX_SUBGROUP_SIZE}}u;

const EXPECTED_SUBGROUPS = SUBGROUP_M * SUBGROUP_N;

const SUBGROUP_MATRIX_M_SIZE = {{WEBGPU_SG_MAT_M_SIZE}}u;
const SUBGROUP_MATRIX_N_SIZE = {{WEBGPU_SG_MAT_N_SIZE}}u;
const SUBGROUP_MATRIX_K_SIZE = {{WEBGPU_SG_MAT_K_SIZE}}u;

const SUBGROUP_MATRIX_M = {{WEBGPU_SUBGROUP_MATRIX_M}}u;
const SUBGROUP_MATRIX_N = {{WEBGPU_SUBGROUP_MATRIX_N}}u;

const TILE_K = {{WEBGPU_TILE_K}}u;

const WG_M_SG_TILE_SIZE = SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
const WG_N_SG_TILE_SIZE = SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

const TOTAL_WORKGROUP_SIZE = SUBGROUP_M * SUBGROUP_N * MAX_SUBGROUP_SIZE;
const TILE_SRC0_SHMEM = TILE_K * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
const TILE_SRC1_SHMEM = TILE_K * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

const SG_MAT_ACCUM_SHMEM = SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_M_SIZE * SUBGROUP_MATRIX_N_SIZE;

// We reuse shmem for accumulation matrices
const SHMEM_SIZE = max(TILE_SRC0_SHMEM + TILE_SRC1_SHMEM, SG_MAT_ACCUM_SHMEM);

var<workgroup> shmem: array<f16, SHMEM_SIZE>;

@compute @workgroup_size(TOTAL_WORKGROUP_SIZE)
fn main(@builtin(workgroup_id) wg_id: vec3<u32>,
        @builtin(local_invocation_id) local_id: vec3<u32>,
        @builtin(subgroup_id) subgroup_id: u32) {

    let thread_id = local_id.x;
    let subgroup_m = subgroup_id % SUBGROUP_M;
    let subgroup_n = subgroup_id / SUBGROUP_M;

    let wg_m_count = (params.m + WG_M_SG_TILE_SIZE - 1) / WG_M_SG_TILE_SIZE;
    let wg_n_count = (params.n + WG_N_SG_TILE_SIZE - 1) / WG_N_SG_TILE_SIZE;
    let wg_per_matrix = wg_m_count * wg_n_count;

    let batch_idx = wg_id.x / wg_per_matrix;

    let wg_in_batch = wg_id.x % wg_per_matrix;
    let wg_m = wg_in_batch % wg_m_count;
    let wg_n = wg_in_batch / wg_m_count;

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_batch_offset = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02;
    let src1_batch_offset = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;

    let offset_m = wg_m * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
    let offset_n = wg_n * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

    var acc_sg_mat : array<array<subgroup_matrix_result<f16, SUBGROUP_MATRIX_N_SIZE, SUBGROUP_MATRIX_M_SIZE>, SUBGROUP_MATRIX_N>, SUBGROUP_MATRIX_M>;

    for (var k_outer = 0u; k_outer < params.k; k_outer += TILE_K) {

        // see mul_mat_decls.tmpl
        init_shmem_src0(thread_id, src0_batch_offset, offset_m, k_outer);
        init_shmem_src1(thread_id, src1_batch_offset, offset_n, k_outer);

        workgroupBarrier();

        if (subgroup_id < EXPECTED_SUBGROUPS) {

            for (var k_inner = 0u; k_inner < TILE_K; k_inner += SUBGROUP_MATRIX_K_SIZE) {

                let src0_shmem_idx_base = subgroup_m * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE * TILE_K + k_inner;
                var src0_sg_mats: array<subgroup_matrix_left<f16, SUBGROUP_MATRIX_K_SIZE, SUBGROUP_MATRIX_M_SIZE>, SUBGROUP_MATRIX_M>;
                for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                    src0_sg_mats[m] = subgroupMatrixLoad<subgroup_matrix_left<f16, SUBGROUP_MATRIX_K_SIZE, SUBGROUP_MATRIX_M_SIZE>>(
                        &shmem,
                        src0_shmem_idx_base + m * SUBGROUP_MATRIX_M_SIZE * TILE_K,
                        false,
                        TILE_K
                    );
                }

                let src1_shmem_idx_base = TILE_SRC0_SHMEM + subgroup_n * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE * TILE_K + k_inner;
                for (var n = 0u; n < SUBGROUP_MATRIX_N; n++) {
                    let src1_sg_mat = subgroupMatrixLoad<subgroup_matrix_right<f16, SUBGROUP_MATRIX_N_SIZE, SUBGROUP_MATRIX_K_SIZE>>(
                        &shmem,
                        src1_shmem_idx_base + n * SUBGROUP_MATRIX_N_SIZE * TILE_K,
                        true,
                        TILE_K
                    );
                    for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                        acc_sg_mat[m][n] = subgroupMatrixMultiplyAccumulate(src0_sg_mats[m], src1_sg_mat, acc_sg_mat[m][n]);
                    }
                }
            }
        }

        workgroupBarrier();
    }

    let dst_batch_offset = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride;

    // Stage the subgroup matrix tiles into shared memory
    // This uses WG_M_SG_TILE_SIZE as the stride (number of columns in the workgroup tile).
    let WG_TILE_STRIDE = WG_M_SG_TILE_SIZE;
    let tile_row_base_local = subgroup_n * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;
    let tile_col_base_local = subgroup_m * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;

    if (subgroup_id < EXPECTED_SUBGROUPS) { // 2-5% performance hit :(
        for (var n = 0u; n < SUBGROUP_MATRIX_N; n++) {
            for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                let local_row = tile_row_base_local + n * SUBGROUP_MATRIX_N_SIZE;
                let local_col = tile_col_base_local + m * SUBGROUP_MATRIX_M_SIZE;
                let out_base = local_row * WG_TILE_STRIDE + local_col;
                subgroupMatrixStore(&shmem, out_base, acc_sg_mat[m][n], true, WG_TILE_STRIDE);
            }
        }
    }

    workgroupBarrier();

    // Cooperative write: iterate over the entire workgroup tile
    let tile_rows = WG_N_SG_TILE_SIZE;
    let tile_cols = WG_M_SG_TILE_SIZE;
    let total_tile_elems = tile_rows * tile_cols;
    let tile_dst_row_base = wg_m * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
    let tile_dst_col_base = wg_n * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

    for (var idx = thread_id * 4; idx < total_tile_elems; idx += TOTAL_WORKGROUP_SIZE * 4) {
        let local_row = idx % WG_TILE_STRIDE;
        let local_col = idx / WG_TILE_STRIDE;

        let global_row = tile_dst_row_base + local_row;
        let global_col = tile_dst_col_base + local_col;

        if (global_col < params.n && global_row < params.m) {
            let dst_idx = dst_batch_offset + global_col * params.m + global_row;
            store_dst(idx, dst_idx/4);
        }
    }
})";

const char* wgsl_mul_mat_subgroup_matrix_q4_0_f32 = R"(diagnostic(off, chromium.subgroup_matrix_uniformity);
enable f16;
enable subgroups;
enable chromium_experimental_subgroup_matrix;

struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<f16>; // M rows, K columns
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // K rows, N columns (transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>; // M rows, N columns (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

fn store_dst(shmem_idx: u32, dst_idx: u32) {
    dst[dst_idx] = f32(shmem[shmem_idx]);
}

fn store_shmem(val: f16, idx: u32) {
    shmem[idx] = val;
}

const BLOCK_SIZE = 32u;
// the number of blocks per k-tile. Note that this currently only works if TILE_K is a multiple of BLOCK_SIZE, which may need to be rethought for larger quantized types.
override BLOCKS_K = TILE_K/BLOCK_SIZE;
const NQ = 16u;
const F16_PER_BLOCK = 9u; // 1 scale + 8x4 packed weights
const WEIGHTS_PER_F16 = 4u; // 4 weights per f16
const F16_PER_THREAD = NQ / WEIGHTS_PER_F16;

fn init_shmem_src0(thread_id: u32, batch_offset: u32, offset_m: u32, k_outer: u32) {
    for (var i = thread_id * NQ; i < TILE_SRC0_SHMEM; i += TOTAL_WORKGROUP_SIZE * NQ) {
        let blck_idx = i / BLOCK_SIZE;
        let block_offset = (i % BLOCK_SIZE) / WEIGHTS_PER_F16;
        let shmem_idx = blck_idx * BLOCK_SIZE + block_offset * 2u;

        let tile_m = blck_idx / BLOCKS_K;
        let global_m = offset_m + tile_m;
        let block_k = blck_idx % BLOCKS_K;
        let global_k = k_outer / BLOCK_SIZE + block_k;

        if (global_m < params.m && global_k < params.k / BLOCK_SIZE) {
            let src0_idx = batch_offset + global_m * params.stride_01 + global_k;
            let scale_idx = src0_idx * F16_PER_BLOCK;
            let d = src0[scale_idx];

            for (var j = 0u; j < F16_PER_THREAD; j += 2) {
                let q_0 = src0[scale_idx + 1u + block_offset + j];
                let q_1 = src0[scale_idx + 1u + block_offset + j + 1];

                let q_packed = bitcast<u32>(vec2(q_0, q_1));
                for (var k = 0u; k < 4u; k++) {
                    let q_byte = get_byte(q_packed, k);
                    let q_hi = (f16((q_byte >> 4) & 0xF) - 8.0) * d;
                    let q_lo = (f16(q_byte & 0xF) - 8.0) * d;
                    shmem[shmem_idx + j * 2 + k] = q_lo;
                    shmem[shmem_idx + j * 2 + k + 16u] = q_hi;
                }
            }
        }
    }
}

fn init_shmem_src1(thread_id: u32, batch_offset: u32, offset_n: u32, k_outer: u32) {
    for (var elem_idx = thread_id * 1; elem_idx < TILE_SRC1_SHMEM; elem_idx += TOTAL_WORKGROUP_SIZE * 1) {
        let tile_n = elem_idx / TILE_K;
        let tile_k = elem_idx % TILE_K;
        let global_n = offset_n + tile_n;
        let global_k = k_outer + tile_k;
        let src1_idx = batch_offset + global_n * params.stride_11 + global_k;
        let src1_val = select(
            f32(0.0),
            src1[src1_idx/1],
            global_n < params.n && global_k < params.k);
        store_shmem(f16(src1_val), TILE_SRC0_SHMEM + elem_idx);
    }
}



// Note: These are string interpolated at build time, cannot use override constants due to limitations in
// current Dawn version type definitions/matrix load requirements for constant memory sizes.
const SUBGROUP_M = {{WEBGPU_SUBGROUP_M}}u;
const SUBGROUP_N = {{WEBGPU_SUBGROUP_N}}u;
// For portability we assume the max subgroup size, meaning some subgroups will be masked out if the
// runtime subgroup size is smaller.
const MAX_SUBGROUP_SIZE = {{WEBGPU_MAX_SUBGROUP_SIZE}}u;

const EXPECTED_SUBGROUPS = SUBGROUP_M * SUBGROUP_N;

const SUBGROUP_MATRIX_M_SIZE = {{WEBGPU_SG_MAT_M_SIZE}}u;
const SUBGROUP_MATRIX_N_SIZE = {{WEBGPU_SG_MAT_N_SIZE}}u;
const SUBGROUP_MATRIX_K_SIZE = {{WEBGPU_SG_MAT_K_SIZE}}u;

const SUBGROUP_MATRIX_M = {{WEBGPU_SUBGROUP_MATRIX_M}}u;
const SUBGROUP_MATRIX_N = {{WEBGPU_SUBGROUP_MATRIX_N}}u;

const TILE_K = {{WEBGPU_TILE_K}}u;

const WG_M_SG_TILE_SIZE = SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
const WG_N_SG_TILE_SIZE = SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

const TOTAL_WORKGROUP_SIZE = SUBGROUP_M * SUBGROUP_N * MAX_SUBGROUP_SIZE;
const TILE_SRC0_SHMEM = TILE_K * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
const TILE_SRC1_SHMEM = TILE_K * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

const SG_MAT_ACCUM_SHMEM = SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_M_SIZE * SUBGROUP_MATRIX_N_SIZE;

// We reuse shmem for accumulation matrices
const SHMEM_SIZE = max(TILE_SRC0_SHMEM + TILE_SRC1_SHMEM, SG_MAT_ACCUM_SHMEM);

var<workgroup> shmem: array<f16, SHMEM_SIZE>;

@compute @workgroup_size(TOTAL_WORKGROUP_SIZE)
fn main(@builtin(workgroup_id) wg_id: vec3<u32>,
        @builtin(local_invocation_id) local_id: vec3<u32>,
        @builtin(subgroup_id) subgroup_id: u32) {

    let thread_id = local_id.x;
    let subgroup_m = subgroup_id % SUBGROUP_M;
    let subgroup_n = subgroup_id / SUBGROUP_M;

    let wg_m_count = (params.m + WG_M_SG_TILE_SIZE - 1) / WG_M_SG_TILE_SIZE;
    let wg_n_count = (params.n + WG_N_SG_TILE_SIZE - 1) / WG_N_SG_TILE_SIZE;
    let wg_per_matrix = wg_m_count * wg_n_count;

    let batch_idx = wg_id.x / wg_per_matrix;

    let wg_in_batch = wg_id.x % wg_per_matrix;
    let wg_m = wg_in_batch % wg_m_count;
    let wg_n = wg_in_batch / wg_m_count;

    let dst2_stride = params.m * params.n;
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;

    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_batch_offset = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02;
    let src1_batch_offset = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;

    let offset_m = wg_m * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
    let offset_n = wg_n * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

    var acc_sg_mat : array<array<subgroup_matrix_result<f16, SUBGROUP_MATRIX_N_SIZE, SUBGROUP_MATRIX_M_SIZE>, SUBGROUP_MATRIX_N>, SUBGROUP_MATRIX_M>;

    for (var k_outer = 0u; k_outer < params.k; k_outer += TILE_K) {

        // see mul_mat_decls.tmpl
        init_shmem_src0(thread_id, src0_batch_offset, offset_m, k_outer);
        init_shmem_src1(thread_id, src1_batch_offset, offset_n, k_outer);

        workgroupBarrier();

        if (subgroup_id < EXPECTED_SUBGROUPS) {

            for (var k_inner = 0u; k_inner < TILE_K; k_inner += SUBGROUP_MATRIX_K_SIZE) {

                let src0_shmem_idx_base = subgroup_m * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE * TILE_K + k_inner;
                var src0_sg_mats: array<subgroup_matrix_left<f16, SUBGROUP_MATRIX_K_SIZE, SUBGROUP_MATRIX_M_SIZE>, SUBGROUP_MATRIX_M>;
                for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                    src0_sg_mats[m] = subgroupMatrixLoad<subgroup_matrix_left<f16, SUBGROUP_MATRIX_K_SIZE, SUBGROUP_MATRIX_M_SIZE>>(
                        &shmem,
                        src0_shmem_idx_base + m * SUBGROUP_MATRIX_M_SIZE * TILE_K,
                        false,
                        TILE_K
                    );
                }

                let src1_shmem_idx_base = TILE_SRC0_SHMEM + subgroup_n * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE * TILE_K + k_inner;
                for (var n = 0u; n < SUBGROUP_MATRIX_N; n++) {
                    let src1_sg_mat = subgroupMatrixLoad<subgroup_matrix_right<f16, SUBGROUP_MATRIX_N_SIZE, SUBGROUP_MATRIX_K_SIZE>>(
                        &shmem,
                        src1_shmem_idx_base + n * SUBGROUP_MATRIX_N_SIZE * TILE_K,
                        true,
                        TILE_K
                    );
                    for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                        acc_sg_mat[m][n] = subgroupMatrixMultiplyAccumulate(src0_sg_mats[m], src1_sg_mat, acc_sg_mat[m][n]);
                    }
                }
            }
        }

        workgroupBarrier();
    }

    let dst_batch_offset = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride;

    // Stage the subgroup matrix tiles into shared memory
    // This uses WG_M_SG_TILE_SIZE as the stride (number of columns in the workgroup tile).
    let WG_TILE_STRIDE = WG_M_SG_TILE_SIZE;
    let tile_row_base_local = subgroup_n * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;
    let tile_col_base_local = subgroup_m * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;

    if (subgroup_id < EXPECTED_SUBGROUPS) { // 2-5% performance hit :(
        for (var n = 0u; n < SUBGROUP_MATRIX_N; n++) {
            for (var m = 0u; m < SUBGROUP_MATRIX_M; m++) {
                let local_row = tile_row_base_local + n * SUBGROUP_MATRIX_N_SIZE;
                let local_col = tile_col_base_local + m * SUBGROUP_MATRIX_M_SIZE;
                let out_base = local_row * WG_TILE_STRIDE + local_col;
                subgroupMatrixStore(&shmem, out_base, acc_sg_mat[m][n], true, WG_TILE_STRIDE);
            }
        }
    }

    workgroupBarrier();

    // Cooperative write: iterate over the entire workgroup tile
    let tile_rows = WG_N_SG_TILE_SIZE;
    let tile_cols = WG_M_SG_TILE_SIZE;
    let total_tile_elems = tile_rows * tile_cols;
    let tile_dst_row_base = wg_m * SUBGROUP_M * SUBGROUP_MATRIX_M * SUBGROUP_MATRIX_M_SIZE;
    let tile_dst_col_base = wg_n * SUBGROUP_N * SUBGROUP_MATRIX_N * SUBGROUP_MATRIX_N_SIZE;

    for (var idx = thread_id * 1; idx < total_tile_elems; idx += TOTAL_WORKGROUP_SIZE * 1) {
        let local_row = idx % WG_TILE_STRIDE;
        let local_col = idx / WG_TILE_STRIDE;

        let global_row = tile_dst_row_base + local_row;
        let global_col = tile_dst_col_base + local_col;

        if (global_col < params.n && global_row < params.m) {
            let dst_idx = dst_batch_offset + global_col * params.m + global_row;
            store_dst(idx, dst_idx/1);
        }
    }
})";

const char* wgsl_mul_mat_vec_f32_f32_vec = R"(enable f16;

fn inner_dot(src0_val: vec4<f32>, src1_val: vec4<f32>) -> f32 {
    return f32(dot(vec4<f32>(src0_val), src1_val));
}

fn store_val(group_base: u32) -> vec4<f32> {
    return vec4<f32>(partial_sums[group_base],
                     partial_sums[group_base + THREADS_PER_OUTPUT],
                     partial_sums[group_base + THREADS_PER_OUTPUT * 2],
                     partial_sums[group_base + THREADS_PER_OUTPUT * 3]);
}

fn mul_acc(tig:u32, tile_size: u32, idx_base: u32, k_outer: u32) -> f32 {
    var local_sum = 0.0;
    for (var i = tig * 4; i < tile_size; i += THREADS_PER_OUTPUT * 4) {
        let a = src0[(idx_base + k_outer + i) / 4];
        let b = shared_vector[i / 4];
        local_sum += inner_dot(a, b);
    }
    return local_sum;
}



struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<vec4<f32>>; // Matrix (M x K)
@group(0) @binding(1) var<storage, read_write> src1: array<vec4<f32>>; // Vector (K x 1, transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<vec4<f32>>;  // Result vector (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

override WORKGROUP_SIZE: u32;
override TILE_K: u32;
override OUTPUTS_PER_WG: u32;
override THREADS_PER_OUTPUT = WORKGROUP_SIZE / OUTPUTS_PER_WG;

// Shared memory for collaborative loading and reduction
var<workgroup> shared_vector: array<vec4<f32>, TILE_K/4>;  // Cache vector tile
var<workgroup> partial_sums: array<f32, WORKGROUP_SIZE>;   // For reduction

@compute @workgroup_size(WORKGROUP_SIZE)
fn main(
    @builtin(local_invocation_id) local_id: vec3<u32>,
    @builtin(workgroup_id) wg_id: vec3<u32>,
    @builtin(num_workgroups) num_wg: vec3<u32>) {
    let thread_id = local_id.x;

    // Handle batch dimensions
    let total_batches = params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    let wg_linear = wg_id.y * num_wg.x + wg_id.x;
    let output_groups = (params.m + OUTPUTS_PER_WG - 1u) / OUTPUTS_PER_WG;
    let batch_idx = wg_linear / output_groups;
    if (batch_idx >= total_batches) {
        return;
    }

    // Which of the outputs does this thread belong to?
    let thread_group = thread_id / THREADS_PER_OUTPUT;
    let thread_in_group = thread_id % THREADS_PER_OUTPUT;

    // Each workgroup computes OUTPUTS_PER_WG consecutive outputs
    let output_row = (wg_linear % output_groups) * OUTPUTS_PER_WG + thread_group;

    let dst2_stride = params.m * params.n;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;
    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + output_row * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;
    let dst_idx = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + output_row;

    var local_sum = 0.0;

    // Each thread processes multiple K elements and accumulates
    for (var k_tile = 0u; k_tile < params.k; k_tile += TILE_K) {
        let tile_size = min(TILE_K, params.k - k_tile);

        // Cooperatively load vector tile into shared memory (all threads)
        for (var i = thread_id * 4; i < tile_size; i += WORKGROUP_SIZE * 4) {
            shared_vector[i / 4] = src1[(src1_idx_base + k_tile + i) / 4];
        }

        workgroupBarrier();

        if (output_row < params.m) {
            local_sum += mul_acc(thread_in_group, tile_size, src0_idx_base, k_tile);
        }

        workgroupBarrier();
    }

    // Store partial sums and reduce within each partition
    partial_sums[thread_id] = local_sum;
    workgroupBarrier();
    let group_base = thread_group * THREADS_PER_OUTPUT;
    let thread_base = group_base + thread_in_group;
    var offset = THREADS_PER_OUTPUT / 2;
    while (offset > 0) {
        if (thread_in_group < offset) {
            partial_sums[thread_base] += partial_sums[thread_base + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }

    // Store back to global memory
    if (output_row < params.m && thread_group % 4 == 0 && thread_in_group == 0) {
        dst[dst_idx / 4] = store_val(group_base);
    }
})";

const char* wgsl_mul_mat_vec_f32_f32 = R"(enable f16;

fn inner_dot(src0_val: f32, src1_val: f32) -> f32 {
    return f32(src0_val) * f32(src1_val);
}

fn store_val(group_base: u32) -> f32 {
    return partial_sums[group_base];
}

fn mul_acc(tig:u32, tile_size: u32, idx_base: u32, k_outer: u32) -> f32 {
    var local_sum = 0.0;
    for (var i = tig * 1; i < tile_size; i += THREADS_PER_OUTPUT * 1) {
        let a = src0[(idx_base + k_outer + i) / 1];
        let b = shared_vector[i / 1];
        local_sum += inner_dot(a, b);
    }
    return local_sum;
}



struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<f32>; // Matrix (M x K)
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // Vector (K x 1, transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>;  // Result vector (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

override WORKGROUP_SIZE: u32;
override TILE_K: u32;
override OUTPUTS_PER_WG: u32;
override THREADS_PER_OUTPUT = WORKGROUP_SIZE / OUTPUTS_PER_WG;

// Shared memory for collaborative loading and reduction
var<workgroup> shared_vector: array<f32, TILE_K/1>;  // Cache vector tile
var<workgroup> partial_sums: array<f32, WORKGROUP_SIZE>;   // For reduction

@compute @workgroup_size(WORKGROUP_SIZE)
fn main(
    @builtin(local_invocation_id) local_id: vec3<u32>,
    @builtin(workgroup_id) wg_id: vec3<u32>,
    @builtin(num_workgroups) num_wg: vec3<u32>) {
    let thread_id = local_id.x;

    // Handle batch dimensions
    let total_batches = params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    let wg_linear = wg_id.y * num_wg.x + wg_id.x;
    let output_groups = (params.m + OUTPUTS_PER_WG - 1u) / OUTPUTS_PER_WG;
    let batch_idx = wg_linear / output_groups;
    if (batch_idx >= total_batches) {
        return;
    }

    // Which of the outputs does this thread belong to?
    let thread_group = thread_id / THREADS_PER_OUTPUT;
    let thread_in_group = thread_id % THREADS_PER_OUTPUT;

    // Each workgroup computes OUTPUTS_PER_WG consecutive outputs
    let output_row = (wg_linear % output_groups) * OUTPUTS_PER_WG + thread_group;

    let dst2_stride = params.m * params.n;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;
    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + output_row * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;
    let dst_idx = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + output_row;

    var local_sum = 0.0;

    // Each thread processes multiple K elements and accumulates
    for (var k_tile = 0u; k_tile < params.k; k_tile += TILE_K) {
        let tile_size = min(TILE_K, params.k - k_tile);

        // Cooperatively load vector tile into shared memory (all threads)
        for (var i = thread_id * 1; i < tile_size; i += WORKGROUP_SIZE * 1) {
            shared_vector[i / 1] = src1[(src1_idx_base + k_tile + i) / 1];
        }

        workgroupBarrier();

        if (output_row < params.m) {
            local_sum += mul_acc(thread_in_group, tile_size, src0_idx_base, k_tile);
        }

        workgroupBarrier();
    }

    // Store partial sums and reduce within each partition
    partial_sums[thread_id] = local_sum;
    workgroupBarrier();
    let group_base = thread_group * THREADS_PER_OUTPUT;
    let thread_base = group_base + thread_in_group;
    var offset = THREADS_PER_OUTPUT / 2;
    while (offset > 0) {
        if (thread_in_group < offset) {
            partial_sums[thread_base] += partial_sums[thread_base + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }

    // Store back to global memory
    if (output_row < params.m && thread_group % 1 == 0 && thread_in_group == 0) {
        dst[dst_idx / 1] = store_val(group_base);
    }
})";

const char* wgsl_mul_mat_vec_f16_f32_vec = R"(enable f16;

fn inner_dot(src0_val: vec4<f16>, src1_val: vec4<f32>) -> f32 {
    return f32(dot(vec4<f32>(src0_val), src1_val));
}

fn store_val(group_base: u32) -> vec4<f32> {
    return vec4<f32>(partial_sums[group_base],
                     partial_sums[group_base + THREADS_PER_OUTPUT],
                     partial_sums[group_base + THREADS_PER_OUTPUT * 2],
                     partial_sums[group_base + THREADS_PER_OUTPUT * 3]);
}

fn mul_acc(tig:u32, tile_size: u32, idx_base: u32, k_outer: u32) -> f32 {
    var local_sum = 0.0;
    for (var i = tig * 4; i < tile_size; i += THREADS_PER_OUTPUT * 4) {
        let a = src0[(idx_base + k_outer + i) / 4];
        let b = shared_vector[i / 4];
        local_sum += inner_dot(a, b);
    }
    return local_sum;
}



struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<vec4<f16>>; // Matrix (M x K)
@group(0) @binding(1) var<storage, read_write> src1: array<vec4<f32>>; // Vector (K x 1, transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<vec4<f32>>;  // Result vector (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

override WORKGROUP_SIZE: u32;
override TILE_K: u32;
override OUTPUTS_PER_WG: u32;
override THREADS_PER_OUTPUT = WORKGROUP_SIZE / OUTPUTS_PER_WG;

// Shared memory for collaborative loading and reduction
var<workgroup> shared_vector: array<vec4<f32>, TILE_K/4>;  // Cache vector tile
var<workgroup> partial_sums: array<f32, WORKGROUP_SIZE>;   // For reduction

@compute @workgroup_size(WORKGROUP_SIZE)
fn main(
    @builtin(local_invocation_id) local_id: vec3<u32>,
    @builtin(workgroup_id) wg_id: vec3<u32>,
    @builtin(num_workgroups) num_wg: vec3<u32>) {
    let thread_id = local_id.x;

    // Handle batch dimensions
    let total_batches = params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    let wg_linear = wg_id.y * num_wg.x + wg_id.x;
    let output_groups = (params.m + OUTPUTS_PER_WG - 1u) / OUTPUTS_PER_WG;
    let batch_idx = wg_linear / output_groups;
    if (batch_idx >= total_batches) {
        return;
    }

    // Which of the outputs does this thread belong to?
    let thread_group = thread_id / THREADS_PER_OUTPUT;
    let thread_in_group = thread_id % THREADS_PER_OUTPUT;

    // Each workgroup computes OUTPUTS_PER_WG consecutive outputs
    let output_row = (wg_linear % output_groups) * OUTPUTS_PER_WG + thread_group;

    let dst2_stride = params.m * params.n;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;
    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + output_row * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;
    let dst_idx = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + output_row;

    var local_sum = 0.0;

    // Each thread processes multiple K elements and accumulates
    for (var k_tile = 0u; k_tile < params.k; k_tile += TILE_K) {
        let tile_size = min(TILE_K, params.k - k_tile);

        // Cooperatively load vector tile into shared memory (all threads)
        for (var i = thread_id * 4; i < tile_size; i += WORKGROUP_SIZE * 4) {
            shared_vector[i / 4] = src1[(src1_idx_base + k_tile + i) / 4];
        }

        workgroupBarrier();

        if (output_row < params.m) {
            local_sum += mul_acc(thread_in_group, tile_size, src0_idx_base, k_tile);
        }

        workgroupBarrier();
    }

    // Store partial sums and reduce within each partition
    partial_sums[thread_id] = local_sum;
    workgroupBarrier();
    let group_base = thread_group * THREADS_PER_OUTPUT;
    let thread_base = group_base + thread_in_group;
    var offset = THREADS_PER_OUTPUT / 2;
    while (offset > 0) {
        if (thread_in_group < offset) {
            partial_sums[thread_base] += partial_sums[thread_base + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }

    // Store back to global memory
    if (output_row < params.m && thread_group % 4 == 0 && thread_in_group == 0) {
        dst[dst_idx / 4] = store_val(group_base);
    }
})";

const char* wgsl_mul_mat_vec_f16_f32 = R"(enable f16;

fn inner_dot(src0_val: f16, src1_val: f32) -> f32 {
    return f32(src0_val) * f32(src1_val);
}

fn store_val(group_base: u32) -> f32 {
    return partial_sums[group_base];
}

fn mul_acc(tig:u32, tile_size: u32, idx_base: u32, k_outer: u32) -> f32 {
    var local_sum = 0.0;
    for (var i = tig * 1; i < tile_size; i += THREADS_PER_OUTPUT * 1) {
        let a = src0[(idx_base + k_outer + i) / 1];
        let b = shared_vector[i / 1];
        local_sum += inner_dot(a, b);
    }
    return local_sum;
}



struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<f16>; // Matrix (M x K)
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // Vector (K x 1, transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>;  // Result vector (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

override WORKGROUP_SIZE: u32;
override TILE_K: u32;
override OUTPUTS_PER_WG: u32;
override THREADS_PER_OUTPUT = WORKGROUP_SIZE / OUTPUTS_PER_WG;

// Shared memory for collaborative loading and reduction
var<workgroup> shared_vector: array<f32, TILE_K/1>;  // Cache vector tile
var<workgroup> partial_sums: array<f32, WORKGROUP_SIZE>;   // For reduction

@compute @workgroup_size(WORKGROUP_SIZE)
fn main(
    @builtin(local_invocation_id) local_id: vec3<u32>,
    @builtin(workgroup_id) wg_id: vec3<u32>,
    @builtin(num_workgroups) num_wg: vec3<u32>) {
    let thread_id = local_id.x;

    // Handle batch dimensions
    let total_batches = params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    let wg_linear = wg_id.y * num_wg.x + wg_id.x;
    let output_groups = (params.m + OUTPUTS_PER_WG - 1u) / OUTPUTS_PER_WG;
    let batch_idx = wg_linear / output_groups;
    if (batch_idx >= total_batches) {
        return;
    }

    // Which of the outputs does this thread belong to?
    let thread_group = thread_id / THREADS_PER_OUTPUT;
    let thread_in_group = thread_id % THREADS_PER_OUTPUT;

    // Each workgroup computes OUTPUTS_PER_WG consecutive outputs
    let output_row = (wg_linear % output_groups) * OUTPUTS_PER_WG + thread_group;

    let dst2_stride = params.m * params.n;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;
    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + output_row * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;
    let dst_idx = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + output_row;

    var local_sum = 0.0;

    // Each thread processes multiple K elements and accumulates
    for (var k_tile = 0u; k_tile < params.k; k_tile += TILE_K) {
        let tile_size = min(TILE_K, params.k - k_tile);

        // Cooperatively load vector tile into shared memory (all threads)
        for (var i = thread_id * 1; i < tile_size; i += WORKGROUP_SIZE * 1) {
            shared_vector[i / 1] = src1[(src1_idx_base + k_tile + i) / 1];
        }

        workgroupBarrier();

        if (output_row < params.m) {
            local_sum += mul_acc(thread_in_group, tile_size, src0_idx_base, k_tile);
        }

        workgroupBarrier();
    }

    // Store partial sums and reduce within each partition
    partial_sums[thread_id] = local_sum;
    workgroupBarrier();
    let group_base = thread_group * THREADS_PER_OUTPUT;
    let thread_base = group_base + thread_in_group;
    var offset = THREADS_PER_OUTPUT / 2;
    while (offset > 0) {
        if (thread_in_group < offset) {
            partial_sums[thread_base] += partial_sums[thread_base + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }

    // Store back to global memory
    if (output_row < params.m && thread_group % 1 == 0 && thread_in_group == 0) {
        dst[dst_idx / 1] = store_val(group_base);
    }
})";

const char* wgsl_mul_mat_vec_f16_f16_vec = R"(enable f16;

fn inner_dot(src0_val: vec4<f16>, src1_val: vec4<f16>) -> f32 {
    return f32(dot(vec4<f16>(src0_val), src1_val));
}

fn store_val(group_base: u32) -> vec4<f32> {
    return vec4<f32>(partial_sums[group_base],
                     partial_sums[group_base + THREADS_PER_OUTPUT],
                     partial_sums[group_base + THREADS_PER_OUTPUT * 2],
                     partial_sums[group_base + THREADS_PER_OUTPUT * 3]);
}

fn mul_acc(tig:u32, tile_size: u32, idx_base: u32, k_outer: u32) -> f32 {
    var local_sum = 0.0;
    for (var i = tig * 4; i < tile_size; i += THREADS_PER_OUTPUT * 4) {
        let a = src0[(idx_base + k_outer + i) / 4];
        let b = shared_vector[i / 4];
        local_sum += inner_dot(a, b);
    }
    return local_sum;
}



struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<vec4<f16>>; // Matrix (M x K)
@group(0) @binding(1) var<storage, read_write> src1: array<vec4<f16>>; // Vector (K x 1, transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<vec4<f32>>;  // Result vector (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

override WORKGROUP_SIZE: u32;
override TILE_K: u32;
override OUTPUTS_PER_WG: u32;
override THREADS_PER_OUTPUT = WORKGROUP_SIZE / OUTPUTS_PER_WG;

// Shared memory for collaborative loading and reduction
var<workgroup> shared_vector: array<vec4<f16>, TILE_K/4>;  // Cache vector tile
var<workgroup> partial_sums: array<f32, WORKGROUP_SIZE>;   // For reduction

@compute @workgroup_size(WORKGROUP_SIZE)
fn main(
    @builtin(local_invocation_id) local_id: vec3<u32>,
    @builtin(workgroup_id) wg_id: vec3<u32>,
    @builtin(num_workgroups) num_wg: vec3<u32>) {
    let thread_id = local_id.x;

    // Handle batch dimensions
    let total_batches = params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    let wg_linear = wg_id.y * num_wg.x + wg_id.x;
    let output_groups = (params.m + OUTPUTS_PER_WG - 1u) / OUTPUTS_PER_WG;
    let batch_idx = wg_linear / output_groups;
    if (batch_idx >= total_batches) {
        return;
    }

    // Which of the outputs does this thread belong to?
    let thread_group = thread_id / THREADS_PER_OUTPUT;
    let thread_in_group = thread_id % THREADS_PER_OUTPUT;

    // Each workgroup computes OUTPUTS_PER_WG consecutive outputs
    let output_row = (wg_linear % output_groups) * OUTPUTS_PER_WG + thread_group;

    let dst2_stride = params.m * params.n;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;
    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + output_row * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;
    let dst_idx = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + output_row;

    var local_sum = 0.0;

    // Each thread processes multiple K elements and accumulates
    for (var k_tile = 0u; k_tile < params.k; k_tile += TILE_K) {
        let tile_size = min(TILE_K, params.k - k_tile);

        // Cooperatively load vector tile into shared memory (all threads)
        for (var i = thread_id * 4; i < tile_size; i += WORKGROUP_SIZE * 4) {
            shared_vector[i / 4] = src1[(src1_idx_base + k_tile + i) / 4];
        }

        workgroupBarrier();

        if (output_row < params.m) {
            local_sum += mul_acc(thread_in_group, tile_size, src0_idx_base, k_tile);
        }

        workgroupBarrier();
    }

    // Store partial sums and reduce within each partition
    partial_sums[thread_id] = local_sum;
    workgroupBarrier();
    let group_base = thread_group * THREADS_PER_OUTPUT;
    let thread_base = group_base + thread_in_group;
    var offset = THREADS_PER_OUTPUT / 2;
    while (offset > 0) {
        if (thread_in_group < offset) {
            partial_sums[thread_base] += partial_sums[thread_base + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }

    // Store back to global memory
    if (output_row < params.m && thread_group % 4 == 0 && thread_in_group == 0) {
        dst[dst_idx / 4] = store_val(group_base);
    }
})";

const char* wgsl_mul_mat_vec_f16_f16 = R"(enable f16;

fn inner_dot(src0_val: f16, src1_val: f16) -> f32 {
    return f32(src0_val) * f32(src1_val);
}

fn store_val(group_base: u32) -> f32 {
    return partial_sums[group_base];
}

fn mul_acc(tig:u32, tile_size: u32, idx_base: u32, k_outer: u32) -> f32 {
    var local_sum = 0.0;
    for (var i = tig * 1; i < tile_size; i += THREADS_PER_OUTPUT * 1) {
        let a = src0[(idx_base + k_outer + i) / 1];
        let b = shared_vector[i / 1];
        local_sum += inner_dot(a, b);
    }
    return local_sum;
}



struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<f16>; // Matrix (M x K)
@group(0) @binding(1) var<storage, read_write> src1: array<f16>; // Vector (K x 1, transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>;  // Result vector (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

override WORKGROUP_SIZE: u32;
override TILE_K: u32;
override OUTPUTS_PER_WG: u32;
override THREADS_PER_OUTPUT = WORKGROUP_SIZE / OUTPUTS_PER_WG;

// Shared memory for collaborative loading and reduction
var<workgroup> shared_vector: array<f16, TILE_K/1>;  // Cache vector tile
var<workgroup> partial_sums: array<f32, WORKGROUP_SIZE>;   // For reduction

@compute @workgroup_size(WORKGROUP_SIZE)
fn main(
    @builtin(local_invocation_id) local_id: vec3<u32>,
    @builtin(workgroup_id) wg_id: vec3<u32>,
    @builtin(num_workgroups) num_wg: vec3<u32>) {
    let thread_id = local_id.x;

    // Handle batch dimensions
    let total_batches = params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    let wg_linear = wg_id.y * num_wg.x + wg_id.x;
    let output_groups = (params.m + OUTPUTS_PER_WG - 1u) / OUTPUTS_PER_WG;
    let batch_idx = wg_linear / output_groups;
    if (batch_idx >= total_batches) {
        return;
    }

    // Which of the outputs does this thread belong to?
    let thread_group = thread_id / THREADS_PER_OUTPUT;
    let thread_in_group = thread_id % THREADS_PER_OUTPUT;

    // Each workgroup computes OUTPUTS_PER_WG consecutive outputs
    let output_row = (wg_linear % output_groups) * OUTPUTS_PER_WG + thread_group;

    let dst2_stride = params.m * params.n;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;
    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + output_row * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;
    let dst_idx = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + output_row;

    var local_sum = 0.0;

    // Each thread processes multiple K elements and accumulates
    for (var k_tile = 0u; k_tile < params.k; k_tile += TILE_K) {
        let tile_size = min(TILE_K, params.k - k_tile);

        // Cooperatively load vector tile into shared memory (all threads)
        for (var i = thread_id * 1; i < tile_size; i += WORKGROUP_SIZE * 1) {
            shared_vector[i / 1] = src1[(src1_idx_base + k_tile + i) / 1];
        }

        workgroupBarrier();

        if (output_row < params.m) {
            local_sum += mul_acc(thread_in_group, tile_size, src0_idx_base, k_tile);
        }

        workgroupBarrier();
    }

    // Store partial sums and reduce within each partition
    partial_sums[thread_id] = local_sum;
    workgroupBarrier();
    let group_base = thread_group * THREADS_PER_OUTPUT;
    let thread_base = group_base + thread_in_group;
    var offset = THREADS_PER_OUTPUT / 2;
    while (offset > 0) {
        if (thread_in_group < offset) {
            partial_sums[thread_base] += partial_sums[thread_base + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }

    // Store back to global memory
    if (output_row < params.m && thread_group % 1 == 0 && thread_in_group == 0) {
        dst[dst_idx / 1] = store_val(group_base);
    }
})";

const char* wgsl_mul_mat_vec_q4_0_f32 = R"(enable f16;

fn get_byte(value: u32, index: u32) -> u32 {
    return (value >> (index * 8)) & 0xFF;
}

fn get_byte_i32(value: u32, index: u32) -> i32 {
    return bitcast<i32>(((value >> (index * 8)) & 0xFF) << 24) >> 24;
}

fn inner_dot(src0_val: f16, src1_val: f32) -> f32 {
    return f32(src0_val) * f32(src1_val);
}

fn store_val(group_base: u32) -> f32 {
    return partial_sums[group_base];
}

const BLOCK_SIZE = 32;
const NQ = 16u; // number of weights per thread
const F16_PER_BLOCK = 9u; // 1 scale + 8x4 packed weights
const WEIGHTS_PER_F16 = 4u; // 4 weights per f16
const F16_PER_THREAD = NQ / WEIGHTS_PER_F16;

fn mul_acc(tig:u32, tile_size: u32, idx_base: u32, k_outer: u32) -> f32 {
    var local_sum = 0.0;
    for (var i = tig * NQ; i < tile_size; i += THREADS_PER_OUTPUT * NQ) {
        let blck_idx = i / BLOCK_SIZE;
        let block_offset = (i % BLOCK_SIZE) / WEIGHTS_PER_F16;
        let scale_idx = (idx_base + k_outer / BLOCK_SIZE + blck_idx) * F16_PER_BLOCK;
        // each f16 contains offsets [block_offset, block_offset + 1] and [block_offset + 16, block_offset + 17]
        let shmem_idx = blck_idx * BLOCK_SIZE + block_offset * 2u;
        let d = f32(src0[scale_idx]);
        for (var j = 0u; j < F16_PER_THREAD; j += 2) {
            let q_0 = src0[scale_idx + 1 + block_offset + j];
            let q_1 = src0[scale_idx + 1 + block_offset + j + 1];
            let q_packed = bitcast<u32>(vec2(q_0, q_1));
            for (var k: u32 = 0; k < 4; k++) {
                let q_byte = get_byte(q_packed, k);
                let q_hi = (f32((q_byte >> 4) & 0xF) - 8.0) * d;
                let q_lo = (f32(q_byte & 0xF) - 8.0) * d;
                local_sum += q_lo * shared_vector[shmem_idx + j * 2 + k];
                local_sum += q_hi * shared_vector[shmem_idx + j * 2 + k + 16];
            }
        }
    }
    return local_sum;
}



struct MulMatParams {
    offset_src0: u32,
    offset_src1: u32,
    offset_dst: u32,
    m: u32,
    n: u32,
    k: u32,
    stride_01: u32,
    stride_11: u32,
    stride_02: u32,
    stride_12: u32,
    stride_03: u32,
    stride_13: u32,
    bs02: u32,
    bs03: u32,
    broadcast2: u32,
    broadcast3: u32
};

@group(0) @binding(0) var<storage, read_write> src0: array<f16>; // Matrix (M x K)
@group(0) @binding(1) var<storage, read_write> src1: array<f32>; // Vector (K x 1, transposed)
@group(0) @binding(2) var<storage, read_write> dst: array<f32>;  // Result vector (transposed)

@group(0) @binding(3) var<uniform> params: MulMatParams;

override WORKGROUP_SIZE: u32;
override TILE_K: u32;
override OUTPUTS_PER_WG: u32;
override THREADS_PER_OUTPUT = WORKGROUP_SIZE / OUTPUTS_PER_WG;

// Shared memory for collaborative loading and reduction
var<workgroup> shared_vector: array<f32, TILE_K/1>;  // Cache vector tile
var<workgroup> partial_sums: array<f32, WORKGROUP_SIZE>;   // For reduction

@compute @workgroup_size(WORKGROUP_SIZE)
fn main(
    @builtin(local_invocation_id) local_id: vec3<u32>,
    @builtin(workgroup_id) wg_id: vec3<u32>,
    @builtin(num_workgroups) num_wg: vec3<u32>) {
    let thread_id = local_id.x;

    // Handle batch dimensions
    let total_batches = params.bs02 * params.broadcast2 * params.bs03 * params.broadcast3;
    let wg_linear = wg_id.y * num_wg.x + wg_id.x;
    let output_groups = (params.m + OUTPUTS_PER_WG - 1u) / OUTPUTS_PER_WG;
    let batch_idx = wg_linear / output_groups;
    if (batch_idx >= total_batches) {
        return;
    }

    // Which of the outputs does this thread belong to?
    let thread_group = thread_id / THREADS_PER_OUTPUT;
    let thread_in_group = thread_id % THREADS_PER_OUTPUT;

    // Each workgroup computes OUTPUTS_PER_WG consecutive outputs
    let output_row = (wg_linear % output_groups) * OUTPUTS_PER_WG + thread_group;

    let dst2_stride = params.m * params.n;
    let dst2_idx = batch_idx % (params.bs02 * params.broadcast2);
    let dst3_stride = dst2_stride * params.bs02 * params.broadcast2;
    let dst3_idx = batch_idx / (params.bs02 * params.broadcast2);
    let src03_idx = dst3_idx / params.broadcast3;
    let src13_idx = dst3_idx;
    let src02_idx = dst2_idx / params.broadcast2;
    let src12_idx = dst2_idx;

    let src0_idx_base = params.offset_src0 + src03_idx * params.stride_03 + src02_idx * params.stride_02 + output_row * params.stride_01;
    let src1_idx_base = params.offset_src1 + src13_idx * params.stride_13 + src12_idx * params.stride_12;
    let dst_idx = params.offset_dst + dst3_idx * dst3_stride + dst2_idx * dst2_stride + output_row;

    var local_sum = 0.0;

    // Each thread processes multiple K elements and accumulates
    for (var k_tile = 0u; k_tile < params.k; k_tile += TILE_K) {
        let tile_size = min(TILE_K, params.k - k_tile);

        // Cooperatively load vector tile into shared memory (all threads)
        for (var i = thread_id * 1; i < tile_size; i += WORKGROUP_SIZE * 1) {
            shared_vector[i / 1] = src1[(src1_idx_base + k_tile + i) / 1];
        }

        workgroupBarrier();

        if (output_row < params.m) {
            local_sum += mul_acc(thread_in_group, tile_size, src0_idx_base, k_tile);
        }

        workgroupBarrier();
    }

    // Store partial sums and reduce within each partition
    partial_sums[thread_id] = local_sum;
    workgroupBarrier();
    let group_base = thread_group * THREADS_PER_OUTPUT;
    let thread_base = group_base + thread_in_group;
    var offset = THREADS_PER_OUTPUT / 2;
    while (offset > 0) {
        if (thread_in_group < offset) {
            partial_sums[thread_base] += partial_sums[thread_base + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }

    // Store back to global memory
    if (output_row < params.m && thread_group % 1 == 0 && thread_in_group == 0) {
        dst[dst_idx / 1] = store_val(group_base);
    }
})";

const char* wgsl_rms_norm = R"(struct Params {
    offset_src: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of src/dst
    ne0: u32,
    ne1: u32,
    ne2: u32,
    ne3: u32,

    eps: f32
};

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

fn update(src_offset: u32, dst_offset: u32, scale: f32) {
    dst[dst_offset] = scale * src[src_offset];
}

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;



override wg_size: u32;
var<workgroup> scratch: array<f32, wg_size>;

@compute @workgroup_size(wg_size)
fn main(@builtin(workgroup_id) wid: vec3<u32>,
        @builtin(local_invocation_id) lid: vec3<u32>) {

    // one thread per row
    var i = wid.x;
    let i3 = i / (params.ne2 * params.ne1);
    i = i % (params.ne2 * params.ne1);
    let i2 = i / params.ne1;
    let i1 = i % params.ne1;
    let i_src_row = params.offset_src + i3 * params.stride_src3 + i2 * params.stride_src2 + i1 * params.stride_src1;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;

    let elems = (params.ne0 + wg_size - 1) / wg_size;

    var sum = 0.0f;
    var col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        sum += pow(src[i_src_row + col], 2.0);
        col += wg_size;
    }

    scratch[lid.x] = sum;
    workgroupBarrier();
    var offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] += scratch[lid.x + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    sum = scratch[0];

    let scale = 1.0/sqrt(sum/f32(params.ne0) + params.eps);
    col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        update(i_src_row + col, i_dst_row + col, scale);
        col += wg_size;
    }
})";

const char* wgsl_rms_norm_inplace = R"(struct Params {
    offset_src: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of src/dst
    ne0: u32,
    ne1: u32,
    ne2: u32,
    ne3: u32,

    eps: f32
};

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

fn update(src_offset: u32, dst_offset: u32, scale: f32) {
    src[dst_offset] = scale * src[src_offset];
}

@group(0) @binding(1)
var<uniform> params: Params;



override wg_size: u32;
var<workgroup> scratch: array<f32, wg_size>;

@compute @workgroup_size(wg_size)
fn main(@builtin(workgroup_id) wid: vec3<u32>,
        @builtin(local_invocation_id) lid: vec3<u32>) {

    // one thread per row
    var i = wid.x;
    let i3 = i / (params.ne2 * params.ne1);
    i = i % (params.ne2 * params.ne1);
    let i2 = i / params.ne1;
    let i1 = i % params.ne1;
    let i_src_row = params.offset_src + i3 * params.stride_src3 + i2 * params.stride_src2 + i1 * params.stride_src1;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;

    let elems = (params.ne0 + wg_size - 1) / wg_size;

    var sum = 0.0f;
    var col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        sum += pow(src[i_src_row + col], 2.0);
        col += wg_size;
    }

    scratch[lid.x] = sum;
    workgroupBarrier();
    var offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] += scratch[lid.x + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    sum = scratch[0];

    let scale = 1.0/sqrt(sum/f32(params.ne0) + params.eps);
    col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        update(i_src_row + col, i_dst_row + col, scale);
        col += wg_size;
    }
})";

const char* wgsl_rope_f32 = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_src2: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    n_threads: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    n_dims: u32,
    mode: u32,
    theta_scale: f32,
    attn_factor: f32,
    freq_scale: f32,
    ext_factor: f32,
    corr_dim0: f32,
    corr_dim1: f32,
    sections0: u32,
    sections1: u32,
    sections2: u32,
    sections3: u32
};

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> src1: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(3)
var<uniform> params: Params;

fn freq_factor(i: u32) -> f32 {
    return 1.0f;
}

fn rotate(i_dst0: u32, i_dst1: u32, out0: f32, out1: f32) {
    dst[i_dst0] = f32(out0);
    dst[i_dst1] = f32(out1);
}



fn rope_yarn_ramp(low: f32, high: f32, i: u32) -> f32 {
    let y = (f32(i / 2) - low) / max(0.001f, high - low);
    return 1.0f - min(1.0f, max(0.0f, y));
}

// returns vector of (cos_theta, sin_theta)
// TODO: check performance of instantiating once on the CPU and passed as buffer, since it's repeated per-row
fn rope_yarn(theta_extrap: f32, i: u32) -> vec2<f32> {
    var mscale = params.attn_factor;
    var theta = params.freq_scale * theta_extrap;
    if (params.ext_factor != 0.0f) {
        let ramp_mix = rope_yarn_ramp(params.corr_dim0, params.corr_dim1, i) * params.ext_factor;
        theta = theta * (1 - ramp_mix) + theta_extrap * ramp_mix;
        mscale *= 1.0f + 0.1f * log(1.0f / params.freq_scale);
    }
    return vec2<f32>(cos(theta) * mscale, sin(theta) * mscale);
}

fn pair_base(i0: u32, div_2: bool) -> u32 {
    if (div_2) {
        return i0 / 2;
    } else {
        return i0;
    }
}

fn pair_offset(is_neox: bool, is_mrope: bool, is_vision: bool) -> u32 {
    if (is_vision) {
        return params.n_dims;
    } else if (is_neox || is_mrope) {
        return params.n_dims / 2;
    } else {
        return 1;
    }
}

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    // two elements per thread
    if (gid.x >= params.n_threads) {
        return;
    }

    let is_neox = bool(params.mode & 2);
    let is_mrope = bool(params.mode & 8);
    let is_imrope = params.mode == 40;
    let is_vision = params.mode == 24;

    var i = gid.x * 2; // start index for this thread
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_src_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;

    if (i0 >= params.n_dims && !is_vision) {
        let i_src = i_src_row + i0;
        let i_dst = i_dst_row + i0;
        rotate(i_dst, i_dst + 1, f32(src0[i_src]), f32(src0[i_src + 1]));
        return;
    }

    var theta_base_mult: u32 = 0;
    var theta_scale_pwr: u32 = i0 / 2;
    if (is_mrope) {
        let sect_dims = params.sections0 + params.sections1 + params.sections2 + params.sections3;
        let sec_w = params.sections1 + params.sections0;
        let sec_e = params.sections2 + sec_w;
        let sector = (i0 / 2) % sect_dims;
        if (is_imrope) {
          if (sector % 3 == 1 && sector < 3 * params.sections1) {
              theta_base_mult = 1;
          } else if (sector % 3 == 2 && sector < 3 * params.sections2) {
              theta_base_mult = 2;
          } else if (sector % 3 == 0 && sector < 3 * params.sections0) {
              theta_base_mult = 0;
          } else {
              theta_base_mult = 3;
          }
        } else {
          if (sector >= params.sections0 && sector < sec_w) {
              theta_base_mult = 1;
              if (is_vision) {
                  theta_scale_pwr = sector - params.sections0;
              }
          } else if (sector >= sec_w && sector < sec_e) {
              theta_base_mult = 2;
              if (is_vision) {
                  theta_scale_pwr = sector - sec_w;
              }
          } else if (sector >= sec_e) {
              if (is_vision) {
                  theta_scale_pwr = sector - sec_e;
                  theta_scale_pwr = (i0 / 2) % sec_e;
              }
              theta_base_mult = 3;
          } else if (is_vision) {
              theta_scale_pwr = sector;
          }
        }
    }
    let theta_base = f32(src1[params.offset_src1 + i2 + params.ne2 * theta_base_mult]) * pow(params.theta_scale, f32(theta_scale_pwr));
    let thetas = rope_yarn(theta_base/freq_factor(i0), i0);

    let i_src = i_src_row + pair_base(i0, is_neox || is_mrope || is_vision);
    let i_dst = i_dst_row + pair_base(i0, is_neox || is_mrope || is_vision);

    let x0 = f32(src0[i_src]);
    let x1 = f32(src0[i_src + pair_offset(is_neox, is_mrope, is_vision)]);
    rotate(i_dst, i_dst + pair_offset(is_neox, is_mrope, is_vision), x0 * thetas.x - x1 * thetas.y, x0 * thetas.y + x1 * thetas.x);
})";

const char* wgsl_rope_f32_inplace = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_src2: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    n_threads: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    n_dims: u32,
    mode: u32,
    theta_scale: f32,
    attn_factor: f32,
    freq_scale: f32,
    ext_factor: f32,
    corr_dim0: f32,
    corr_dim1: f32,
    sections0: u32,
    sections1: u32,
    sections2: u32,
    sections3: u32
};

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> src1: array<i32>;

@group(0) @binding(2)
var<uniform> params: Params;

fn freq_factor(i: u32) -> f32 {
    return 1.0f;
}

fn rotate(i_dst0: u32, i_dst1: u32, out0: f32, out1: f32) {
    src0[i_dst0] = f32(out0);
    src0[i_dst1] = f32(out1);
}



fn rope_yarn_ramp(low: f32, high: f32, i: u32) -> f32 {
    let y = (f32(i / 2) - low) / max(0.001f, high - low);
    return 1.0f - min(1.0f, max(0.0f, y));
}

// returns vector of (cos_theta, sin_theta)
// TODO: check performance of instantiating once on the CPU and passed as buffer, since it's repeated per-row
fn rope_yarn(theta_extrap: f32, i: u32) -> vec2<f32> {
    var mscale = params.attn_factor;
    var theta = params.freq_scale * theta_extrap;
    if (params.ext_factor != 0.0f) {
        let ramp_mix = rope_yarn_ramp(params.corr_dim0, params.corr_dim1, i) * params.ext_factor;
        theta = theta * (1 - ramp_mix) + theta_extrap * ramp_mix;
        mscale *= 1.0f + 0.1f * log(1.0f / params.freq_scale);
    }
    return vec2<f32>(cos(theta) * mscale, sin(theta) * mscale);
}

fn pair_base(i0: u32, div_2: bool) -> u32 {
    if (div_2) {
        return i0 / 2;
    } else {
        return i0;
    }
}

fn pair_offset(is_neox: bool, is_mrope: bool, is_vision: bool) -> u32 {
    if (is_vision) {
        return params.n_dims;
    } else if (is_neox || is_mrope) {
        return params.n_dims / 2;
    } else {
        return 1;
    }
}

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    // two elements per thread
    if (gid.x >= params.n_threads) {
        return;
    }

    let is_neox = bool(params.mode & 2);
    let is_mrope = bool(params.mode & 8);
    let is_imrope = params.mode == 40;
    let is_vision = params.mode == 24;

    var i = gid.x * 2; // start index for this thread
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_src_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;

    if (i0 >= params.n_dims && !is_vision) {
        let i_src = i_src_row + i0;
        let i_dst = i_dst_row + i0;
        rotate(i_dst, i_dst + 1, f32(src0[i_src]), f32(src0[i_src + 1]));
        return;
    }

    var theta_base_mult: u32 = 0;
    var theta_scale_pwr: u32 = i0 / 2;
    if (is_mrope) {
        let sect_dims = params.sections0 + params.sections1 + params.sections2 + params.sections3;
        let sec_w = params.sections1 + params.sections0;
        let sec_e = params.sections2 + sec_w;
        let sector = (i0 / 2) % sect_dims;
        if (is_imrope) {
          if (sector % 3 == 1 && sector < 3 * params.sections1) {
              theta_base_mult = 1;
          } else if (sector % 3 == 2 && sector < 3 * params.sections2) {
              theta_base_mult = 2;
          } else if (sector % 3 == 0 && sector < 3 * params.sections0) {
              theta_base_mult = 0;
          } else {
              theta_base_mult = 3;
          }
        } else {
          if (sector >= params.sections0 && sector < sec_w) {
              theta_base_mult = 1;
              if (is_vision) {
                  theta_scale_pwr = sector - params.sections0;
              }
          } else if (sector >= sec_w && sector < sec_e) {
              theta_base_mult = 2;
              if (is_vision) {
                  theta_scale_pwr = sector - sec_w;
              }
          } else if (sector >= sec_e) {
              if (is_vision) {
                  theta_scale_pwr = sector - sec_e;
                  theta_scale_pwr = (i0 / 2) % sec_e;
              }
              theta_base_mult = 3;
          } else if (is_vision) {
              theta_scale_pwr = sector;
          }
        }
    }
    let theta_base = f32(src1[params.offset_src1 + i2 + params.ne2 * theta_base_mult]) * pow(params.theta_scale, f32(theta_scale_pwr));
    let thetas = rope_yarn(theta_base/freq_factor(i0), i0);

    let i_src = i_src_row + pair_base(i0, is_neox || is_mrope || is_vision);
    let i_dst = i_dst_row + pair_base(i0, is_neox || is_mrope || is_vision);

    let x0 = f32(src0[i_src]);
    let x1 = f32(src0[i_src + pair_offset(is_neox, is_mrope, is_vision)]);
    rotate(i_dst, i_dst + pair_offset(is_neox, is_mrope, is_vision), x0 * thetas.x - x1 * thetas.y, x0 * thetas.y + x1 * thetas.x);
})";

const char* wgsl_rope_f16 = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_src2: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    n_threads: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    n_dims: u32,
    mode: u32,
    theta_scale: f32,
    attn_factor: f32,
    freq_scale: f32,
    ext_factor: f32,
    corr_dim0: f32,
    corr_dim1: f32,
    sections0: u32,
    sections1: u32,
    sections2: u32,
    sections3: u32
};

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> src1: array<i32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(3)
var<uniform> params: Params;

fn freq_factor(i: u32) -> f32 {
    return 1.0f;
}

fn rotate(i_dst0: u32, i_dst1: u32, out0: f32, out1: f32) {
    dst[i_dst0] = f16(out0);
    dst[i_dst1] = f16(out1);
}



fn rope_yarn_ramp(low: f32, high: f32, i: u32) -> f32 {
    let y = (f32(i / 2) - low) / max(0.001f, high - low);
    return 1.0f - min(1.0f, max(0.0f, y));
}

// returns vector of (cos_theta, sin_theta)
// TODO: check performance of instantiating once on the CPU and passed as buffer, since it's repeated per-row
fn rope_yarn(theta_extrap: f32, i: u32) -> vec2<f32> {
    var mscale = params.attn_factor;
    var theta = params.freq_scale * theta_extrap;
    if (params.ext_factor != 0.0f) {
        let ramp_mix = rope_yarn_ramp(params.corr_dim0, params.corr_dim1, i) * params.ext_factor;
        theta = theta * (1 - ramp_mix) + theta_extrap * ramp_mix;
        mscale *= 1.0f + 0.1f * log(1.0f / params.freq_scale);
    }
    return vec2<f32>(cos(theta) * mscale, sin(theta) * mscale);
}

fn pair_base(i0: u32, div_2: bool) -> u32 {
    if (div_2) {
        return i0 / 2;
    } else {
        return i0;
    }
}

fn pair_offset(is_neox: bool, is_mrope: bool, is_vision: bool) -> u32 {
    if (is_vision) {
        return params.n_dims;
    } else if (is_neox || is_mrope) {
        return params.n_dims / 2;
    } else {
        return 1;
    }
}

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    // two elements per thread
    if (gid.x >= params.n_threads) {
        return;
    }

    let is_neox = bool(params.mode & 2);
    let is_mrope = bool(params.mode & 8);
    let is_imrope = params.mode == 40;
    let is_vision = params.mode == 24;

    var i = gid.x * 2; // start index for this thread
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_src_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;

    if (i0 >= params.n_dims && !is_vision) {
        let i_src = i_src_row + i0;
        let i_dst = i_dst_row + i0;
        rotate(i_dst, i_dst + 1, f32(src0[i_src]), f32(src0[i_src + 1]));
        return;
    }

    var theta_base_mult: u32 = 0;
    var theta_scale_pwr: u32 = i0 / 2;
    if (is_mrope) {
        let sect_dims = params.sections0 + params.sections1 + params.sections2 + params.sections3;
        let sec_w = params.sections1 + params.sections0;
        let sec_e = params.sections2 + sec_w;
        let sector = (i0 / 2) % sect_dims;
        if (is_imrope) {
          if (sector % 3 == 1 && sector < 3 * params.sections1) {
              theta_base_mult = 1;
          } else if (sector % 3 == 2 && sector < 3 * params.sections2) {
              theta_base_mult = 2;
          } else if (sector % 3 == 0 && sector < 3 * params.sections0) {
              theta_base_mult = 0;
          } else {
              theta_base_mult = 3;
          }
        } else {
          if (sector >= params.sections0 && sector < sec_w) {
              theta_base_mult = 1;
              if (is_vision) {
                  theta_scale_pwr = sector - params.sections0;
              }
          } else if (sector >= sec_w && sector < sec_e) {
              theta_base_mult = 2;
              if (is_vision) {
                  theta_scale_pwr = sector - sec_w;
              }
          } else if (sector >= sec_e) {
              if (is_vision) {
                  theta_scale_pwr = sector - sec_e;
                  theta_scale_pwr = (i0 / 2) % sec_e;
              }
              theta_base_mult = 3;
          } else if (is_vision) {
              theta_scale_pwr = sector;
          }
        }
    }
    let theta_base = f32(src1[params.offset_src1 + i2 + params.ne2 * theta_base_mult]) * pow(params.theta_scale, f32(theta_scale_pwr));
    let thetas = rope_yarn(theta_base/freq_factor(i0), i0);

    let i_src = i_src_row + pair_base(i0, is_neox || is_mrope || is_vision);
    let i_dst = i_dst_row + pair_base(i0, is_neox || is_mrope || is_vision);

    let x0 = f32(src0[i_src]);
    let x1 = f32(src0[i_src + pair_offset(is_neox, is_mrope, is_vision)]);
    rotate(i_dst, i_dst + pair_offset(is_neox, is_mrope, is_vision), x0 * thetas.x - x1 * thetas.y, x0 * thetas.y + x1 * thetas.x);
})";

const char* wgsl_rope_f16_inplace = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_src2: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    n_threads: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    n_dims: u32,
    mode: u32,
    theta_scale: f32,
    attn_factor: f32,
    freq_scale: f32,
    ext_factor: f32,
    corr_dim0: f32,
    corr_dim1: f32,
    sections0: u32,
    sections1: u32,
    sections2: u32,
    sections3: u32
};

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> src1: array<i32>;

@group(0) @binding(2)
var<uniform> params: Params;

fn freq_factor(i: u32) -> f32 {
    return 1.0f;
}

fn rotate(i_dst0: u32, i_dst1: u32, out0: f32, out1: f32) {
    src0[i_dst0] = f16(out0);
    src0[i_dst1] = f16(out1);
}



fn rope_yarn_ramp(low: f32, high: f32, i: u32) -> f32 {
    let y = (f32(i / 2) - low) / max(0.001f, high - low);
    return 1.0f - min(1.0f, max(0.0f, y));
}

// returns vector of (cos_theta, sin_theta)
// TODO: check performance of instantiating once on the CPU and passed as buffer, since it's repeated per-row
fn rope_yarn(theta_extrap: f32, i: u32) -> vec2<f32> {
    var mscale = params.attn_factor;
    var theta = params.freq_scale * theta_extrap;
    if (params.ext_factor != 0.0f) {
        let ramp_mix = rope_yarn_ramp(params.corr_dim0, params.corr_dim1, i) * params.ext_factor;
        theta = theta * (1 - ramp_mix) + theta_extrap * ramp_mix;
        mscale *= 1.0f + 0.1f * log(1.0f / params.freq_scale);
    }
    return vec2<f32>(cos(theta) * mscale, sin(theta) * mscale);
}

fn pair_base(i0: u32, div_2: bool) -> u32 {
    if (div_2) {
        return i0 / 2;
    } else {
        return i0;
    }
}

fn pair_offset(is_neox: bool, is_mrope: bool, is_vision: bool) -> u32 {
    if (is_vision) {
        return params.n_dims;
    } else if (is_neox || is_mrope) {
        return params.n_dims / 2;
    } else {
        return 1;
    }
}

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    // two elements per thread
    if (gid.x >= params.n_threads) {
        return;
    }

    let is_neox = bool(params.mode & 2);
    let is_mrope = bool(params.mode & 8);
    let is_imrope = params.mode == 40;
    let is_vision = params.mode == 24;

    var i = gid.x * 2; // start index for this thread
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_src_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;

    if (i0 >= params.n_dims && !is_vision) {
        let i_src = i_src_row + i0;
        let i_dst = i_dst_row + i0;
        rotate(i_dst, i_dst + 1, f32(src0[i_src]), f32(src0[i_src + 1]));
        return;
    }

    var theta_base_mult: u32 = 0;
    var theta_scale_pwr: u32 = i0 / 2;
    if (is_mrope) {
        let sect_dims = params.sections0 + params.sections1 + params.sections2 + params.sections3;
        let sec_w = params.sections1 + params.sections0;
        let sec_e = params.sections2 + sec_w;
        let sector = (i0 / 2) % sect_dims;
        if (is_imrope) {
          if (sector % 3 == 1 && sector < 3 * params.sections1) {
              theta_base_mult = 1;
          } else if (sector % 3 == 2 && sector < 3 * params.sections2) {
              theta_base_mult = 2;
          } else if (sector % 3 == 0 && sector < 3 * params.sections0) {
              theta_base_mult = 0;
          } else {
              theta_base_mult = 3;
          }
        } else {
          if (sector >= params.sections0 && sector < sec_w) {
              theta_base_mult = 1;
              if (is_vision) {
                  theta_scale_pwr = sector - params.sections0;
              }
          } else if (sector >= sec_w && sector < sec_e) {
              theta_base_mult = 2;
              if (is_vision) {
                  theta_scale_pwr = sector - sec_w;
              }
          } else if (sector >= sec_e) {
              if (is_vision) {
                  theta_scale_pwr = sector - sec_e;
                  theta_scale_pwr = (i0 / 2) % sec_e;
              }
              theta_base_mult = 3;
          } else if (is_vision) {
              theta_scale_pwr = sector;
          }
        }
    }
    let theta_base = f32(src1[params.offset_src1 + i2 + params.ne2 * theta_base_mult]) * pow(params.theta_scale, f32(theta_scale_pwr));
    let thetas = rope_yarn(theta_base/freq_factor(i0), i0);

    let i_src = i_src_row + pair_base(i0, is_neox || is_mrope || is_vision);
    let i_dst = i_dst_row + pair_base(i0, is_neox || is_mrope || is_vision);

    let x0 = f32(src0[i_src]);
    let x1 = f32(src0[i_src + pair_offset(is_neox, is_mrope, is_vision)]);
    rotate(i_dst, i_dst + pair_offset(is_neox, is_mrope, is_vision), x0 * thetas.x - x1 * thetas.y, x0 * thetas.y + x1 * thetas.x);
})";

const char* wgsl_rope_f32_ff = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_src2: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    n_threads: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    n_dims: u32,
    mode: u32,
    theta_scale: f32,
    attn_factor: f32,
    freq_scale: f32,
    ext_factor: f32,
    corr_dim0: f32,
    corr_dim1: f32,
    sections0: u32,
    sections1: u32,
    sections2: u32,
    sections3: u32
};

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> src1: array<i32>;

@group(0) @binding(2)
var<storage, read_write> src2: array<f32>;

@group(0) @binding(3)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(4)
var<uniform> params: Params;

fn freq_factor(i: u32) -> f32 {
    return src2[params.offset_src2 + i/2];
}

fn rotate(i_dst0: u32, i_dst1: u32, out0: f32, out1: f32) {
    dst[i_dst0] = f32(out0);
    dst[i_dst1] = f32(out1);
}



fn rope_yarn_ramp(low: f32, high: f32, i: u32) -> f32 {
    let y = (f32(i / 2) - low) / max(0.001f, high - low);
    return 1.0f - min(1.0f, max(0.0f, y));
}

// returns vector of (cos_theta, sin_theta)
// TODO: check performance of instantiating once on the CPU and passed as buffer, since it's repeated per-row
fn rope_yarn(theta_extrap: f32, i: u32) -> vec2<f32> {
    var mscale = params.attn_factor;
    var theta = params.freq_scale * theta_extrap;
    if (params.ext_factor != 0.0f) {
        let ramp_mix = rope_yarn_ramp(params.corr_dim0, params.corr_dim1, i) * params.ext_factor;
        theta = theta * (1 - ramp_mix) + theta_extrap * ramp_mix;
        mscale *= 1.0f + 0.1f * log(1.0f / params.freq_scale);
    }
    return vec2<f32>(cos(theta) * mscale, sin(theta) * mscale);
}

fn pair_base(i0: u32, div_2: bool) -> u32 {
    if (div_2) {
        return i0 / 2;
    } else {
        return i0;
    }
}

fn pair_offset(is_neox: bool, is_mrope: bool, is_vision: bool) -> u32 {
    if (is_vision) {
        return params.n_dims;
    } else if (is_neox || is_mrope) {
        return params.n_dims / 2;
    } else {
        return 1;
    }
}

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    // two elements per thread
    if (gid.x >= params.n_threads) {
        return;
    }

    let is_neox = bool(params.mode & 2);
    let is_mrope = bool(params.mode & 8);
    let is_imrope = params.mode == 40;
    let is_vision = params.mode == 24;

    var i = gid.x * 2; // start index for this thread
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_src_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;

    if (i0 >= params.n_dims && !is_vision) {
        let i_src = i_src_row + i0;
        let i_dst = i_dst_row + i0;
        rotate(i_dst, i_dst + 1, f32(src0[i_src]), f32(src0[i_src + 1]));
        return;
    }

    var theta_base_mult: u32 = 0;
    var theta_scale_pwr: u32 = i0 / 2;
    if (is_mrope) {
        let sect_dims = params.sections0 + params.sections1 + params.sections2 + params.sections3;
        let sec_w = params.sections1 + params.sections0;
        let sec_e = params.sections2 + sec_w;
        let sector = (i0 / 2) % sect_dims;
        if (is_imrope) {
          if (sector % 3 == 1 && sector < 3 * params.sections1) {
              theta_base_mult = 1;
          } else if (sector % 3 == 2 && sector < 3 * params.sections2) {
              theta_base_mult = 2;
          } else if (sector % 3 == 0 && sector < 3 * params.sections0) {
              theta_base_mult = 0;
          } else {
              theta_base_mult = 3;
          }
        } else {
          if (sector >= params.sections0 && sector < sec_w) {
              theta_base_mult = 1;
              if (is_vision) {
                  theta_scale_pwr = sector - params.sections0;
              }
          } else if (sector >= sec_w && sector < sec_e) {
              theta_base_mult = 2;
              if (is_vision) {
                  theta_scale_pwr = sector - sec_w;
              }
          } else if (sector >= sec_e) {
              if (is_vision) {
                  theta_scale_pwr = sector - sec_e;
                  theta_scale_pwr = (i0 / 2) % sec_e;
              }
              theta_base_mult = 3;
          } else if (is_vision) {
              theta_scale_pwr = sector;
          }
        }
    }
    let theta_base = f32(src1[params.offset_src1 + i2 + params.ne2 * theta_base_mult]) * pow(params.theta_scale, f32(theta_scale_pwr));
    let thetas = rope_yarn(theta_base/freq_factor(i0), i0);

    let i_src = i_src_row + pair_base(i0, is_neox || is_mrope || is_vision);
    let i_dst = i_dst_row + pair_base(i0, is_neox || is_mrope || is_vision);

    let x0 = f32(src0[i_src]);
    let x1 = f32(src0[i_src + pair_offset(is_neox, is_mrope, is_vision)]);
    rotate(i_dst, i_dst + pair_offset(is_neox, is_mrope, is_vision), x0 * thetas.x - x1 * thetas.y, x0 * thetas.y + x1 * thetas.x);
})";

const char* wgsl_rope_f32_ff_inplace = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_src2: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    n_threads: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    n_dims: u32,
    mode: u32,
    theta_scale: f32,
    attn_factor: f32,
    freq_scale: f32,
    ext_factor: f32,
    corr_dim0: f32,
    corr_dim1: f32,
    sections0: u32,
    sections1: u32,
    sections2: u32,
    sections3: u32
};

@group(0) @binding(0)
var<storage, read_write> src0: array<f32>;

@group(0) @binding(1)
var<storage, read_write> src1: array<i32>;

@group(0) @binding(2)
var<storage, read_write> src2: array<f32>;

@group(0) @binding(3)
var<uniform> params: Params;

fn freq_factor(i: u32) -> f32 {
    return src2[params.offset_src2 + i/2];
}

fn rotate(i_dst0: u32, i_dst1: u32, out0: f32, out1: f32) {
    src0[i_dst0] = f32(out0);
    src0[i_dst1] = f32(out1);
}



fn rope_yarn_ramp(low: f32, high: f32, i: u32) -> f32 {
    let y = (f32(i / 2) - low) / max(0.001f, high - low);
    return 1.0f - min(1.0f, max(0.0f, y));
}

// returns vector of (cos_theta, sin_theta)
// TODO: check performance of instantiating once on the CPU and passed as buffer, since it's repeated per-row
fn rope_yarn(theta_extrap: f32, i: u32) -> vec2<f32> {
    var mscale = params.attn_factor;
    var theta = params.freq_scale * theta_extrap;
    if (params.ext_factor != 0.0f) {
        let ramp_mix = rope_yarn_ramp(params.corr_dim0, params.corr_dim1, i) * params.ext_factor;
        theta = theta * (1 - ramp_mix) + theta_extrap * ramp_mix;
        mscale *= 1.0f + 0.1f * log(1.0f / params.freq_scale);
    }
    return vec2<f32>(cos(theta) * mscale, sin(theta) * mscale);
}

fn pair_base(i0: u32, div_2: bool) -> u32 {
    if (div_2) {
        return i0 / 2;
    } else {
        return i0;
    }
}

fn pair_offset(is_neox: bool, is_mrope: bool, is_vision: bool) -> u32 {
    if (is_vision) {
        return params.n_dims;
    } else if (is_neox || is_mrope) {
        return params.n_dims / 2;
    } else {
        return 1;
    }
}

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    // two elements per thread
    if (gid.x >= params.n_threads) {
        return;
    }

    let is_neox = bool(params.mode & 2);
    let is_mrope = bool(params.mode & 8);
    let is_imrope = params.mode == 40;
    let is_vision = params.mode == 24;

    var i = gid.x * 2; // start index for this thread
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_src_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;

    if (i0 >= params.n_dims && !is_vision) {
        let i_src = i_src_row + i0;
        let i_dst = i_dst_row + i0;
        rotate(i_dst, i_dst + 1, f32(src0[i_src]), f32(src0[i_src + 1]));
        return;
    }

    var theta_base_mult: u32 = 0;
    var theta_scale_pwr: u32 = i0 / 2;
    if (is_mrope) {
        let sect_dims = params.sections0 + params.sections1 + params.sections2 + params.sections3;
        let sec_w = params.sections1 + params.sections0;
        let sec_e = params.sections2 + sec_w;
        let sector = (i0 / 2) % sect_dims;
        if (is_imrope) {
          if (sector % 3 == 1 && sector < 3 * params.sections1) {
              theta_base_mult = 1;
          } else if (sector % 3 == 2 && sector < 3 * params.sections2) {
              theta_base_mult = 2;
          } else if (sector % 3 == 0 && sector < 3 * params.sections0) {
              theta_base_mult = 0;
          } else {
              theta_base_mult = 3;
          }
        } else {
          if (sector >= params.sections0 && sector < sec_w) {
              theta_base_mult = 1;
              if (is_vision) {
                  theta_scale_pwr = sector - params.sections0;
              }
          } else if (sector >= sec_w && sector < sec_e) {
              theta_base_mult = 2;
              if (is_vision) {
                  theta_scale_pwr = sector - sec_w;
              }
          } else if (sector >= sec_e) {
              if (is_vision) {
                  theta_scale_pwr = sector - sec_e;
                  theta_scale_pwr = (i0 / 2) % sec_e;
              }
              theta_base_mult = 3;
          } else if (is_vision) {
              theta_scale_pwr = sector;
          }
        }
    }
    let theta_base = f32(src1[params.offset_src1 + i2 + params.ne2 * theta_base_mult]) * pow(params.theta_scale, f32(theta_scale_pwr));
    let thetas = rope_yarn(theta_base/freq_factor(i0), i0);

    let i_src = i_src_row + pair_base(i0, is_neox || is_mrope || is_vision);
    let i_dst = i_dst_row + pair_base(i0, is_neox || is_mrope || is_vision);

    let x0 = f32(src0[i_src]);
    let x1 = f32(src0[i_src + pair_offset(is_neox, is_mrope, is_vision)]);
    rotate(i_dst, i_dst + pair_offset(is_neox, is_mrope, is_vision), x0 * thetas.x - x1 * thetas.y, x0 * thetas.y + x1 * thetas.x);
})";

const char* wgsl_rope_f16_ff = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_src2: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    n_threads: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    n_dims: u32,
    mode: u32,
    theta_scale: f32,
    attn_factor: f32,
    freq_scale: f32,
    ext_factor: f32,
    corr_dim0: f32,
    corr_dim1: f32,
    sections0: u32,
    sections1: u32,
    sections2: u32,
    sections3: u32
};

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> src1: array<i32>;

@group(0) @binding(2)
var<storage, read_write> src2: array<f32>;

@group(0) @binding(3)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(4)
var<uniform> params: Params;

fn freq_factor(i: u32) -> f32 {
    return src2[params.offset_src2 + i/2];
}

fn rotate(i_dst0: u32, i_dst1: u32, out0: f32, out1: f32) {
    dst[i_dst0] = f16(out0);
    dst[i_dst1] = f16(out1);
}



fn rope_yarn_ramp(low: f32, high: f32, i: u32) -> f32 {
    let y = (f32(i / 2) - low) / max(0.001f, high - low);
    return 1.0f - min(1.0f, max(0.0f, y));
}

// returns vector of (cos_theta, sin_theta)
// TODO: check performance of instantiating once on the CPU and passed as buffer, since it's repeated per-row
fn rope_yarn(theta_extrap: f32, i: u32) -> vec2<f32> {
    var mscale = params.attn_factor;
    var theta = params.freq_scale * theta_extrap;
    if (params.ext_factor != 0.0f) {
        let ramp_mix = rope_yarn_ramp(params.corr_dim0, params.corr_dim1, i) * params.ext_factor;
        theta = theta * (1 - ramp_mix) + theta_extrap * ramp_mix;
        mscale *= 1.0f + 0.1f * log(1.0f / params.freq_scale);
    }
    return vec2<f32>(cos(theta) * mscale, sin(theta) * mscale);
}

fn pair_base(i0: u32, div_2: bool) -> u32 {
    if (div_2) {
        return i0 / 2;
    } else {
        return i0;
    }
}

fn pair_offset(is_neox: bool, is_mrope: bool, is_vision: bool) -> u32 {
    if (is_vision) {
        return params.n_dims;
    } else if (is_neox || is_mrope) {
        return params.n_dims / 2;
    } else {
        return 1;
    }
}

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    // two elements per thread
    if (gid.x >= params.n_threads) {
        return;
    }

    let is_neox = bool(params.mode & 2);
    let is_mrope = bool(params.mode & 8);
    let is_imrope = params.mode == 40;
    let is_vision = params.mode == 24;

    var i = gid.x * 2; // start index for this thread
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_src_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;

    if (i0 >= params.n_dims && !is_vision) {
        let i_src = i_src_row + i0;
        let i_dst = i_dst_row + i0;
        rotate(i_dst, i_dst + 1, f32(src0[i_src]), f32(src0[i_src + 1]));
        return;
    }

    var theta_base_mult: u32 = 0;
    var theta_scale_pwr: u32 = i0 / 2;
    if (is_mrope) {
        let sect_dims = params.sections0 + params.sections1 + params.sections2 + params.sections3;
        let sec_w = params.sections1 + params.sections0;
        let sec_e = params.sections2 + sec_w;
        let sector = (i0 / 2) % sect_dims;
        if (is_imrope) {
          if (sector % 3 == 1 && sector < 3 * params.sections1) {
              theta_base_mult = 1;
          } else if (sector % 3 == 2 && sector < 3 * params.sections2) {
              theta_base_mult = 2;
          } else if (sector % 3 == 0 && sector < 3 * params.sections0) {
              theta_base_mult = 0;
          } else {
              theta_base_mult = 3;
          }
        } else {
          if (sector >= params.sections0 && sector < sec_w) {
              theta_base_mult = 1;
              if (is_vision) {
                  theta_scale_pwr = sector - params.sections0;
              }
          } else if (sector >= sec_w && sector < sec_e) {
              theta_base_mult = 2;
              if (is_vision) {
                  theta_scale_pwr = sector - sec_w;
              }
          } else if (sector >= sec_e) {
              if (is_vision) {
                  theta_scale_pwr = sector - sec_e;
                  theta_scale_pwr = (i0 / 2) % sec_e;
              }
              theta_base_mult = 3;
          } else if (is_vision) {
              theta_scale_pwr = sector;
          }
        }
    }
    let theta_base = f32(src1[params.offset_src1 + i2 + params.ne2 * theta_base_mult]) * pow(params.theta_scale, f32(theta_scale_pwr));
    let thetas = rope_yarn(theta_base/freq_factor(i0), i0);

    let i_src = i_src_row + pair_base(i0, is_neox || is_mrope || is_vision);
    let i_dst = i_dst_row + pair_base(i0, is_neox || is_mrope || is_vision);

    let x0 = f32(src0[i_src]);
    let x1 = f32(src0[i_src + pair_offset(is_neox, is_mrope, is_vision)]);
    rotate(i_dst, i_dst + pair_offset(is_neox, is_mrope, is_vision), x0 * thetas.x - x1 * thetas.y, x0 * thetas.y + x1 * thetas.x);
})";

const char* wgsl_rope_f16_ff_inplace = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_src2: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    n_threads: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    n_dims: u32,
    mode: u32,
    theta_scale: f32,
    attn_factor: f32,
    freq_scale: f32,
    ext_factor: f32,
    corr_dim0: f32,
    corr_dim1: f32,
    sections0: u32,
    sections1: u32,
    sections2: u32,
    sections3: u32
};

@group(0) @binding(0)
var<storage, read_write> src0: array<f16>;

@group(0) @binding(1)
var<storage, read_write> src1: array<i32>;

@group(0) @binding(2)
var<storage, read_write> src2: array<f32>;

@group(0) @binding(3)
var<uniform> params: Params;

fn freq_factor(i: u32) -> f32 {
    return src2[params.offset_src2 + i/2];
}

fn rotate(i_dst0: u32, i_dst1: u32, out0: f32, out1: f32) {
    src0[i_dst0] = f16(out0);
    src0[i_dst1] = f16(out1);
}



fn rope_yarn_ramp(low: f32, high: f32, i: u32) -> f32 {
    let y = (f32(i / 2) - low) / max(0.001f, high - low);
    return 1.0f - min(1.0f, max(0.0f, y));
}

// returns vector of (cos_theta, sin_theta)
// TODO: check performance of instantiating once on the CPU and passed as buffer, since it's repeated per-row
fn rope_yarn(theta_extrap: f32, i: u32) -> vec2<f32> {
    var mscale = params.attn_factor;
    var theta = params.freq_scale * theta_extrap;
    if (params.ext_factor != 0.0f) {
        let ramp_mix = rope_yarn_ramp(params.corr_dim0, params.corr_dim1, i) * params.ext_factor;
        theta = theta * (1 - ramp_mix) + theta_extrap * ramp_mix;
        mscale *= 1.0f + 0.1f * log(1.0f / params.freq_scale);
    }
    return vec2<f32>(cos(theta) * mscale, sin(theta) * mscale);
}

fn pair_base(i0: u32, div_2: bool) -> u32 {
    if (div_2) {
        return i0 / 2;
    } else {
        return i0;
    }
}

fn pair_offset(is_neox: bool, is_mrope: bool, is_vision: bool) -> u32 {
    if (is_vision) {
        return params.n_dims;
    } else if (is_neox || is_mrope) {
        return params.n_dims / 2;
    } else {
        return 1;
    }
}

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    // two elements per thread
    if (gid.x >= params.n_threads) {
        return;
    }

    let is_neox = bool(params.mode & 2);
    let is_mrope = bool(params.mode & 8);
    let is_imrope = params.mode == 40;
    let is_vision = params.mode == 24;

    var i = gid.x * 2; // start index for this thread
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_src_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;

    if (i0 >= params.n_dims && !is_vision) {
        let i_src = i_src_row + i0;
        let i_dst = i_dst_row + i0;
        rotate(i_dst, i_dst + 1, f32(src0[i_src]), f32(src0[i_src + 1]));
        return;
    }

    var theta_base_mult: u32 = 0;
    var theta_scale_pwr: u32 = i0 / 2;
    if (is_mrope) {
        let sect_dims = params.sections0 + params.sections1 + params.sections2 + params.sections3;
        let sec_w = params.sections1 + params.sections0;
        let sec_e = params.sections2 + sec_w;
        let sector = (i0 / 2) % sect_dims;
        if (is_imrope) {
          if (sector % 3 == 1 && sector < 3 * params.sections1) {
              theta_base_mult = 1;
          } else if (sector % 3 == 2 && sector < 3 * params.sections2) {
              theta_base_mult = 2;
          } else if (sector % 3 == 0 && sector < 3 * params.sections0) {
              theta_base_mult = 0;
          } else {
              theta_base_mult = 3;
          }
        } else {
          if (sector >= params.sections0 && sector < sec_w) {
              theta_base_mult = 1;
              if (is_vision) {
                  theta_scale_pwr = sector - params.sections0;
              }
          } else if (sector >= sec_w && sector < sec_e) {
              theta_base_mult = 2;
              if (is_vision) {
                  theta_scale_pwr = sector - sec_w;
              }
          } else if (sector >= sec_e) {
              if (is_vision) {
                  theta_scale_pwr = sector - sec_e;
                  theta_scale_pwr = (i0 / 2) % sec_e;
              }
              theta_base_mult = 3;
          } else if (is_vision) {
              theta_scale_pwr = sector;
          }
        }
    }
    let theta_base = f32(src1[params.offset_src1 + i2 + params.ne2 * theta_base_mult]) * pow(params.theta_scale, f32(theta_scale_pwr));
    let thetas = rope_yarn(theta_base/freq_factor(i0), i0);

    let i_src = i_src_row + pair_base(i0, is_neox || is_mrope || is_vision);
    let i_dst = i_dst_row + pair_base(i0, is_neox || is_mrope || is_vision);

    let x0 = f32(src0[i_src]);
    let x1 = f32(src0[i_src + pair_offset(is_neox, is_mrope, is_vision)]);
    rotate(i_dst, i_dst + pair_offset(is_neox, is_mrope, is_vision), x0 * thetas.x - x1 * thetas.y, x0 * thetas.y + x1 * thetas.x);
})";

const char* wgsl_scale_f32 = R"(struct Params {
    offset_src: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    scale: f32,
    bias: f32
};

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;

fn store_scale(val: f32, offset: u32) {
    dst[offset] = val;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_src = params.offset_src + i3 * params.stride_src3 + i2 * params.stride_src2 + i1 * params.stride_src1 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    store_scale(src[i_src] * params.scale + params.bias, i_dst);
})";

const char* wgsl_scale_f32_inplace = R"(struct Params {
    offset_src: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    scale: f32,
    bias: f32
};

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<uniform> params: Params;

fn store_scale(val: f32, offset: u32) {
    src[offset] = val;
}



override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
        return;
    }

    var i = gid.x;
    let i3 = i / (params.ne2 * params.ne1 * params.ne0);
    i = i % (params.ne2 * params.ne1 * params.ne0);
    let i2 = i / (params.ne1 * params.ne0);
    i = i % (params.ne1 * params.ne0);
    let i1 = i / params.ne0;
    let i0 = i % params.ne0;

    let i_src = params.offset_src + i3 * params.stride_src3 + i2 * params.stride_src2 + i1 * params.stride_src1 + i0;
    let i_dst = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1 + i0;

    store_scale(src[i_src] * params.scale + params.bias, i_dst);
})";

const char* wgsl_set_rows_f16_vec = R"(enable f16;

@group(0) @binding(0)
var<storage, read_write> src: array<vec4<f32>>;

@group(0) @binding(1)
var<storage, read_write> idx: array<u32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<vec4<f16>>;

@group(0) @binding(3)
var<storage, read_write> error: atomic<u32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of src
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(4)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= (params.ne3 * params.ne2 * params.n_rows * params.ne0) / 4) {
        return;
    }

    // getting the row from gid
    let elems_per_row = params.ne0 / 4;
    var i = gid.x / elems_per_row;

    let i_src3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_src2 = i / params.n_rows;
    let i_src1 = i % params.n_rows;

    let i_idx2 = i_src3 % params.idx2;
    let i_idx1 = i_src2 % params.idx1;
    let i_idx0 = i_src1;

    let idx_high = (params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2) * 2;

    let idx_high_val = idx[idx_high];
    let idx_low_val = idx[idx_high + 1];

    if (idx_low_val != 0) {
        // Upper bits of index are not zero, output will be incorrect
        atomicStore(&error, 1);
        return;
    }

    let i_dst_row = params.offset_dst + idx_high_val * params.stride_dst1 + i_src2 * params.stride_dst2 + i_src3 * params.stride_dst3;
    let i_src_row = params.offset_src + i_src1 * params.stride_src1 + i_src2 * params.stride_src2 + i_src3 * params.stride_src3;

    let col_idx = (gid.x % elems_per_row);
    dst[i_dst_row/4 + col_idx] = vec4<f16>(src[i_src_row/4 + col_idx]);
})";

const char* wgsl_set_rows_f16 = R"(enable f16;

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> idx: array<u32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(3)
var<storage, read_write> error: atomic<u32>;

struct Params {
    offset_src: u32, // in elements
    offset_idx: u32, // in elements
    offset_dst: u32, // in elements

    // Strides (in elements)
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_idx0: u32,
    stride_idx1: u32,
    stride_idx2: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Shape of src
    ne0: u32,
    n_rows: u32,
    ne2: u32,
    ne3: u32,

    // Shape of idx
    idx1: u32,
    idx2: u32,
};

@group(0) @binding(4)
var<uniform> params: Params;

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= (params.ne3 * params.ne2 * params.n_rows * params.ne0) / 1) {
        return;
    }

    // getting the row from gid
    let elems_per_row = params.ne0 / 1;
    var i = gid.x / elems_per_row;

    let i_src3 = i / (params.ne2 * params.n_rows);

    i = i % (params.ne2 * params.n_rows);
    let i_src2 = i / params.n_rows;
    let i_src1 = i % params.n_rows;

    let i_idx2 = i_src3 % params.idx2;
    let i_idx1 = i_src2 % params.idx1;
    let i_idx0 = i_src1;

    let idx_high = (params.offset_idx + i_idx0 * params.stride_idx0 + i_idx1 * params.stride_idx1 + i_idx2 * params.stride_idx2) * 2;

    let idx_high_val = idx[idx_high];
    let idx_low_val = idx[idx_high + 1];

    if (idx_low_val != 0) {
        // Upper bits of index are not zero, output will be incorrect
        atomicStore(&error, 1);
        return;
    }

    let i_dst_row = params.offset_dst + idx_high_val * params.stride_dst1 + i_src2 * params.stride_dst2 + i_src3 * params.stride_dst3;
    let i_src_row = params.offset_src + i_src1 * params.stride_src1 + i_src2 * params.stride_src2 + i_src3 * params.stride_src3;

    let col_idx = (gid.x % elems_per_row);
    dst[i_dst_row/1 + col_idx] = f16(src[i_src_row/1 + col_idx]);
})";

const char* wgsl_soft_max_f32 = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_sinks: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of src0/dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    // shape of src1
    ne12: u32,
    ne13: u32,

    scale: f32,
    max_bias: f32,
    n_head_log2: f32,
    m0: f32,
    m1: f32,
};

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;

fn inter_value(i: u32) -> f32 {
    return dst[i];
}

fn update(i: u32, val: f32) {
    dst[i] = val;
}

fn mask_val(i: u32) -> f32 {
    return 0.0;
}

fn lower_max_bound(i2: u32) -> f32 {
    return -1e30;
}

fn add_sinks(val: f32, i2: u32, max_val: f32) -> f32 {
    return val;
}



const CACHE_SIZE: u32 = 16;

override wg_size: u32;
var<workgroup> scratch: array<f32, wg_size>;

@compute @workgroup_size(wg_size)
fn main(@builtin(workgroup_id) wid: vec3<u32>,
        @builtin(local_invocation_id) lid: vec3<u32>) {

    var i = wid.x;
    let i3 = i / (params.ne2 * params.ne1);
    i = i % (params.ne2 * params.ne1);
    let i2 = i / params.ne1;
    let i1 = i % params.ne1;
    let i_src0_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_src1_row = params.offset_src1 + (i3 % params.ne13) * params.stride_src13 + (i2 % params.ne12) * params.stride_src12 + i1 * params.stride_src11;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;
    let elems = (params.ne0 + wg_size - 1) / wg_size;

    let head = f32(i2);
    let slope = select(1, select(pow(params.m1, 2 * (head - params.n_head_log2) + 1), pow(params.m0, head + 1), head < params.n_head_log2), params.max_bias > 0);

    var cache: array<f32, CACHE_SIZE>;

    var max_val = lower_max_bound(i2);
    var col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col);
        max_val = max(max_val, val);
        if (col < CACHE_SIZE) {
            cache[col] = val;
        }
        col += wg_size;
    }

    scratch[lid.x] = max_val;
    workgroupBarrier();
    var offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] = max(scratch[lid.x], scratch[lid.x + offset]);
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_max = scratch[0];
    workgroupBarrier();

    var sum = 0.0f;
    col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = select(src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col),
                         cache[col], col < CACHE_SIZE);
        let ex = exp(val - row_max);
        sum += ex;
        if (col < CACHE_SIZE) {
            cache[col] = ex;
        } else {
            update(i_dst_row + col, ex);
        }
        col += wg_size;
    }

    scratch[lid.x] = sum;
    workgroupBarrier();
    offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] += scratch[lid.x + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_sum = add_sinks(scratch[0], i2, row_max);

    let sum_recip = 1.0 / row_sum;
    col = lid.x;
    for  (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        update(i_dst_row + col, select(inter_value(i_dst_row + col), cache[col], col < CACHE_SIZE) * sum_recip);
        col += wg_size;
    }
})";

const char* wgsl_soft_max_f32_inplace = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_sinks: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of src0/dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    // shape of src1
    ne12: u32,
    ne13: u32,

    scale: f32,
    max_bias: f32,
    n_head_log2: f32,
    m0: f32,
    m1: f32,
};

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<uniform> params: Params;

fn inter_value(i: u32) -> f32 {
    return src[i];
}

fn update(i: u32, val: f32) {
    src[i] = val;
}

fn mask_val(i: u32) -> f32 {
    return 0.0;
}

fn lower_max_bound(i2: u32) -> f32 {
    return -1e30;
}

fn add_sinks(val: f32, i2: u32, max_val: f32) -> f32 {
    return val;
}



const CACHE_SIZE: u32 = 16;

override wg_size: u32;
var<workgroup> scratch: array<f32, wg_size>;

@compute @workgroup_size(wg_size)
fn main(@builtin(workgroup_id) wid: vec3<u32>,
        @builtin(local_invocation_id) lid: vec3<u32>) {

    var i = wid.x;
    let i3 = i / (params.ne2 * params.ne1);
    i = i % (params.ne2 * params.ne1);
    let i2 = i / params.ne1;
    let i1 = i % params.ne1;
    let i_src0_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_src1_row = params.offset_src1 + (i3 % params.ne13) * params.stride_src13 + (i2 % params.ne12) * params.stride_src12 + i1 * params.stride_src11;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;
    let elems = (params.ne0 + wg_size - 1) / wg_size;

    let head = f32(i2);
    let slope = select(1, select(pow(params.m1, 2 * (head - params.n_head_log2) + 1), pow(params.m0, head + 1), head < params.n_head_log2), params.max_bias > 0);

    var cache: array<f32, CACHE_SIZE>;

    var max_val = lower_max_bound(i2);
    var col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col);
        max_val = max(max_val, val);
        if (col < CACHE_SIZE) {
            cache[col] = val;
        }
        col += wg_size;
    }

    scratch[lid.x] = max_val;
    workgroupBarrier();
    var offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] = max(scratch[lid.x], scratch[lid.x + offset]);
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_max = scratch[0];
    workgroupBarrier();

    var sum = 0.0f;
    col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = select(src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col),
                         cache[col], col < CACHE_SIZE);
        let ex = exp(val - row_max);
        sum += ex;
        if (col < CACHE_SIZE) {
            cache[col] = ex;
        } else {
            update(i_dst_row + col, ex);
        }
        col += wg_size;
    }

    scratch[lid.x] = sum;
    workgroupBarrier();
    offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] += scratch[lid.x + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_sum = add_sinks(scratch[0], i2, row_max);

    let sum_recip = 1.0 / row_sum;
    col = lid.x;
    for  (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        update(i_dst_row + col, select(inter_value(i_dst_row + col), cache[col], col < CACHE_SIZE) * sum_recip);
        col += wg_size;
    }
})";

const char* wgsl_soft_max_f32_sink = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_sinks: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of src0/dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    // shape of src1
    ne12: u32,
    ne13: u32,

    scale: f32,
    max_bias: f32,
    n_head_log2: f32,
    m0: f32,
    m1: f32,
};

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> sinks: array<f32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(3)
var<uniform> params: Params;

fn inter_value(i: u32) -> f32 {
    return dst[i];
}

fn update(i: u32, val: f32) {
    dst[i] = val;
}

fn mask_val(i: u32) -> f32 {
    return 0.0;
}

fn lower_max_bound(i2: u32) -> f32 {
    return sinks[params.offset_sinks + i2];
}

fn add_sinks(val: f32, i2: u32, max_val: f32) -> f32 {
    return val + exp(sinks[params.offset_sinks + i2] - max_val);
}



const CACHE_SIZE: u32 = 16;

override wg_size: u32;
var<workgroup> scratch: array<f32, wg_size>;

@compute @workgroup_size(wg_size)
fn main(@builtin(workgroup_id) wid: vec3<u32>,
        @builtin(local_invocation_id) lid: vec3<u32>) {

    var i = wid.x;
    let i3 = i / (params.ne2 * params.ne1);
    i = i % (params.ne2 * params.ne1);
    let i2 = i / params.ne1;
    let i1 = i % params.ne1;
    let i_src0_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_src1_row = params.offset_src1 + (i3 % params.ne13) * params.stride_src13 + (i2 % params.ne12) * params.stride_src12 + i1 * params.stride_src11;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;
    let elems = (params.ne0 + wg_size - 1) / wg_size;

    let head = f32(i2);
    let slope = select(1, select(pow(params.m1, 2 * (head - params.n_head_log2) + 1), pow(params.m0, head + 1), head < params.n_head_log2), params.max_bias > 0);

    var cache: array<f32, CACHE_SIZE>;

    var max_val = lower_max_bound(i2);
    var col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col);
        max_val = max(max_val, val);
        if (col < CACHE_SIZE) {
            cache[col] = val;
        }
        col += wg_size;
    }

    scratch[lid.x] = max_val;
    workgroupBarrier();
    var offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] = max(scratch[lid.x], scratch[lid.x + offset]);
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_max = scratch[0];
    workgroupBarrier();

    var sum = 0.0f;
    col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = select(src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col),
                         cache[col], col < CACHE_SIZE);
        let ex = exp(val - row_max);
        sum += ex;
        if (col < CACHE_SIZE) {
            cache[col] = ex;
        } else {
            update(i_dst_row + col, ex);
        }
        col += wg_size;
    }

    scratch[lid.x] = sum;
    workgroupBarrier();
    offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] += scratch[lid.x + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_sum = add_sinks(scratch[0], i2, row_max);

    let sum_recip = 1.0 / row_sum;
    col = lid.x;
    for  (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        update(i_dst_row + col, select(inter_value(i_dst_row + col), cache[col], col < CACHE_SIZE) * sum_recip);
        col += wg_size;
    }
})";

const char* wgsl_soft_max_f32_sink_inplace = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_sinks: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of src0/dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    // shape of src1
    ne12: u32,
    ne13: u32,

    scale: f32,
    max_bias: f32,
    n_head_log2: f32,
    m0: f32,
    m1: f32,
};

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> sinks: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;

fn inter_value(i: u32) -> f32 {
    return src[i];
}

fn update(i: u32, val: f32) {
    src[i] = val;
}

fn mask_val(i: u32) -> f32 {
    return 0.0;
}

fn lower_max_bound(i2: u32) -> f32 {
    return sinks[params.offset_sinks + i2];
}

fn add_sinks(val: f32, i2: u32, max_val: f32) -> f32 {
    return val + exp(sinks[params.offset_sinks + i2] - max_val);
}



const CACHE_SIZE: u32 = 16;

override wg_size: u32;
var<workgroup> scratch: array<f32, wg_size>;

@compute @workgroup_size(wg_size)
fn main(@builtin(workgroup_id) wid: vec3<u32>,
        @builtin(local_invocation_id) lid: vec3<u32>) {

    var i = wid.x;
    let i3 = i / (params.ne2 * params.ne1);
    i = i % (params.ne2 * params.ne1);
    let i2 = i / params.ne1;
    let i1 = i % params.ne1;
    let i_src0_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_src1_row = params.offset_src1 + (i3 % params.ne13) * params.stride_src13 + (i2 % params.ne12) * params.stride_src12 + i1 * params.stride_src11;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;
    let elems = (params.ne0 + wg_size - 1) / wg_size;

    let head = f32(i2);
    let slope = select(1, select(pow(params.m1, 2 * (head - params.n_head_log2) + 1), pow(params.m0, head + 1), head < params.n_head_log2), params.max_bias > 0);

    var cache: array<f32, CACHE_SIZE>;

    var max_val = lower_max_bound(i2);
    var col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col);
        max_val = max(max_val, val);
        if (col < CACHE_SIZE) {
            cache[col] = val;
        }
        col += wg_size;
    }

    scratch[lid.x] = max_val;
    workgroupBarrier();
    var offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] = max(scratch[lid.x], scratch[lid.x + offset]);
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_max = scratch[0];
    workgroupBarrier();

    var sum = 0.0f;
    col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = select(src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col),
                         cache[col], col < CACHE_SIZE);
        let ex = exp(val - row_max);
        sum += ex;
        if (col < CACHE_SIZE) {
            cache[col] = ex;
        } else {
            update(i_dst_row + col, ex);
        }
        col += wg_size;
    }

    scratch[lid.x] = sum;
    workgroupBarrier();
    offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] += scratch[lid.x + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_sum = add_sinks(scratch[0], i2, row_max);

    let sum_recip = 1.0 / row_sum;
    col = lid.x;
    for  (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        update(i_dst_row + col, select(inter_value(i_dst_row + col), cache[col], col < CACHE_SIZE) * sum_recip);
        col += wg_size;
    }
})";

const char* wgsl_soft_max_f32_mask_f32 = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_sinks: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of src0/dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    // shape of src1
    ne12: u32,
    ne13: u32,

    scale: f32,
    max_bias: f32,
    n_head_log2: f32,
    m0: f32,
    m1: f32,
};

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> mask: array<f32>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(3)
var<uniform> params: Params;

fn inter_value(i: u32) -> f32 {
    return dst[i];
}

fn update(i: u32, val: f32) {
    dst[i] = val;
}

fn mask_val(i: u32) -> f32 {
    return f32(mask[i]);
}

fn lower_max_bound(i2: u32) -> f32 {
    return -1e30;
}

fn add_sinks(val: f32, i2: u32, max_val: f32) -> f32 {
    return val;
}



const CACHE_SIZE: u32 = 16;

override wg_size: u32;
var<workgroup> scratch: array<f32, wg_size>;

@compute @workgroup_size(wg_size)
fn main(@builtin(workgroup_id) wid: vec3<u32>,
        @builtin(local_invocation_id) lid: vec3<u32>) {

    var i = wid.x;
    let i3 = i / (params.ne2 * params.ne1);
    i = i % (params.ne2 * params.ne1);
    let i2 = i / params.ne1;
    let i1 = i % params.ne1;
    let i_src0_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_src1_row = params.offset_src1 + (i3 % params.ne13) * params.stride_src13 + (i2 % params.ne12) * params.stride_src12 + i1 * params.stride_src11;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;
    let elems = (params.ne0 + wg_size - 1) / wg_size;

    let head = f32(i2);
    let slope = select(1, select(pow(params.m1, 2 * (head - params.n_head_log2) + 1), pow(params.m0, head + 1), head < params.n_head_log2), params.max_bias > 0);

    var cache: array<f32, CACHE_SIZE>;

    var max_val = lower_max_bound(i2);
    var col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col);
        max_val = max(max_val, val);
        if (col < CACHE_SIZE) {
            cache[col] = val;
        }
        col += wg_size;
    }

    scratch[lid.x] = max_val;
    workgroupBarrier();
    var offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] = max(scratch[lid.x], scratch[lid.x + offset]);
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_max = scratch[0];
    workgroupBarrier();

    var sum = 0.0f;
    col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = select(src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col),
                         cache[col], col < CACHE_SIZE);
        let ex = exp(val - row_max);
        sum += ex;
        if (col < CACHE_SIZE) {
            cache[col] = ex;
        } else {
            update(i_dst_row + col, ex);
        }
        col += wg_size;
    }

    scratch[lid.x] = sum;
    workgroupBarrier();
    offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] += scratch[lid.x + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_sum = add_sinks(scratch[0], i2, row_max);

    let sum_recip = 1.0 / row_sum;
    col = lid.x;
    for  (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        update(i_dst_row + col, select(inter_value(i_dst_row + col), cache[col], col < CACHE_SIZE) * sum_recip);
        col += wg_size;
    }
})";

const char* wgsl_soft_max_f32_mask_f32_inplace = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_sinks: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of src0/dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    // shape of src1
    ne12: u32,
    ne13: u32,

    scale: f32,
    max_bias: f32,
    n_head_log2: f32,
    m0: f32,
    m1: f32,
};

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> mask: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;

fn inter_value(i: u32) -> f32 {
    return src[i];
}

fn update(i: u32, val: f32) {
    src[i] = val;
}

fn mask_val(i: u32) -> f32 {
    return f32(mask[i]);
}

fn lower_max_bound(i2: u32) -> f32 {
    return -1e30;
}

fn add_sinks(val: f32, i2: u32, max_val: f32) -> f32 {
    return val;
}



const CACHE_SIZE: u32 = 16;

override wg_size: u32;
var<workgroup> scratch: array<f32, wg_size>;

@compute @workgroup_size(wg_size)
fn main(@builtin(workgroup_id) wid: vec3<u32>,
        @builtin(local_invocation_id) lid: vec3<u32>) {

    var i = wid.x;
    let i3 = i / (params.ne2 * params.ne1);
    i = i % (params.ne2 * params.ne1);
    let i2 = i / params.ne1;
    let i1 = i % params.ne1;
    let i_src0_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_src1_row = params.offset_src1 + (i3 % params.ne13) * params.stride_src13 + (i2 % params.ne12) * params.stride_src12 + i1 * params.stride_src11;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;
    let elems = (params.ne0 + wg_size - 1) / wg_size;

    let head = f32(i2);
    let slope = select(1, select(pow(params.m1, 2 * (head - params.n_head_log2) + 1), pow(params.m0, head + 1), head < params.n_head_log2), params.max_bias > 0);

    var cache: array<f32, CACHE_SIZE>;

    var max_val = lower_max_bound(i2);
    var col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col);
        max_val = max(max_val, val);
        if (col < CACHE_SIZE) {
            cache[col] = val;
        }
        col += wg_size;
    }

    scratch[lid.x] = max_val;
    workgroupBarrier();
    var offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] = max(scratch[lid.x], scratch[lid.x + offset]);
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_max = scratch[0];
    workgroupBarrier();

    var sum = 0.0f;
    col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = select(src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col),
                         cache[col], col < CACHE_SIZE);
        let ex = exp(val - row_max);
        sum += ex;
        if (col < CACHE_SIZE) {
            cache[col] = ex;
        } else {
            update(i_dst_row + col, ex);
        }
        col += wg_size;
    }

    scratch[lid.x] = sum;
    workgroupBarrier();
    offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] += scratch[lid.x + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_sum = add_sinks(scratch[0], i2, row_max);

    let sum_recip = 1.0 / row_sum;
    col = lid.x;
    for  (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        update(i_dst_row + col, select(inter_value(i_dst_row + col), cache[col], col < CACHE_SIZE) * sum_recip);
        col += wg_size;
    }
})";

const char* wgsl_soft_max_f32_mask_f16 = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_sinks: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of src0/dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    // shape of src1
    ne12: u32,
    ne13: u32,

    scale: f32,
    max_bias: f32,
    n_head_log2: f32,
    m0: f32,
    m1: f32,
};

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> mask: array<f16>;

@group(0) @binding(2)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(3)
var<uniform> params: Params;

fn inter_value(i: u32) -> f32 {
    return dst[i];
}

fn update(i: u32, val: f32) {
    dst[i] = val;
}

fn mask_val(i: u32) -> f32 {
    return f32(mask[i]);
}

fn lower_max_bound(i2: u32) -> f32 {
    return -1e30;
}

fn add_sinks(val: f32, i2: u32, max_val: f32) -> f32 {
    return val;
}



const CACHE_SIZE: u32 = 16;

override wg_size: u32;
var<workgroup> scratch: array<f32, wg_size>;

@compute @workgroup_size(wg_size)
fn main(@builtin(workgroup_id) wid: vec3<u32>,
        @builtin(local_invocation_id) lid: vec3<u32>) {

    var i = wid.x;
    let i3 = i / (params.ne2 * params.ne1);
    i = i % (params.ne2 * params.ne1);
    let i2 = i / params.ne1;
    let i1 = i % params.ne1;
    let i_src0_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_src1_row = params.offset_src1 + (i3 % params.ne13) * params.stride_src13 + (i2 % params.ne12) * params.stride_src12 + i1 * params.stride_src11;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;
    let elems = (params.ne0 + wg_size - 1) / wg_size;

    let head = f32(i2);
    let slope = select(1, select(pow(params.m1, 2 * (head - params.n_head_log2) + 1), pow(params.m0, head + 1), head < params.n_head_log2), params.max_bias > 0);

    var cache: array<f32, CACHE_SIZE>;

    var max_val = lower_max_bound(i2);
    var col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col);
        max_val = max(max_val, val);
        if (col < CACHE_SIZE) {
            cache[col] = val;
        }
        col += wg_size;
    }

    scratch[lid.x] = max_val;
    workgroupBarrier();
    var offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] = max(scratch[lid.x], scratch[lid.x + offset]);
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_max = scratch[0];
    workgroupBarrier();

    var sum = 0.0f;
    col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = select(src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col),
                         cache[col], col < CACHE_SIZE);
        let ex = exp(val - row_max);
        sum += ex;
        if (col < CACHE_SIZE) {
            cache[col] = ex;
        } else {
            update(i_dst_row + col, ex);
        }
        col += wg_size;
    }

    scratch[lid.x] = sum;
    workgroupBarrier();
    offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] += scratch[lid.x + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_sum = add_sinks(scratch[0], i2, row_max);

    let sum_recip = 1.0 / row_sum;
    col = lid.x;
    for  (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        update(i_dst_row + col, select(inter_value(i_dst_row + col), cache[col], col < CACHE_SIZE) * sum_recip);
        col += wg_size;
    }
})";

const char* wgsl_soft_max_f32_mask_f16_inplace = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_sinks: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of src0/dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    // shape of src1
    ne12: u32,
    ne13: u32,

    scale: f32,
    max_bias: f32,
    n_head_log2: f32,
    m0: f32,
    m1: f32,
};

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> mask: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;

fn inter_value(i: u32) -> f32 {
    return src[i];
}

fn update(i: u32, val: f32) {
    src[i] = val;
}

fn mask_val(i: u32) -> f32 {
    return f32(mask[i]);
}

fn lower_max_bound(i2: u32) -> f32 {
    return -1e30;
}

fn add_sinks(val: f32, i2: u32, max_val: f32) -> f32 {
    return val;
}



const CACHE_SIZE: u32 = 16;

override wg_size: u32;
var<workgroup> scratch: array<f32, wg_size>;

@compute @workgroup_size(wg_size)
fn main(@builtin(workgroup_id) wid: vec3<u32>,
        @builtin(local_invocation_id) lid: vec3<u32>) {

    var i = wid.x;
    let i3 = i / (params.ne2 * params.ne1);
    i = i % (params.ne2 * params.ne1);
    let i2 = i / params.ne1;
    let i1 = i % params.ne1;
    let i_src0_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_src1_row = params.offset_src1 + (i3 % params.ne13) * params.stride_src13 + (i2 % params.ne12) * params.stride_src12 + i1 * params.stride_src11;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;
    let elems = (params.ne0 + wg_size - 1) / wg_size;

    let head = f32(i2);
    let slope = select(1, select(pow(params.m1, 2 * (head - params.n_head_log2) + 1), pow(params.m0, head + 1), head < params.n_head_log2), params.max_bias > 0);

    var cache: array<f32, CACHE_SIZE>;

    var max_val = lower_max_bound(i2);
    var col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col);
        max_val = max(max_val, val);
        if (col < CACHE_SIZE) {
            cache[col] = val;
        }
        col += wg_size;
    }

    scratch[lid.x] = max_val;
    workgroupBarrier();
    var offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] = max(scratch[lid.x], scratch[lid.x + offset]);
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_max = scratch[0];
    workgroupBarrier();

    var sum = 0.0f;
    col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = select(src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col),
                         cache[col], col < CACHE_SIZE);
        let ex = exp(val - row_max);
        sum += ex;
        if (col < CACHE_SIZE) {
            cache[col] = ex;
        } else {
            update(i_dst_row + col, ex);
        }
        col += wg_size;
    }

    scratch[lid.x] = sum;
    workgroupBarrier();
    offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] += scratch[lid.x + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_sum = add_sinks(scratch[0], i2, row_max);

    let sum_recip = 1.0 / row_sum;
    col = lid.x;
    for  (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        update(i_dst_row + col, select(inter_value(i_dst_row + col), cache[col], col < CACHE_SIZE) * sum_recip);
        col += wg_size;
    }
})";

const char* wgsl_soft_max_f32_mask_f32_sink = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_sinks: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of src0/dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    // shape of src1
    ne12: u32,
    ne13: u32,

    scale: f32,
    max_bias: f32,
    n_head_log2: f32,
    m0: f32,
    m1: f32,
};

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> mask: array<f32>;

@group(0) @binding(2)
var<storage, read_write> sinks: array<f32>;

@group(0) @binding(3)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(4)
var<uniform> params: Params;

fn inter_value(i: u32) -> f32 {
    return dst[i];
}

fn update(i: u32, val: f32) {
    dst[i] = val;
}

fn mask_val(i: u32) -> f32 {
    return f32(mask[i]);
}

fn lower_max_bound(i2: u32) -> f32 {
    return sinks[params.offset_sinks + i2];
}

fn add_sinks(val: f32, i2: u32, max_val: f32) -> f32 {
    return val + exp(sinks[params.offset_sinks + i2] - max_val);
}



const CACHE_SIZE: u32 = 16;

override wg_size: u32;
var<workgroup> scratch: array<f32, wg_size>;

@compute @workgroup_size(wg_size)
fn main(@builtin(workgroup_id) wid: vec3<u32>,
        @builtin(local_invocation_id) lid: vec3<u32>) {

    var i = wid.x;
    let i3 = i / (params.ne2 * params.ne1);
    i = i % (params.ne2 * params.ne1);
    let i2 = i / params.ne1;
    let i1 = i % params.ne1;
    let i_src0_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_src1_row = params.offset_src1 + (i3 % params.ne13) * params.stride_src13 + (i2 % params.ne12) * params.stride_src12 + i1 * params.stride_src11;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;
    let elems = (params.ne0 + wg_size - 1) / wg_size;

    let head = f32(i2);
    let slope = select(1, select(pow(params.m1, 2 * (head - params.n_head_log2) + 1), pow(params.m0, head + 1), head < params.n_head_log2), params.max_bias > 0);

    var cache: array<f32, CACHE_SIZE>;

    var max_val = lower_max_bound(i2);
    var col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col);
        max_val = max(max_val, val);
        if (col < CACHE_SIZE) {
            cache[col] = val;
        }
        col += wg_size;
    }

    scratch[lid.x] = max_val;
    workgroupBarrier();
    var offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] = max(scratch[lid.x], scratch[lid.x + offset]);
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_max = scratch[0];
    workgroupBarrier();

    var sum = 0.0f;
    col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = select(src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col),
                         cache[col], col < CACHE_SIZE);
        let ex = exp(val - row_max);
        sum += ex;
        if (col < CACHE_SIZE) {
            cache[col] = ex;
        } else {
            update(i_dst_row + col, ex);
        }
        col += wg_size;
    }

    scratch[lid.x] = sum;
    workgroupBarrier();
    offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] += scratch[lid.x + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_sum = add_sinks(scratch[0], i2, row_max);

    let sum_recip = 1.0 / row_sum;
    col = lid.x;
    for  (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        update(i_dst_row + col, select(inter_value(i_dst_row + col), cache[col], col < CACHE_SIZE) * sum_recip);
        col += wg_size;
    }
})";

const char* wgsl_soft_max_f32_mask_f32_sink_inplace = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_sinks: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of src0/dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    // shape of src1
    ne12: u32,
    ne13: u32,

    scale: f32,
    max_bias: f32,
    n_head_log2: f32,
    m0: f32,
    m1: f32,
};

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> mask: array<f32>;

@group(0) @binding(2)
var<storage, read_write> sinks: array<f32>;

@group(0) @binding(3)
var<uniform> params: Params;

fn inter_value(i: u32) -> f32 {
    return src[i];
}

fn update(i: u32, val: f32) {
    src[i] = val;
}

fn mask_val(i: u32) -> f32 {
    return f32(mask[i]);
}

fn lower_max_bound(i2: u32) -> f32 {
    return sinks[params.offset_sinks + i2];
}

fn add_sinks(val: f32, i2: u32, max_val: f32) -> f32 {
    return val + exp(sinks[params.offset_sinks + i2] - max_val);
}



const CACHE_SIZE: u32 = 16;

override wg_size: u32;
var<workgroup> scratch: array<f32, wg_size>;

@compute @workgroup_size(wg_size)
fn main(@builtin(workgroup_id) wid: vec3<u32>,
        @builtin(local_invocation_id) lid: vec3<u32>) {

    var i = wid.x;
    let i3 = i / (params.ne2 * params.ne1);
    i = i % (params.ne2 * params.ne1);
    let i2 = i / params.ne1;
    let i1 = i % params.ne1;
    let i_src0_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_src1_row = params.offset_src1 + (i3 % params.ne13) * params.stride_src13 + (i2 % params.ne12) * params.stride_src12 + i1 * params.stride_src11;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;
    let elems = (params.ne0 + wg_size - 1) / wg_size;

    let head = f32(i2);
    let slope = select(1, select(pow(params.m1, 2 * (head - params.n_head_log2) + 1), pow(params.m0, head + 1), head < params.n_head_log2), params.max_bias > 0);

    var cache: array<f32, CACHE_SIZE>;

    var max_val = lower_max_bound(i2);
    var col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col);
        max_val = max(max_val, val);
        if (col < CACHE_SIZE) {
            cache[col] = val;
        }
        col += wg_size;
    }

    scratch[lid.x] = max_val;
    workgroupBarrier();
    var offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] = max(scratch[lid.x], scratch[lid.x + offset]);
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_max = scratch[0];
    workgroupBarrier();

    var sum = 0.0f;
    col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = select(src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col),
                         cache[col], col < CACHE_SIZE);
        let ex = exp(val - row_max);
        sum += ex;
        if (col < CACHE_SIZE) {
            cache[col] = ex;
        } else {
            update(i_dst_row + col, ex);
        }
        col += wg_size;
    }

    scratch[lid.x] = sum;
    workgroupBarrier();
    offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] += scratch[lid.x + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_sum = add_sinks(scratch[0], i2, row_max);

    let sum_recip = 1.0 / row_sum;
    col = lid.x;
    for  (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        update(i_dst_row + col, select(inter_value(i_dst_row + col), cache[col], col < CACHE_SIZE) * sum_recip);
        col += wg_size;
    }
})";

const char* wgsl_soft_max_f32_mask_f16_sink = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_sinks: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of src0/dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    // shape of src1
    ne12: u32,
    ne13: u32,

    scale: f32,
    max_bias: f32,
    n_head_log2: f32,
    m0: f32,
    m1: f32,
};

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> mask: array<f16>;

@group(0) @binding(2)
var<storage, read_write> sinks: array<f32>;

@group(0) @binding(3)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(4)
var<uniform> params: Params;

fn inter_value(i: u32) -> f32 {
    return dst[i];
}

fn update(i: u32, val: f32) {
    dst[i] = val;
}

fn mask_val(i: u32) -> f32 {
    return f32(mask[i]);
}

fn lower_max_bound(i2: u32) -> f32 {
    return sinks[params.offset_sinks + i2];
}

fn add_sinks(val: f32, i2: u32, max_val: f32) -> f32 {
    return val + exp(sinks[params.offset_sinks + i2] - max_val);
}



const CACHE_SIZE: u32 = 16;

override wg_size: u32;
var<workgroup> scratch: array<f32, wg_size>;

@compute @workgroup_size(wg_size)
fn main(@builtin(workgroup_id) wid: vec3<u32>,
        @builtin(local_invocation_id) lid: vec3<u32>) {

    var i = wid.x;
    let i3 = i / (params.ne2 * params.ne1);
    i = i % (params.ne2 * params.ne1);
    let i2 = i / params.ne1;
    let i1 = i % params.ne1;
    let i_src0_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_src1_row = params.offset_src1 + (i3 % params.ne13) * params.stride_src13 + (i2 % params.ne12) * params.stride_src12 + i1 * params.stride_src11;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;
    let elems = (params.ne0 + wg_size - 1) / wg_size;

    let head = f32(i2);
    let slope = select(1, select(pow(params.m1, 2 * (head - params.n_head_log2) + 1), pow(params.m0, head + 1), head < params.n_head_log2), params.max_bias > 0);

    var cache: array<f32, CACHE_SIZE>;

    var max_val = lower_max_bound(i2);
    var col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col);
        max_val = max(max_val, val);
        if (col < CACHE_SIZE) {
            cache[col] = val;
        }
        col += wg_size;
    }

    scratch[lid.x] = max_val;
    workgroupBarrier();
    var offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] = max(scratch[lid.x], scratch[lid.x + offset]);
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_max = scratch[0];
    workgroupBarrier();

    var sum = 0.0f;
    col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = select(src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col),
                         cache[col], col < CACHE_SIZE);
        let ex = exp(val - row_max);
        sum += ex;
        if (col < CACHE_SIZE) {
            cache[col] = ex;
        } else {
            update(i_dst_row + col, ex);
        }
        col += wg_size;
    }

    scratch[lid.x] = sum;
    workgroupBarrier();
    offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] += scratch[lid.x + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_sum = add_sinks(scratch[0], i2, row_max);

    let sum_recip = 1.0 / row_sum;
    col = lid.x;
    for  (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        update(i_dst_row + col, select(inter_value(i_dst_row + col), cache[col], col < CACHE_SIZE) * sum_recip);
        col += wg_size;
    }
})";

const char* wgsl_soft_max_f32_mask_f16_sink_inplace = R"(enable f16;

struct Params {
    offset_src0: u32,
    offset_src1: u32,
    offset_sinks: u32,
    offset_dst: u32,

    // Strides (in elements)
    stride_src01: u32,
    stride_src02: u32,
    stride_src03: u32,

    stride_src11: u32,
    stride_src12: u32,
    stride_src13: u32,

    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // shape of src0/dst
    ne: u32,
    ne0: u32,
    ne1: u32,
    ne2: u32,

    // shape of src1
    ne12: u32,
    ne13: u32,

    scale: f32,
    max_bias: f32,
    n_head_log2: f32,
    m0: f32,
    m1: f32,
};

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> mask: array<f16>;

@group(0) @binding(2)
var<storage, read_write> sinks: array<f32>;

@group(0) @binding(3)
var<uniform> params: Params;

fn inter_value(i: u32) -> f32 {
    return src[i];
}

fn update(i: u32, val: f32) {
    src[i] = val;
}

fn mask_val(i: u32) -> f32 {
    return f32(mask[i]);
}

fn lower_max_bound(i2: u32) -> f32 {
    return sinks[params.offset_sinks + i2];
}

fn add_sinks(val: f32, i2: u32, max_val: f32) -> f32 {
    return val + exp(sinks[params.offset_sinks + i2] - max_val);
}



const CACHE_SIZE: u32 = 16;

override wg_size: u32;
var<workgroup> scratch: array<f32, wg_size>;

@compute @workgroup_size(wg_size)
fn main(@builtin(workgroup_id) wid: vec3<u32>,
        @builtin(local_invocation_id) lid: vec3<u32>) {

    var i = wid.x;
    let i3 = i / (params.ne2 * params.ne1);
    i = i % (params.ne2 * params.ne1);
    let i2 = i / params.ne1;
    let i1 = i % params.ne1;
    let i_src0_row = params.offset_src0 + i3 * params.stride_src03 + i2 * params.stride_src02 + i1 * params.stride_src01;
    let i_src1_row = params.offset_src1 + (i3 % params.ne13) * params.stride_src13 + (i2 % params.ne12) * params.stride_src12 + i1 * params.stride_src11;
    let i_dst_row = params.offset_dst + i3 * params.stride_dst3 + i2 * params.stride_dst2 + i1 * params.stride_dst1;
    let elems = (params.ne0 + wg_size - 1) / wg_size;

    let head = f32(i2);
    let slope = select(1, select(pow(params.m1, 2 * (head - params.n_head_log2) + 1), pow(params.m0, head + 1), head < params.n_head_log2), params.max_bias > 0);

    var cache: array<f32, CACHE_SIZE>;

    var max_val = lower_max_bound(i2);
    var col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col);
        max_val = max(max_val, val);
        if (col < CACHE_SIZE) {
            cache[col] = val;
        }
        col += wg_size;
    }

    scratch[lid.x] = max_val;
    workgroupBarrier();
    var offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] = max(scratch[lid.x], scratch[lid.x + offset]);
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_max = scratch[0];
    workgroupBarrier();

    var sum = 0.0f;
    col = lid.x;
    for (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        let val = select(src[i_src0_row + col] * params.scale + slope * mask_val(i_src1_row + col),
                         cache[col], col < CACHE_SIZE);
        let ex = exp(val - row_max);
        sum += ex;
        if (col < CACHE_SIZE) {
            cache[col] = ex;
        } else {
            update(i_dst_row + col, ex);
        }
        col += wg_size;
    }

    scratch[lid.x] = sum;
    workgroupBarrier();
    offset = wg_size / 2;
    while (offset > 0) {
        if (lid.x < offset) {
            scratch[lid.x] += scratch[lid.x + offset];
        }
        offset = offset / 2;
        workgroupBarrier();
    }
    let row_sum = add_sinks(scratch[0], i2, row_max);

    let sum_recip = 1.0 / row_sum;
    col = lid.x;
    for  (var j: u32 = 0; j < elems; j++) {
        if (col >= params.ne0) {
            break;
        }
        update(i_dst_row + col, select(inter_value(i_dst_row + col), cache[col], col < CACHE_SIZE) * sum_recip);
        col += wg_size;
    }
})";

const char* wgsl_abs_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = abs(src[src_i]);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_abs_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = abs(src[src_i]);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_abs_inplace_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = abs(src[src_i]);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_abs_inplace_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = abs(src[src_i]);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_sgn_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = select(f32(select(0.0, -1.0, src[src_i] < 0.0)), f32(1.0), src[src_i] > 0.0);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_sgn_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = select(f16(select(0.0, -1.0, src[src_i] < 0.0)), f16(1.0), src[src_i] > 0.0);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_sgn_inplace_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = select(f32(select(0.0, -1.0, src[src_i] < 0.0)), f32(1.0), src[src_i] > 0.0);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_sgn_inplace_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = select(f16(select(0.0, -1.0, src[src_i] < 0.0)), f16(1.0), src[src_i] > 0.0);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_neg_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = -src[src_i];
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_neg_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = -src[src_i];
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_neg_inplace_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = -src[src_i];
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_neg_inplace_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = -src[src_i];
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_step_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = f32(select(0.0, 1.0, src[src_i] > 0.0));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_step_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = f16(select(0.0, 1.0, src[src_i] > 0.0));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_step_inplace_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = f32(select(0.0, 1.0, src[src_i] > 0.0));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_step_inplace_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = f16(select(0.0, 1.0, src[src_i] > 0.0));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_tanh_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = tanh(clamp(src[src_i], -9.010913, 9.010913)); // Regarding tanh() domain restrictions in wgsl https://github.com/gpuweb/gpuweb/issues/4458
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_tanh_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = tanh(clamp(src[src_i], -9.010913, 9.010913)); // Regarding tanh() domain restrictions in wgsl https://github.com/gpuweb/gpuweb/issues/4458
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_tanh_inplace_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = tanh(clamp(src[src_i], -9.010913, 9.010913)); // Regarding tanh() domain restrictions in wgsl https://github.com/gpuweb/gpuweb/issues/4458
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_tanh_inplace_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = tanh(clamp(src[src_i], -9.010913, 9.010913)); // Regarding tanh() domain restrictions in wgsl https://github.com/gpuweb/gpuweb/issues/4458
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_elu_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = select(exp(src[src_i]) - 1.0, src[src_i], src[src_i] > 0.0);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_elu_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = select(exp(src[src_i]) - 1.0, src[src_i], src[src_i] > 0.0);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_elu_inplace_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = select(exp(src[src_i]) - 1.0, src[src_i], src[src_i] > 0.0);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_elu_inplace_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = select(exp(src[src_i]) - 1.0, src[src_i], src[src_i] > 0.0);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_relu_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = select(0.0, src[src_i], src[src_i] > 0.0);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_relu_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = select(0.0, src[src_i], src[src_i] > 0.0);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_relu_inplace_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = select(0.0, src[src_i], src[src_i] > 0.0);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_relu_inplace_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = select(0.0, src[src_i], src[src_i] > 0.0);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_sigmoid_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = 1.0 / (1.0 + exp(-src[src_i]));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_sigmoid_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = 1.0 / (1.0 + exp(-src[src_i]));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_sigmoid_inplace_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = 1.0 / (1.0 + exp(-src[src_i]));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_sigmoid_inplace_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = 1.0 / (1.0 + exp(-src[src_i]));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_silu_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = src[src_i] / (1.0 + exp(-src[src_i]));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_silu_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = src[src_i] / (1.0 + exp(-src[src_i]));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_silu_inplace_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = src[src_i] / (1.0 + exp(-src[src_i]));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_silu_inplace_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = src[src_i] / (1.0 + exp(-src[src_i]));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_exp_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = exp(src[src_i]);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_exp_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = exp(src[src_i]);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_exp_inplace_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = exp(src[src_i]);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_exp_inplace_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = exp(src[src_i]);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_hardsigmoid_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = min(1.0, max(0.0, (src[src_i] + 3.0) / 6.0));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_hardsigmoid_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = min(1.0, max(0.0, (src[src_i] + 3.0) / 6.0));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_hardsigmoid_inplace_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = min(1.0, max(0.0, (src[src_i] + 3.0) / 6.0));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_hardsigmoid_inplace_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = min(1.0, max(0.0, (src[src_i] + 3.0) / 6.0));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_hardswish_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = src[src_i] * min(1.0, max(0.0, (src[src_i] + 3.0) / 6.0));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_hardswish_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = src[src_i] * min(1.0, max(0.0, (src[src_i] + 3.0) / 6.0));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_hardswish_inplace_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = src[src_i] * min(1.0, max(0.0, (src[src_i] + 3.0) / 6.0));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_hardswish_inplace_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = src[src_i] * min(1.0, max(0.0, (src[src_i] + 3.0) / 6.0));
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_gelu_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = 0.5 * src[src_i] * (1.0 + tanh(clamp(sqrt(2.0 / 3.14159265) * (src[src_i] + 0.044715 * pow(src[src_i], 3.0)), -9.010913, 9.010913))); // Regarding tanh() domain restrictions in wgsl https://github.com/gpuweb/gpuweb/issues/4458
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_gelu_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = 0.5 * src[src_i] * (1.0 + tanh(clamp(sqrt(2.0 / 3.14159265) * (src[src_i] + 0.044715 * pow(src[src_i], 3.0)), -9.010913, 9.010913))); // Regarding tanh() domain restrictions in wgsl https://github.com/gpuweb/gpuweb/issues/4458
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_gelu_inplace_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = 0.5 * src[src_i] * (1.0 + tanh(clamp(sqrt(2.0 / 3.14159265) * (src[src_i] + 0.044715 * pow(src[src_i], 3.0)), -9.010913, 9.010913))); // Regarding tanh() domain restrictions in wgsl https://github.com/gpuweb/gpuweb/issues/4458
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_gelu_inplace_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = 0.5 * src[src_i] * (1.0 + tanh(clamp(sqrt(2.0 / 3.14159265) * (src[src_i] + 0.044715 * pow(src[src_i], 3.0)), -9.010913, 9.010913))); // Regarding tanh() domain restrictions in wgsl https://github.com/gpuweb/gpuweb/issues/4458
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_gelu_quick_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = src[src_i] * 0.5 * (1.0 + tanh(clamp(0.79788456 * (src[src_i] + 0.044715 * src[src_i] * src[src_i] * src[src_i]), -9.010913, 9.010913))); // Regarding tanh() domain restrictions in wgsl https://github.com/gpuweb/gpuweb/issues/4458
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_gelu_quick_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = src[src_i] * 0.5 * (1.0 + tanh(clamp(0.79788456 * (src[src_i] + 0.044715 * src[src_i] * src[src_i] * src[src_i]), -9.010913, 9.010913))); // Regarding tanh() domain restrictions in wgsl https://github.com/gpuweb/gpuweb/issues/4458
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_gelu_quick_inplace_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = src[src_i] * 0.5 * (1.0 + tanh(clamp(0.79788456 * (src[src_i] + 0.044715 * src[src_i] * src[src_i] * src[src_i]), -9.010913, 9.010913))); // Regarding tanh() domain restrictions in wgsl https://github.com/gpuweb/gpuweb/issues/4458
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_gelu_quick_inplace_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = src[src_i] * 0.5 * (1.0 + tanh(clamp(0.79788456 * (src[src_i] + 0.044715 * src[src_i] * src[src_i] * src[src_i]), -9.010913, 9.010913))); // Regarding tanh() domain restrictions in wgsl https://github.com/gpuweb/gpuweb/issues/4458
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_xielu_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = select(((exp(min(src[src_i], f32(params.eps))) - 1.0) - src[src_i]) * f32(params.alpha_n) + f32(params.beta) * src[src_i], f32(params.alpha_p) * src[src_i] * src[src_i] + f32(params.beta) * src[src_i], src[src_i] > 0.0);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    alpha_n: f32, alpha_p: f32, beta: f32, eps: f32
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_xielu_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = select(((exp(min(src[src_i], f16(params.eps))) - 1.0) - src[src_i]) * f16(params.alpha_n) + f16(params.beta) * src[src_i], f16(params.alpha_p) * src[src_i] * src[src_i] + f16(params.beta) * src[src_i], src[src_i] > 0.0);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    alpha_n: f32, alpha_p: f32, beta: f32, eps: f32
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_xielu_inplace_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = select(((exp(min(src[src_i], f32(params.eps))) - 1.0) - src[src_i]) * f32(params.alpha_n) + f32(params.beta) * src[src_i], f32(params.alpha_p) * src[src_i] * src[src_i] + f32(params.beta) * src[src_i], src[src_i] > 0.0);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    alpha_n: f32, alpha_p: f32, beta: f32, eps: f32
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_xielu_inplace_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = select(((exp(min(src[src_i], f16(params.eps))) - 1.0) - src[src_i]) * f16(params.alpha_n) + f16(params.beta) * src[src_i], f16(params.alpha_p) * src[src_i] * src[src_i] + f16(params.beta) * src[src_i], src[src_i] > 0.0);
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    alpha_n: f32, alpha_p: f32, beta: f32, eps: f32
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_gelu_erf_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = 0.5 * src[src_i] * (1.0 + tanh(clamp(0.79788456 * (src[src_i] + 0.044715 * src[src_i] * src[src_i] * src[src_i]), -9.010913, 9.010913))); // Regarding tanh() domain restrictions in wgsl https://github.com/gpuweb/gpuweb/issues/4458
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f32>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_gelu_erf_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    dst[dst_i] = 0.5 * src[src_i] * (1.0 + tanh(clamp(0.79788456 * (src[src_i] + 0.044715 * src[src_i] * src[src_i] * src[src_i]), -9.010913, 9.010913))); // Regarding tanh() domain restrictions in wgsl https://github.com/gpuweb/gpuweb/issues/4458
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<storage, read_write> dst: array<f16>;

@group(0) @binding(2)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_gelu_erf_inplace_f32 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = 0.5 * src[src_i] * (1.0 + tanh(clamp(0.79788456 * (src[src_i] + 0.044715 * src[src_i] * src[src_i] * src[src_i]), -9.010913, 9.010913))); // Regarding tanh() domain restrictions in wgsl https://github.com/gpuweb/gpuweb/issues/4458
}

@group(0) @binding(0)
var<storage, read_write> src: array<f32>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

const char* wgsl_gelu_erf_inplace_f16 = R"(enable f16;

fn update(dst_i: u32, src_i: u32) {
    src[dst_i] = 0.5 * src[src_i] * (1.0 + tanh(clamp(0.79788456 * (src[src_i] + 0.044715 * src[src_i] * src[src_i] * src[src_i]), -9.010913, 9.010913))); // Regarding tanh() domain restrictions in wgsl https://github.com/gpuweb/gpuweb/issues/4458
}

@group(0) @binding(0)
var<storage, read_write> src: array<f16>;

@group(0) @binding(1)
var<uniform> params: Params;



struct Params {
    ne: u32,            // total number of elements
    offset_src: u32,    // in elements
    offset_dst: u32,    // in elements

    // Strides (in elements) — may be permuted
    stride_src0: u32,
    stride_src1: u32,
    stride_src2: u32,
    stride_src3: u32,

    stride_dst0: u32,
    stride_dst1: u32,
    stride_dst2: u32,
    stride_dst3: u32,

    // Logical shapes
    src_ne0: u32,
    src_ne1: u32,
    src_ne2: u32,

    dst_ne0: u32,
    dst_ne1: u32,
    dst_ne2: u32,

    
};

override wg_size: u32;
@compute @workgroup_size(wg_size)
fn main(@builtin(global_invocation_id) gid: vec3<u32>) {
    if (gid.x >= params.ne) {
      return;
    }

    var i = gid.x;
    let i3 = i / (params.src_ne2 * params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne2 * params.src_ne1 * params.src_ne0);
    let i2 = i / (params.src_ne1 * params.src_ne0);
    i = i % (params.src_ne1 * params.src_ne0);
    let i1 = i / params.src_ne0;
    let i0 = i % params.src_ne0;

    var j = gid.x;
    let j3 = j / (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne2 * params.dst_ne1 * params.dst_ne0);
    let j2 = j / (params.dst_ne1 * params.dst_ne0);
    j = j % (params.dst_ne1 * params.dst_ne0);
    let j1 = j / params.dst_ne0;
    let j0 = j % params.dst_ne0;

    let src_idx = i0 * params.stride_src0 + i1 * params.stride_src1 +
                  i2 * params.stride_src2 + i3 * params.stride_src3;

    let dst_idx = j0 * params.stride_dst0 + j1 * params.stride_dst1 +
                  j2 * params.stride_dst2 + j3 * params.stride_dst3;


    update(params.offset_dst + dst_idx, params.offset_src + src_idx);
})";

