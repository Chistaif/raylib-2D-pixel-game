# MyRPG_Game

Dự án game nhập vai 2D (RPG) sử dụng C++ và thư viện Raylib.

## Cấu Trúc Thư Mục

```text
MyRPG_Game/
├── .gitignore             # Cấu hình file/thư mục Git cần bỏ qua
├── CMakeLists.txt         # Cấu hình build dự án với CMake
├── UML.uxf                # Sơ đồ thiết kế hệ thống (UML)
├── assets/                # Tài nguyên game (Ảnh, Nhạc, Font...)
│
└── src/                   # Mã nguồn chính (Source Code)
    ├── main.cpp           # Điểm khởi chạy chương trình (Entry point)
    │
    ├── core/              # Các thành phần cốt lõi quản lý Game
    │   ├── Game.h         # Quản lý vòng lặp game, input, update, draw
    │   └── Game.cpp
    │
    └── entities/          # Hệ thống thực thể (Entities System)
        ├── Entity.h       # Class cha cơ sở (Base class) cho mọi vật thể
        ├── Entity.cpp
        │
        ├── Player/        # Module nhân vật chính
        │   ├── Player.h
        │   └── Player.cpp
        │
        └── Enemy/         # Module kẻ địch
            ├── Enemy.h    # Class cơ sở cho quái vật (AI, Thanh máu...)
            ├── Enemy.cpp
            │
            └── Dummy/     # Quái vật bù nhìn (Dùng để test)
                ├── Dummy.h
                └── Dummy.cpp
