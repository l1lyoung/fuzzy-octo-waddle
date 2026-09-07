# ue-blueprint-to-cpp 🎮⚡

> **An industrial-grade Unreal Engine 5 Agent Skill that converts Blueprint prototypes into production-grade, compile-safe C++ components.**

## 🎯 The Core Problem
Technical designers and gameplay programmers love prototyping in Blueprints. However, porting Blueprints to C++ is fraught with pitfalls:
- **UHT Syntax Traps**: Forgotten macros, wrong specifiers, missing generated headers.
- **Garbage Collection Crashes**: Dangling raw pointers without proper UPROPERTY() roots.
- **Build.cs Headaches**: Unknown module dependencies causing linker errors.

## 🏗 Architecture
1. Phase 1: Architecture & State Extraction
2. Phase 2: Header Spec & GC Guard
3. Phase 3: Defensive C++ Implementation
4. Phase 4: Build.cs Dependency & Blueprint Reparenting Plan

## 🚀 Showcase: Health & Damage Component
Check xamples/01_health_component/ for an end-to-end example.