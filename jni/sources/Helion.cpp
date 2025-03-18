#include <Helion.h>
#include <dobby.h>
#include <iostream>
#include <vector>

struct HelionHook {
    void* address;
    void* replace_function;
    void* original_function;
};

std::vector<HelionHook> hooks;

void* (*_)(void*);

void Helion::AddHook(void* address, void* replace_function, void** original_function) {
    for (auto& hook : hooks) {
        if (hook.address == address) {
            *original_function = hook.original_function = hook.replace_function;
            hook.replace_function = replace_function;
            DobbyHook(address, replace_function, (void**) &_);
            return;
        }
    }
    DobbyHook(address, replace_function, (void**) &*original_function);
    HelionHook hook = {address, replace_function, &*original_function};
    hooks.push_back(hook);
}
