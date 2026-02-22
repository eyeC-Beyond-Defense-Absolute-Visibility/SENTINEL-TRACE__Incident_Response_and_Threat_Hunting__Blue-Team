/**
 * ReasoningEngine.cpp
 * Logic: Correlating isolated signals into behavioral chains.
 */

#include "ReasoningEngine.hpp"
#include <iostream>

bool ReasoningEngine::loadRules(const std::string& path) {
    // Logic to parse detection_rules.json using nlohmann/json
    std::cout << "[Brain] Loading Behavioral Signatures..." << std::endl;
    return true; 
}

/**
 * The Correlation Logic
 * Checks if a new event completes a known malicious pattern.
 */
void ReasoningEngine::correlate(const Event& newEvent) {
    // 1. Check if event matches a rule signal (e.g., Nginx spawning shell)
    // 2. Look in the 'State Cache' for recent related signals (e.g., outbound connection)
    // 3. If the chain is complete: Trigger Alert
    
    std::cout << "[Brain] Correlating: " << newEvent.type << " from UID " << newEvent.uid << std::endl;
    
    if (isReverseShellChain(newEvent)) {
        std::cout << "\033[1;31m[!] ALARM: Behavioral Match Found (MITRE T1059.004)\033[0m" << std::endl;
        dispatchAlert("ST-001");
    }
}