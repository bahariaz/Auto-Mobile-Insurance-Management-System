🚗 Automobile Insurance Management System
A console-based C++ application for managing an automobile insurance company's core operations. Built on a clean 3-layer architecture with file-based persistence — no DBMS required.

📋 Features

Customer & Vehicle Management — Register customers, add vehicles, issue and renew policies
Claims Processing — File claims, assign surveyors, track claim status
Inspection & Survey — Conduct inspections, submit reports with findings and damage estimates
Manager Dashboard — Approve/reject claims, generate reports (new customers, pending claims, inspection history, claim history)
Workshop Integration — Route approved repairs only to registered workshops
Role-Based Access — Separate menus and permissions for Salesmen, Surveyors, and Managers


🏗️ Architecture
┌─────────────────────────────────────┐
│        Presentation Layer           │  ← Text/menu-driven UI
├─────────────────────────────────────┤
│         Business Layer              │  ← C++ classes (Customer, Vehicle,
│                                     │    Policy, Claim, Inspection, Staff,
│                                     │    Workshop, Manager, RepairOrder)
├─────────────────────────────────────┤
│        Persistence Layer            │  ← FileHandler classes (CSV/binary)
│                                     │    called only by the business layer
└─────────────────────────────────────┘

🗂️ Project Structure
InsuranceSystem/
├── src/
│   ├── presentation/       # Menu-driven UI
│   ├── business/           # Core domain classes
│   │   ├── Customer.cpp / .h
│   │   ├── Vehicle.cpp / .h
│   │   ├── InsurancePolicy.cpp / .h
│   │   ├── Claim.cpp / .h
│   │   ├── Inspection.cpp / .h
│   │   ├── Staff.cpp / .h
│   │   ├── Salesman.cpp / .h
│   │   ├── Surveyor.cpp / .h
│   │   ├── Manager.cpp / .h
│   │   ├── Workshop.cpp / .h
│   │   └── RepairOrder.cpp / .h
│   └── persistence/        # File I/O handlers
│       ├── FileHandler.h
│       ├── CustomerFileHandler.cpp / .h
│       ├── ClaimFileHandler.cpp / .h
│       └── ...
├── data/                   # Flat files (CSV)
│   ├── customers.csv
│   ├── vehicles.csv
│   ├── policies.csv
│   ├── claims.csv
│   ├── inspections.csv
│   └── workshops.csv
├── diagrams/
│   ├── uml.drawio.txt
│   └── usecase.drawio.txt
└── README.md

👥 Actors & Roles
RolePermissionsCustomerRegister, add vehicle, file claim, track claim statusSalesmanRegister customers, issue/renew policiesSurveyorView assigned claims, conduct inspections, submit reportsManagerApprove/reject claims, generate all reports, manage workshopsWorkshopUpdate repair status on assigned repair ordersSystem AdminRegister workshops, manage system access

⚙️ Tech Stack

Language: C++ (C++17)
Storage: File-based persistence (CSV flat files)
UI: Text/menu-driven console interface
No external dependencies or DBMS


🚀 Getting Started
Prerequisites

g++ compiler with C++17 support
Linux / Windows (MinGW) / macOS

Build & Run
bash# Clone the repository
git clone https://github.com/your-username/insurance-management-system.git
cd insurance-management-system

# Compile
g++ -std=c++17 -o insurance src/**/*.cpp

# Run
./insurance

📊 Diagrams
UML Class Diagram and Use Case Diagram are included in the /diagrams folder as Draw.io files. Import them at draw.io via File → Import From → Device.

📄 License
This project was developed as coursework for Software Design and Analysis at FAST-NU.
