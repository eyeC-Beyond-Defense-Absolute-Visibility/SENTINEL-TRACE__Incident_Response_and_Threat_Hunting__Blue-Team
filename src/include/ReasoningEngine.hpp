#ifndef REASONING_ENGINE_HPP
#define REASONING_ENGINE_HPP

#include <string>
#include <vector>

/**
 * The Brain: Matches incoming signals against behavioral patterns (MITRE).
 */
class ReasoningEngine {
public:
    bool loadRules(const std::string& path);
    void correlate(const std::string& eventData);
private:
    bool isReverseShellChain(const std::string& data);
};

#endif