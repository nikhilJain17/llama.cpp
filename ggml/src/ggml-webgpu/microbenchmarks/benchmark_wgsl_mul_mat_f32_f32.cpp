#include <webgpu/webgpu_cpp.h>
#include <iostream>

/**
 * g++ -std=c++17 ggml/src/ggml-webgpu/microbenchmarks/benchmark_wgsl_mul_mat_f32_f32.cpp \
    -I$HOME/dawn-install/include \
    $HOME/dawn-install/lib/libwebgpu_dawn.a \
    -framework Metal -framework CoreGraphics -framework Foundation -framework IOKit -framework IOSurface -framework QuartzCore \
    -o benchmark
 */

int main() {
    std::cout << "Dawn Hello World\n";
    
    // Create instance
    wgpu::InstanceDescriptor instanceDesc{};
    wgpu::Instance instance = wgpu::CreateInstance(&instanceDesc);
    
    if (!instance) {
        std::cerr << "Failed to create WebGPU instance\n";
        return 1;
    }
    
    std::cout << "Successfully created WebGPU instance!\n";
    
    // Request adapter
    std::cout << "Requesting adapter...\n";
    wgpu::RequestAdapterOptions adapterOpts{};
    
    wgpu::Adapter adapter;
    bool adapterReceived = false;
    
    instance.RequestAdapter(
        &adapterOpts, 
        wgpu::CallbackMode::AllowSpontaneous,
        [&](wgpu::RequestAdapterStatus status, wgpu::Adapter adp, wgpu::StringView message) {
            if (status == wgpu::RequestAdapterStatus::Success) {
                adapter = std::move(adp);
                adapterReceived = true;
                std::cout << "Got adapter!\n";
            } else {
                std::cerr << "Failed to get adapter\n";
            }
        }
    );
    
    // Process events until we get the adapter
    while (!adapterReceived) {
        instance.ProcessEvents();
    }
    
    if (!adapter) {
        std::cerr << "No adapter available\n";
        return 1;
    }
    
    // Get adapter info
    wgpu::AdapterInfo info{};
    adapter.GetInfo(&info);
    std::cout << "Adapter: " << std::string(info.device) << "\n";
    std::cout << "Vendor: " << std::string(info.vendor) << "\n";
    std::cout << "Backend: " << static_cast<int>(info.backendType) << "\n";
    
    // Request device
    std::cout << "Requesting device...\n";
    wgpu::DeviceDescriptor deviceDesc{};
    
    wgpu::Device device;
    bool deviceReceived = false;
    
    adapter.RequestDevice(
        &deviceDesc,
        wgpu::CallbackMode::AllowSpontaneous,
        [&](wgpu::RequestDeviceStatus status, wgpu::Device dev, wgpu::StringView message) {
            if (status == wgpu::RequestDeviceStatus::Success) {
                device = std::move(dev);
                deviceReceived = true;
                std::cout << "Got device!\n";
            } else {
                std::cerr << "Failed to get device\n";
            }
        }
    );
    
    // Process events until we get the device
    while (!deviceReceived) {
        instance.ProcessEvents();
    }
    
    if (!device) {
        std::cerr << "No device available\n";
        return 1;
    }
    
    wgpu::Queue queue = device.GetQueue();
    std::cout << "Got queue!\n";
    
    std::cout << "\nDawn initialized successfully!\n";
    std::cout << "All systems ready.\n";
    
    return 0;
}