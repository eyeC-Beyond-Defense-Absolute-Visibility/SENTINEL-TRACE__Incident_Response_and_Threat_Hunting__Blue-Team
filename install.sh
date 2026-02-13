#!/bin/bash

# Sentinel Trace - Automated Installation Script
# This script deploys the systemd service and detection policies.

echo "🚀 Starting Sentinel Trace installation..."

# 1. Create necessary directories
sudo mkdir -p /etc/tetragon/tracingpolicies/

# 2. Copy the Tracing Policies
echo "🛡️ Deploying eBPF Tracing Policies..."
sudo cp policies/*.yaml /etc/tetragon/tracingpolicies/

# 3. Deploy the Systemd Service
echo "⚙️ Configuring systemd service..."
sudo cp service/tetragon.service /etc/systemd/system/

# 4. Reload and Start
echo "🔄 Reloading systemd and starting Sentinel Trace..."
sudo systemctl daemon-reload
sudo systemctl enable --now tetragon

echo "✅ Installation complete! Sentinel Trace is now protecting your system."
echo "🔍 Use 'sudo tetra getevents' to monitor kernel signals."