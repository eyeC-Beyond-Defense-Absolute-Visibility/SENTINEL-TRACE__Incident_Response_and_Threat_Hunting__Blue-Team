![C++](https://img.shields.io/badge/C++-Correlation_Engine-00599C?logo=c%2B%2B&logoColor=white) ![eBPF](https://img.shields.io/badge/Linux-eBPF-000000?logo=linux&logoColor=white) ![Tetragon](https://img.shields.io/badge/Tetragon-Tracing-00b3a4?logo=cilium&logoColor=white) ![JSON](https://img.shields.io/badge/Rules-JSON_Decoupled-black?logo=json&logoColor=white)

![Correlation](https://img.shields.io/badge/Logic-Stateful_Correlation-blueviolet) ![MITRE ATT&CK](https://img.shields.io/badge/MITRE_ATT%26CK-T1059.004-ff6600) ![Decision](https://img.shields.io/badge/Decision-High--Fidelity_Alert-red)

![Sovereign Bridge](https://img.shields.io/badge/Bridge-SOAR_Integration-green) ![Triplets](https://img.shields.io/badge/Project-eyeC_Triplets-blueviolet)

# 🛰️ Sentinel-Trace v2.0: Correlation Engine

> *"Signals are cheap. Decisions are earned."*

Sentinel-Trace is the "Thinking Brain" of the eyeC ecosystem. While most security tools alert on isolated events, Sentinel-Trace performs **Stateful Behavioral Correlation**. It ingests low-level kernel telemetry via eBPF to reconstruct attack chains in real-time.

---

## 🧠 Detection Philosophy: The Behavioral Chain

Sentinel-Trace moves beyond simple pattern matching. It focuses on **Contextual Reasoning**:

1. **The Signal:** An isolated event (e.g., a shell starting).
2. **The Context:** Who started it? (Nginx) What is its history? (Web user).
3. **The Correlation:** Did that shell then initiate a network connection?
4. **The Decision:** High-fidelity alert mapped to MITRE T1059.004.

---

## 🏗️ Technical Architecture

The engine is built in C++ for high-performance JSON parsing and real-time kernel event processing.

* **Ingestion Engine:** Pipes live JSON streams from Tetragon eBPF hooks.
* **Reasoning Engine:** Evaluates events against `detection_rules.json` using a state-tracking logic.
* **Alert Manager:** The "Sovereign Bridge" that dispatches containment commands to Sovereign-Shield.

---

## 🧪 V2.0 Case Study: The Reverse Shell Chain

Sentinel-Trace identifies the following sequence as a single high-priority threat:

1. `process_exec`: Parent `nginx` (UID 33) spawns `/bin/bash`.
2. `socket_connect`: `/bin/bash` connects to external IP on port `4444`.
3. **Outcome:** Immediate trigger of the Sovereign-Shield isolation protocol.

---

## 🚀 Quick Start

### 1. Prerequisites

* Tetragon (Cilium eBPF Runtime Security)
* nlohmann/json (C++ JSON library)
* CMake & G++

### 2. Build & Run
```bash
# Build the engine
mkdir build && cd build
cmake .. && make

# Launch with the demo script
sudo ./demo_sentinel.sh
```

### 3. Adding Rules

Detection logic is decoupled from the code. Add new behaviors in `config/detection_rules.json`:
```json
{
  "rule_id": "ST-001",
  "name": "Reverse Shell Detection",
  "mitre_id": "T1059.004",
  "action": "SOVEREIGN_ISOLATE"
}
```

---

## 🗺️ Roadmap

* [x] v1.0 Genesis: Single-signal eBPF detection.
* [x] V2.0 Correlation: C++ engine linking process and network signals.
* [ ] V2.0 Sovereign Bridge: Fully automated API-based SOAR integration.
* [ ] v3.1 Predictive Analysis: Basic anomaly detection via frequency analysis.

---

## 👤 Author

**O'djuma Badolo**  
Web Developer | Cybersecurity graduate | DevSecOps Enthusiast  
> *"Building secure systems by thinking like the storm."*
