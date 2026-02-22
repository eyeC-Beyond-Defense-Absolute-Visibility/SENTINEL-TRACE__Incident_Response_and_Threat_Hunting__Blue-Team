/**
 * @file        main.cpp
 * @project     Sentinel-Trace (v2.0: Correlation Engine)
 * @author      O’djuma Badolo (eyeC)
 * @version     3.0
 * @description The Behavioral Intelligence Engine of the eyeC Trilogy.
 * Ingests Tetragon eBPF telemetry, correlates process/network signals,
 * and maps detections to MITRE ATT&CK techniques.
 * * "Signals are cheap. Decisions are earned."
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "include/IngestionEngine.hpp"
#include "include/ReasoningEngine.hpp"
#include "include/AlertManager.hpp"

// Utility for Fancy Terminal Styling
namespace UI {
    void printHeader() {
        std::cout << "\033[1;34m" << "================================================================" << "\033[0m" << std::endl;
        std::cout << "\033[1;36m" << "   🛰️  SENTINEL-TRACE | THE eyeC PROJECT | v2.0 Correlation    " << "\033[0m" << std::endl;
        std::cout << "   [ eBPF Behavioral IDS & SIEM - Correlation Engine ]          " << std::endl;
        std::cout << "\033[1;34m" << "================================================================" << "\033[0m" << std::endl;
    }

    void logStatus(std::string msg) {
        std::cout << "\033[0;32m[+]\033[0m " << msg << std::endl;
    }
}

int main(int argc, char* argv[]) {
    UI::printHeader();

    // 1. Initialize Core Components
    UI::logStatus("Initializing eBPF Ingestion Engine...");
    IngestionEngine ingestor;

    UI::logStatus("Loading MITRE ATT&CK Correlation Rules...");
    ReasoningEngine brain;
    if (!brain.loadRules("config/detection_rules.json")) {
        std::cerr << "\033[0;31m[!] Critical: Failed to load detection logic.\033[0m" << std::endl;
        return 1;
    }

    UI::logStatus("Sentinel-Trace is now monitoring the Kernel stream.");
    UI::logStatus("Status: ACTIVE - Awaiting telemetry...");

    // 2. The Real-Time Correlation Loop (Simulation of v2 logic)
    // In a real scenario, this would be a thread reading from Tetragon's JSON output
    bool isRunning = true;
    while (isRunning) {
        
        // Placeholder for Event Capture
        // Event event = ingestor.nextEvent(); 

        /* * LOGIC EXAMPLE (The Reverse Shell Chain):
         * 1. Process Signal:  nginx (UID 33) -> /bin/bash
         * 2. Network Signal: /bin/bash -> outbound port 4444
         * 3. Sentinel Reasoner: Links #1 and #2 -> High Fidelity Alert
         */

        // If high-confidence threat detected:
        // brain.correlate(event);
        
        // break; // For demo purposes we exit, but real SIEM stays alive
        isRunning = false; 
    }

    // 3. Final Integration Step (The Sovereign Bridge)
    std::cout << "\n\033[1;35m[Correlation Alert]\033[0m MITRE T1059.004 Detected: Unauthorized Outbound Shell." << std::endl;
    UI::logStatus("Sentinel Decision: SUSPICIOUS.");
    UI::logStatus("Action: Dispatching containment request to Sovereign-Shield...");

    std::cout << "\033[1;34m" << "================================================================" << "\033[0m" << std::endl;
    UI::logStatus("Sentinel-Trace: Correlation Phase Completed Cleanly.");

    return 0;
}