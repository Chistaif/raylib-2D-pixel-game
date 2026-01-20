```text
MyRPG_Game/
├── .vscode/                # Cấu hình debug/run (tasks.json, launch.json)
├── build/                  # Thư mục chứa file thực thi (.exe) sau khi compile
├── lib/                    # Thư viện bên thứ 3 (Raylib, cJSON, ENet...)
├── resources/              # Toàn bộ tài sản (Assets) của game
│   ├── characters/         # Sprite nhân vật (Player, NPC, Monsters)
│   ├── tilesets/           # Ảnh gạch nền, cây cối, môi trường
│   ├── maps/               # Dữ liệu bản đồ (.txt, .json, .csv)
│   ├── dialogues/          # Kịch bản hội thoại (.json)
│   └── sounds/             # Nhạc nền (BGM) và hiệu ứng âm thanh (SFX)
├── src/                    # Mã nguồn (Source Code)
│   ├── core/               # Các thành phần cốt lõi của Game Engine
│   │   ├── Game.h          # Class quản lý vòng lặp game chính
│   │   ├── Game.cpp
│   │   └── Config.h        # Định nghĩa hằng số (SCREEN_WIDTH, FPS...)
│   ├── entities/           # Các thực thể trong game (GameObject)
│   │   ├── Player.h        # Logic và struct của nhân vật chính
│   │   ├── Player.cpp
│   │   ├── Enemy.h         # Logic của quái vật
│   │   └── Enemy.cpp
│   ├── world/              # Quản lý bản đồ và môi trường
│   │   ├── Map.h           # Load map, vẽ các layer
│   │   ├── Map.cpp
│   │   └── Tile.h          # Định nghĩa struct Tile
│   └── utils/              # Các công cụ hỗ trợ (Helper functions)
│       ├── Animation.h     # Xử lý cắt frame, timer cho animation
│       └── ResourceManager.h # Quản lý load/unload texture để tránh leak RAM
├── main.cpp                # Điểm khởi chạy chương trình (Entry point)
├── CMakeLists.txt          # (Hoặc Makefile) Cấu hình build dự án
└── .gitignore              # Các file git cần bỏ qua (build/, .vscode/...)
