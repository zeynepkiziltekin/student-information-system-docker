# Contributing Guide

Thank you for your interest in contributing to the Student Information System project.

This project follows a structured workflow to ensure code quality and collaboration.

---

## Branching Strategy

- `main`  
  Contains stable and reviewed code only.

- `develop`  
  Active development branch. All features are merged here before release.

- `feature/*`  
  New features must be developed in separate feature branches.

---

## Contribution Rules

- ❌ Direct pushes to `main` and `develop` branches are **not allowed**.
- ✅ All changes must be submitted via **Pull Requests**.
- ✅ Each Pull Request must:
  - Be linked to a related Issue
  - Include a clear description of the changes
  - Be reviewed and approved by at least one team member

---

## Pull Request Process

1. Create a new feature branch:
   ```bash
   git checkout -b feature/your-feature-name
