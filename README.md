# raylib-2D-pixel-game
```text
MyRPG_Game/
├── .gitignore             # File cấu hình Git (bỏ qua folder build)
├── CMakeLists.txt         # File cấu hình build chính
├── assets/                # Chứa toàn bộ tài nguyên game
│   ├── graphics/          # Sprites, tilesets, UI images
│   │   ├── characters/
│   │   └── tilesets/
│   ├── sounds/            # Âm thanh (sfx) và Nhạc nền (bgm)
│   ├── fonts/             # Font chữ pixel
│   └── maps/              # File bản đồ (xuất ra từ Tiled/LDtk)
│
└── src/                   # Mã nguồn C++
    ├── main.cpp           # Điểm khởi chạy (Entry point)
    ├── core/              # Các class nền tảng (Window, Camera, Config)
    ├── entities/          # Các đối tượng game (Player, Enemy, NPC)
    ├── scenes/            # Quản lý màn chơi (Menu, Gameplay, GameOver)
    └── utils/             # Các hàm tiện ích (Toán học, hằng số)
```
