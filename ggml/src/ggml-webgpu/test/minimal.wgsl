@group(0) @binding(0)
var<storage, read_write> data : array<u32>;

@compute @workgroup_size(64)
fn main(@builtin(global_invocation_id) gid : vec3<u32>) {
    // Do something trivial to exercise the pipeline:
    if (gid.x < arrayLength(&data)) {
        data[gid.x] += 1u;
    }
}
