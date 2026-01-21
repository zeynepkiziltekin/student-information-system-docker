# User Manual  
Student Information System (Dockerized)

## 1. Introduction
This document describes how to use the Student Information System application.
The system is a command-line based C++ application that runs inside Docker
containers together with a PostgreSQL database.

The application allows basic student management operations through a CLI menu.

---

## 2. System Requirements
Before running the application, make sure the following requirements are met:

- macOS / Linux / Windows
- Docker Desktop installed and running
- Docker Compose support enabled
- Git (optional, for cloning the repository)

---

## 3. Starting the System (Docker)
Follow these steps to start the system using Docker Compose:

1. Open a terminal
2. Navigate to the project root directory
3. Run the following command:

```bash
docker compose up -d
