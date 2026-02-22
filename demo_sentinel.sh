#!/bin/bash

# --- Sentinel-Trace v3.0: Detection Demo Script ---
# Simulates the Behavioral Detection loop.
# --------------------------------------------------

CYAN='\033[0;36m'
GREEN='\033[0;32m'
NC='\033[0m'

echo -e "${CYAN}--- Starting Sentinel-Trace Correlation Engine ---${NC}"

# 1. Compile (if needed)
mkdir -p build && cd build
cmake .. && make
cd ..

# 2. Deploy eBPF Policies
echo -e "[*] Injecting Tetragon TracingPolicies..."
sudo tetra tracingpolicy add policies/v3-correlation/03-network-observability.yaml

# 3. Launch Sentinel-Trace
echo -e "${GREEN}[✔] Sentinel-Trace is live. Monitoring for Reverse Shells...${NC}"
./build/SentinelTrace