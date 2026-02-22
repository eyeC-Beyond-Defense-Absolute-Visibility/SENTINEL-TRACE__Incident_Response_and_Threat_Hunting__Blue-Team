#ifndef ALERT_MANAGER_HPP
#define ALERT_MANAGER_HPP

#include <string>

/**
 * The Bridge: Orchestrates response by communicating with Sovereign-Shield.
 */
class AlertManager {
public:
    static void dispatchAlert(const std::string& ruleId, const std::string& target);
    static void logDetection(const std::string& details);
};

#endif