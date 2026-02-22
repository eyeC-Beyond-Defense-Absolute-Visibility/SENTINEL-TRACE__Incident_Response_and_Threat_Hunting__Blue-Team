/**
 * AlertManager.cpp
 * Objective: Communication with the Enforcement Plane.
 */

void AlertManager::dispatchAlert(const std::string& ruleId) {
    std::cout << "[Alert] Dispatching Signal to Sovereign-Shield..." << std::endl;

    // Professional Method: Integration via CLI or Shared Message Queue
    std::string cmd = "./SovereignShield --isolate target-node Linux";
    
    // In a real eyeC environment, this would be a secure API call or 
    // a shared signal file that Sovereign-Shield monitors.
    system(cmd.c_str()); 
}