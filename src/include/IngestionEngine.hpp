#ifndef INGESTION_ENGINE_HPP
#define INGESTION_ENGINE_HPP

#include <string>

/**
 * Handles the raw data stream from the eBPF kernel hooks (Tetragon).
 */
class IngestionEngine {
public:
    void startStream(); // Launches the 'tetra getevents' pipe
private:
    void processRawEvent(const std::string& rawJson);
};

#endif