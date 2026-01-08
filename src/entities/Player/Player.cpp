#include "Player.h"

Player::Player() : Entity(10.0f, 10.0f, 250.0f, 200.0f) {
    ManaPoint = 100.0f;
    Stamina = 100.0f;
    currMana = ManaPoint;
    currStamina = Stamina;
    position = { 64.0f, 64.0f };

    // --- LOAD TEXTURE ---
    texture = LoadTexture("assets/graphics/character/Knight_Walking_16Frame.png");

    // --- TÍNH TOÁN FRAME ---
    // Ảnh có 4 cột và 4 hàng.
    // frameRec.width = Tổng chiều rộng / 4
    // frameRec.height = Tổng chiều cao / 4
    frameRec = {0.0f, 0.0f, (float)texture.width / 4, (float)texture.height / 4};

    currFrame = 0;
    frameCounter = 0.0f;
}

Player::~Player(){
    UnloadTexture(texture);
}

void Player::Draw() {
    DrawTextureRec(texture, frameRec, position, WHITE);

    // Hitbox
    // DrawRectangleLines(position.x, position.y, frameRec.width, frameRec.height, GREEN);
}

void Player::DrawUI(int x, int y) {
    // Cấu hình giao diện
    float maxWidth = 200.0f;
    float maxHeight = 20.0f;
    float barGap = 5.0f;

    // 1. Thanh HP
    float percenHP = currHealth / HealthPoint;
    DrawRectangle(x, y, maxWidth, maxHeight, Fade(DARKGRAY, 0.5f)); // Nền xám
    DrawRectangle(x, y, maxWidth * percenHP, maxHeight, RED); // Máu đỏ
    DrawRectangleLines(x, y, maxWidth, maxHeight, BLACK); // Viền đen
    const char* hpText = TextFormat("%d/%d", (int)currHealth, (int)HealthPoint);
    int textWidthHP = MeasureText(hpText, 20);
    // Công thức căn giữa: Tọa độ X + (thanh - chữ) / 2
    DrawText(hpText, x + (maxWidth - textWidthHP) / 2, y + 1, 20, WHITE);

    // 2. Thanh Mana
    float percenMP = currMana / ManaPoint;
    float yMana = y + barGap + maxHeight;
    DrawRectangle(x, yMana, maxWidth, maxHeight, Fade(DARKGRAY, 0.5f)); // Nền xám
    DrawRectangle(x, yMana, maxWidth * percenMP, maxHeight, DARKBLUE); // Mana xanh
    DrawRectangleLines(x, yMana, maxWidth, maxHeight, BLACK);
    const char* mpText = TextFormat("%d/%d", (int)currMana, (int)ManaPoint);
    int textWidthMP = MeasureText(mpText, 20);
    DrawText(mpText, x + (maxWidth - textWidthMP) / 2, yMana + 1, 20, WHITE);

    // 3. Thanh Stamina
    float percenSP = currStamina / Stamina;
    float ySP = yMana + barGap + maxHeight;
    DrawRectangle(x, ySP, maxWidth, maxHeight, Fade(DARKGRAY, 0.5f)); // Nền xám
    DrawRectangle(x, ySP, maxWidth * percenSP, maxHeight, DARKGREEN); // Stamina xanh
    DrawRectangleLines(x, ySP, maxWidth, maxHeight, BLACK);
    const char* spText = TextFormat("%d/%d", (int)currStamina, (int)Stamina);
    int textWidthSP = MeasureText(spText, 20);
    DrawText(spText, x + (maxWidth - textWidthSP) / 2, ySP + 1, 20, WHITE);
}

void Player::Move(Vector2 direc, float currSpeed) {
    Entity::Move(direc, currSpeed);

    bool isMoving = (direc.x != 0 || direc.y != 0);
    if (isMoving) {
        // A. XÁC ĐỊNH HÀNG (ROW) DỰA VÀO HƯỚNG
        // 0=Xuống, 1=Phải, 2=Trái, 3=Lên
        if (direc.y > 0) frameRec.y = 0 * frameRec.height; // Hàng 1
        else if (direc.y < 0) frameRec.y = 3 * frameRec.height; // Hàng 4

        if (direc.x > 0) frameRec.y = 2 * frameRec.height;      // Hàng 2
        else if (direc.x < 0) frameRec.y = 1 * frameRec.height; // Hàng 3

        frameCounter += GetFrameTime();
        if (frameCounter >= 0.15f) { // 0.15 giây đổi hình 1 lần
            frameCounter = 0.0f;
            currFrame++;

            if (currFrame > 3) currFrame = 0; // Quay về khung đầu tiên nếu đã đi hết 4 frame
            frameRec.x = (float)currFrame * frameRec.width; // Dịch khung hình sang phải
        }
    }
    else { // Trường hợp đứng yên
        currFrame = 0;
        frameRec.x = 0;
    }
}

void Player::UpdateHealth(int point) {
    HealthPoint += point;
}

void Player::UpdateStamina(float point) {
    Stamina += point;
    if(Stamina > 200.0f) {
        Stamina = 200.0f;
    }
}

void Player::ReduceStamina(float point) {
    currStamina -= point;
    if(currStamina < 0){
        currStamina = 0;
    }
}