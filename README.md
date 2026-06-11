🚗 Automobile Insurance Management System
A console-based C++ application for managing an automobile insurance company's core operations. Built on a clean 3-layer architecture with file-based persistence — no DBMS required.

📋 Features

Customer & Vehicle Management — Register customers, add vehicles, issue and renew policies
Claims Processing — File claims, assign surveyors, track claim status
Inspection & Survey — Conduct inspections, submit reports with findings and damage estimates
Manager Dashboard — Approve/reject claims, generate reports (new customers, pending claims, inspection history, claim history)
Workshop Integration — Route approved repairs only to registered workshops
Role-Based Access — Separate menus and permissions for Salesmen, Surveyors, and Managers


🏗️ Architecture<br>
├─ Presentation Layer ← Text/menu-driven UI<br>
├─ Business Layer ← C++ classes (Customer, Vehicle, Policy, Claim, Inspection, Staff, Workshop, Manager, RepairOrder) <br>
└─ Persistence Layer ← FileHandler classes (CSV/binary) called only by the business layer <br>


🗂️ Project Structure
InsuranceSystem/
<br>
├── src/<br>
│   ├── presentation/       # Menu-driven UI<br>
│   ├── business/           # Core domain classes<br>
│   │   ├── Customer.cpp / .h<br>
│   │   ├── Vehicle.cpp / .h<br>
│   │   ├── InsurancePolicy.cpp / .h<br>
│   │   ├── Claim.cpp / .h<br>
│   │   ├── Inspection.cpp / .h<br>
│   │   ├── Staff.cpp / .h<br>
│   │   ├── Salesman.cpp / .h<br>
│   │   ├── Surveyor.cpp / .h<br>
│   │   ├── Manager.cpp / .h<br>
│   │   ├── Workshop.cpp / .h<br>
│   │   └── RepairOrder.cpp / .h<br>
│   └── persistence/        # File I/O handlers<br>
│       ├── FileHandler.h<br>
│       ├── CustomerFileHandler.cpp / .h<br>
│       ├── ClaimFileHandler.cpp / .h<br>
│       └── ...<br>
├── data/                   # Flat files (CSV)<br>
│   ├── customers.csv<br>
│   ├── vehicles.csv<br>
│   ├── policies.csv<br>
│   ├── claims.csv<br>
│   ├── inspections.csv<br>
│   └── workshops.csv<br>
## diagrams/
│   ├── uml.drawio.txt<br>
│   └── usecase.drawio.txt<br>
└── README.md<br>

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
