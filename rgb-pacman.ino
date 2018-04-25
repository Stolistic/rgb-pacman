int Pin_Data = 2;
int Pin_Latch = 4;
int Pin_Clock = 5;

int joyYPin = A5;
int joyXPin = A4;
int joyBPin = 8;

#define DEBUG 0

class Glyph
{
  public:
    const byte *pixels;
};

#define TOTAL_GLYPHS 37

// Font Definitions
const byte F00[] = {0x3c, 0x66, 0x6e, 0x7e, 0x76, 0x66, 0x3c, 0x00};
const byte F01[] = {0x18, 0x38, 0x78, 0x18, 0x18, 0x18, 0x18, 0x00};
const byte F02[] = {0x3c, 0x66, 0x06, 0x0c, 0x18, 0x30, 0x7e, 0x00};
const byte F03[] = {0x3c, 0x66, 0x06, 0x1c, 0x06, 0x66, 0x3c, 0x00};
const byte F04[] = {0x1c, 0x3c, 0x6c, 0xcc, 0xfe, 0x0c, 0x0c, 0x00};
const byte F05[] = {0x7e, 0x60, 0x7c, 0x06, 0x06, 0x66, 0x3c, 0x00};
const byte F06[] = {0x1c, 0x30, 0x60, 0x7c, 0x66, 0x66, 0x3c, 0x00};
const byte F07[] = {0x7e, 0x06, 0x06, 0x0c, 0x18, 0x18, 0x18, 0x00};
const byte F08[] = {0x3c, 0x66, 0x66, 0x3c, 0x66, 0x66, 0x3c, 0x00};
const byte F09[] = {0x3c, 0x66, 0x66, 0x3e, 0x06, 0x0c, 0x38, 0x00};

const byte F_A[] = {0x3c, 0x66, 0x66, 0x7e, 0x66, 0x66, 0x66, 0x00};
const byte F_B[] = {0x7c, 0x66, 0x66, 0x7c, 0x66, 0x66, 0x7c, 0x00};
const byte F_C[] = {0x1e, 0x30, 0x60, 0x60, 0x60, 0x30, 0x1e, 0x00};
const byte F_D[] = {0x78, 0x6c, 0x66, 0x66, 0x66, 0x6c, 0x78, 0x00};
const byte F_E[] = {0x7e, 0x60, 0x60, 0x78, 0x60, 0x60, 0x7e, 0x00};
const byte F_F[] = {0x7e, 0x60, 0x60, 0x7c, 0x60, 0x60, 0x60, 0x00};
const byte F_G[] = {0x3c, 0x66, 0x60, 0x6e, 0x66, 0x66, 0x3e, 0x00};
const byte F_H[] = {0x66, 0x66, 0x66, 0x7e, 0x66, 0x66, 0x66, 0x00};
const byte F_I[] = {0x3c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00};
const byte F_J[] = {0x06, 0x06, 0x06, 0x06, 0x06, 0x66, 0x3c, 0x00};
const byte F_K[] = {0xc6, 0xcc, 0xd8, 0xf0, 0xd8, 0xcc, 0xc6, 0x00};
const byte F_L[] = {0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7e, 0x00};
const byte F_M[] = {0xc6, 0xee, 0xfe, 0xd6, 0xc6, 0xc6, 0xc6, 0x00};
const byte F_N[] = {0xc6, 0xe6, 0xf6, 0xde, 0xce, 0xc6, 0xc6, 0x00};
const byte F_O[] = {0x3c, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x00};
const byte F_P[] = {0x7c, 0x66, 0x66, 0x7c, 0x60, 0x60, 0x60, 0x00};
const byte F_Q[] = {0x78, 0xcc, 0xcc, 0xcc, 0xcc, 0xdc, 0x7e, 0x00};
const byte F_R[] = {0x7c, 0x66, 0x66, 0x7c, 0x6c, 0x66, 0x66, 0x00};
const byte F_S[] = {0x3c, 0x66, 0x70, 0x3c, 0x0e, 0x66, 0x3c, 0x00};
const byte F_T[] = {0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00};
const byte F_U[] = {0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x00};
const byte F_V[] = {0x66, 0x66, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x00};
const byte F_W[] = {0xc6, 0xc6, 0xc6, 0xd6, 0xfe, 0xee, 0xc6, 0x00};
const byte F_X[] = {0xc3, 0x66, 0x3c, 0x18, 0x3c, 0x66, 0xc3, 0x00};
const byte F_Y[] = {0xc3, 0x66, 0x3c, 0x18, 0x18, 0x18, 0x18, 0x00};
const byte F_Z[] = {0xfe, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0xfe, 0x00};
const byte F__[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

Glyph font[TOTAL_GLYPHS];

#define ROWS 27

// Three 8x8 Screens Wide 

// WALLS
const byte W00[] = {0x00, 0x00, 0x00};
const byte W01[] = {0x00, 0x00, 0x00};
const byte W02[] = {0x00, 0x00, 0x00};
const byte W03[] = {0x0f, 0xff, 0xfe};
const byte W04[] = {0x08, 0x04, 0x02};
const byte W05[] = {0x0b, 0x75, 0xda};
const byte W06[] = {0x0b, 0x75, 0xda};
const byte W07[] = {0x08, 0x00, 0x02};
const byte W08[] = {0x0b, 0x5f, 0x5a};
const byte W09[] = {0x08, 0x44, 0x42};
const byte W10[] = {0x0f, 0x75, 0xde};
const byte W11[] = {0x01, 0x40, 0x50};
const byte W12[] = {0x0f, 0x5f, 0x5e};
const byte W13[] = {0x00, 0x11, 0x00};
const byte W14[] = {0x0f, 0x5f, 0x5e};
const byte W15[] = {0x01, 0x40, 0x50};
const byte W16[] = {0x0f, 0x5f, 0x5e};
const byte W17[] = {0x08, 0x04, 0x02};
const byte W18[] = {0x0b, 0x75, 0xda};
const byte W19[] = {0x09, 0x00, 0x12};
const byte W20[] = {0x0d, 0x5f, 0x56};
const byte W21[] = {0x08, 0x44, 0x42};
const byte W22[] = {0x0b, 0xf5, 0xfa};
const byte W23[] = {0x08, 0x00, 0x02};
const byte W24[] = {0x0f, 0xff, 0xfe};
const byte W25[] = {0x00, 0x00, 0x00};
const byte W26[] = {0x00, 0x00, 0x00};

// DOTS
const byte D00[] = {0x00, 0x00, 0x00};
const byte D01[] = {0x00, 0x00, 0x00};
const byte D02[] = {0x00, 0x00, 0x00};
const byte D03[] = {0x00, 0x00, 0x00};
const byte D04[] = {0x07, 0xfb, 0xfc};
const byte D05[] = {0x00, 0x8a, 0x20};
const byte D06[] = {0x04, 0x8a, 0x24};
const byte D07[] = {0x07, 0xff, 0xfc};
const byte D08[] = {0x04, 0xa0, 0xa4};
const byte D09[] = {0x07, 0xbb, 0xbc};
const byte D10[] = {0x00, 0x80, 0x20};
const byte D11[] = {0x00, 0x80, 0x20};
const byte D12[] = {0x00, 0x80, 0x20};
const byte D13[] = {0x0f, 0x80, 0x3e};
const byte D14[] = {0x00, 0x80, 0x20};
const byte D15[] = {0x00, 0x80, 0x20};
const byte D16[] = {0x00, 0x80, 0x20};
const byte D17[] = {0x07, 0xfb, 0xfc};
const byte D18[] = {0x04, 0x8a, 0x24};
const byte D19[] = {0x02, 0xfb, 0xe8};
const byte D20[] = {0x02, 0xa0, 0xa8};
const byte D21[] = {0x07, 0xbb, 0xbc};
const byte D22[] = {0x04, 0x0a, 0x04};
const byte D23[] = {0x07, 0xff, 0xfc};
const byte D24[] = {0x00, 0x00, 0x00};
const byte D25[] = {0x00, 0x00, 0x00};
const byte D26[] = {0x00, 0x00, 0x00};

// Death Animation
const byte A00[] = {0x24, 0x66, 0xe7, 0xe7, 0xff, 0xff, 0x7e, 0x3c};
const byte A01[] = {0x00, 0x42, 0xe7, 0xe7, 0xff, 0xff, 0x7e, 0x3c};
const byte A02[] = {0x00, 0x00, 0x81, 0xe7, 0xff, 0xff, 0x7e, 0x3c};
const byte A03[] = {0x00, 0x00, 0x00, 0xe7, 0xff, 0xff, 0x7e, 0x3c};
const byte A04[] = {0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7e, 0x3c};
const byte A05[] = {0x00, 0x00, 0x00, 0x00, 0x18, 0xff, 0x7e, 0x24};
const byte A06[] = {0x00, 0x00, 0x00, 0x00, 0x18, 0x3c, 0x7e, 0x24};
const byte A07[] = {0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18};
const byte A08[] = {0x00, 0x42, 0x24, 0x00, 0x00, 0x24, 0x42, 0x00};

class Animation
{
  public:
  const byte *frames;
};

Animation death[9];
unsigned long lastAnimation;
#define ANIMATION_DELAY 100
byte frame;

class Row
{
  public:
    const byte *walls;
    byte dots[3];
};

Row rows[ROWS];


#define PLAYER_OFFSET_X 4
#define PLAYER_OFFSET_Y 4

class Player
{
  public:
    byte x;
    byte y;
    byte lives;
    bool energized;
};

#define GHOSTS 4

class Ghost
{
  public:
    byte x;
    byte y;
    unsigned long lastMovement;
    unsigned long lastReleased;
    byte lastChoice;
    bool released;
};

Ghost ghosts[GHOSTS];

#define ENERGIZERS 4

class Energizer
{
  public:
    byte x;
    byte y;
    bool used;
};

Energizer energizers[ENERGIZERS];

#define MOVE_LEFT  B00000001
#define MOVE_RIGHT B00000010
#define MOVE_UP    B00000100
#define MOVE_DOWN  B00001000
#define JOY_BUTTON B00010000

Player player;
long lastMove = 0;

byte redScene[8];
byte blueScene[8];
byte greenScene[8];

int state;
int stateAfterMessage;
byte joystick;
unsigned long lastButton = 0;
unsigned long lastScroll = 0;

unsigned long lastEnergizerBlink = 0;
bool energizerBlinkOn = true;
unsigned long lastGhostBlink = 0;
bool ghostBlinkOn = true;

#define ENERGIZER_ACTIVE_TIME 10000
unsigned long energizedStartTime;

byte blinkCount = 0;

byte currentLevel = 0;

byte leftGlyph = 0;
byte rightGlyph = 0;
byte scrollPos = 0;
byte textPos = 0;
byte displayText[25];
bool displayTextRed;
bool displayTextBlue;
bool displayTextGreen;

byte currentWalls[8];
byte currentDots[8];
byte currentGhostWalls[8];

#define PLAYER_MOVE_SPEED   200
#define GHOST_MOVE_SPEED    500
#define MESSAGE_SPEED       50

#define STATE_PLAYING         0
#define STATE_ENTERING_FIGHT  1
#define STATE_DYING           2
#define STATE_RESTART         3
#define STATE_DISPLAY_MESSAGE 4
#define STATE_ENERGIZED       5
#define STATE_NEXT_LEVEL      6
#define STATE_ADVANCE_LEVEL   7

void setup()
{
  Serial.begin(9600);

  // Fetch Random Seed
  randomSeed(analogRead(A0));

  pinMode(joyBPin, INPUT);
  pinMode(joyBPin,INPUT_PULLUP);

  pinMode(Pin_Data, OUTPUT);
  pinMode(Pin_Latch, OUTPUT);
  pinMode(Pin_Clock, OUTPUT);

  // Clear Screen
  clearScene();
  outputScene();
  
  // Should Only Be Done Once
  initFont();
  initWalls();
  initAnimations();
  
  // Setup Intro
  setupIntroText();
}

void loop()
{
  switch (state) {
    case STATE_DISPLAY_MESSAGE:
      joystick = pollJoystick();

      if (joystick & JOY_BUTTON) {
        state = stateAfterMessage;
      }
      
      if (millis() - lastScroll > MESSAGE_SPEED) {
        scrollDisplayText();
        
        lastScroll = millis();
      }
      break;

    case STATE_RESTART:
      currentLevel = 0;
      
      state = STATE_ADVANCE_LEVEL;
      break;

    case STATE_ADVANCE_LEVEL:
      initPlayer();
      resetLevel();
      break;
      
    case STATE_PLAYING:
      getCurrentRows();

      releaseGhost();

      if (player.energized && (millis() - energizedStartTime > ENERGIZER_ACTIVE_TIME)) {
        player.energized = false;
      }
      
      clearScene();
      displayWalls();
      displayGhostDoor();
      displayEnergizers();
      displayDots();
      displayPlayer();
      displayGhosts();
  
      joystick = pollJoystick();

      updatePlayerPosition();
      removeDot();
      
      if (levelFinished()) {
        state = STATE_NEXT_LEVEL;        
      } else {
        // Test for Energizer Collision
        if (collideWithEnergizer()) {
          if (levelFinished()) {
            state = STATE_NEXT_LEVEL;        
          } else {
            player.energized = true;
            energizedStartTime = millis();
          }
        } else {
          // Test for Mob Collision
          if (collideWithGhost()) {
              frame = 255;
              lastAnimation = millis();
              state = STATE_DYING;  
          } else {
              moveGhosts();
          }
        }
      }
      break;

      case STATE_DYING:
        if (displayDeathAnimation()) {
          if (player.lives > 1) {
            player.lives--;
            
            initPlayerPosition();
            resetGhosts();
            state = STATE_PLAYING;  
          } else {
            setupGameOverText();
          }
        }
        break;

      case STATE_NEXT_LEVEL:
        currentLevel++;
        setupNextLevelText();
        break;
  }

  // Output Scene
  outputScene();
}

bool displayDeathAnimation() {
   if (millis() - lastAnimation > ANIMATION_DELAY || frame == 255) {
    frame++;
    
    if (frame == 9) {
      return true;
    } else {
      if (frame == 255)
        frame = 0;
            
      clearScene();
      
      for (byte y = 0; y < 8; y++) {
        byte image[8];
        memcpy(image, death[frame].frames, 8);
        
        redScene[y] = image[y];
        greenScene[y] = image[y];
      }  
      
      lastAnimation = millis();
    }
  } else {
    return false;
  }
}

void initPlayer() {
  player.lives = 3;
  player.energized = false;
  
  initPlayerPosition();
}

void initPlayerPosition() {
  player.x = 13 - PLAYER_OFFSET_X;
  player.y = 19 - PLAYER_OFFSET_Y;
}

void resetLevel() {
  energizers[0].x = 5;
  energizers[0].y = 5;
  energizers[0].used = false;
  
  energizers[1].x = 21;
  energizers[1].y = 5;
  energizers[1].used = false;
  
  energizers[2].x = 5;
  energizers[2].y = 19;
  energizers[2].used = false;
  
  energizers[3].x = 21;
  energizers[3].y = 19;
  energizers[3].used = false;  

  resetGhosts(); 

  initDots();
    
  state = STATE_PLAYING;
}

void resetGhosts() {
  for (byte g = 0; g < GHOSTS; g++) {
    initGhostPosition(g);
   }
}

void initGhostPosition(byte ghost) {
  ghosts[ghost].x = 13;
  ghosts[ghost].y = 13;
  ghosts[ghost].released = false;
  ghosts[ghost].lastReleased = millis();
}

void getCurrentRows() {
  byte firstCol = player.x;
  byte firstRow = player.y;

  // Determine Chunk 0, 1 or 2 from Rows
  byte chunk = (firstCol / 8);

  for (byte y = firstRow; y < firstRow + 8; y++) {
    byte leftWalls = *(rows[y].walls + chunk);
    byte rightWalls = *(rows[y].walls + chunk + 1);

    byte leftDots = rows[y].dots[chunk];
    byte rightDots = rows[y].dots[chunk + 1];

    // Nothing to the Right
    if (chunk == 2) {
      rightWalls = B00000000;
      rightDots = B00000000;
    }

    // Left Half
    byte left = firstCol % 8;
    leftWalls = leftWalls << left;
    leftDots = leftDots << left;

    // Right Half
    byte right = 8 - (firstCol % 8);
    rightWalls = rightWalls >> right;
    rightDots = rightDots >> right;

    // Combine Halves
    currentWalls[y - firstRow] = leftWalls | rightWalls;
    currentDots[y - firstRow] = leftDots | rightDots;
  }
}

void releaseGhost() {
  for (byte g = 0; g < GHOSTS; g++) {
    if (millis() - ghosts[g].lastReleased > ENERGIZER_ACTIVE_TIME) {
    if (ghosts[g].released == false) {
      ghosts[g].released = true;
      ghosts[g].x = 13;
      ghosts[g].y = 11;
      
      ghosts[g].lastReleased = millis();
      break;
    }
  }
  }
}

void removeDot() {
  byte firstCol = player.x + PLAYER_OFFSET_X;
  byte firstRow = player.y + PLAYER_OFFSET_Y;

  // Determine Chunk 0, 1 or 2 from Rows
  byte chunk = (firstCol / 8);
  byte left = firstCol % 8;

  // Update Left Chunk
  rows[firstRow].dots[chunk] &= ~(1 << (7 - left));
}

bool levelFinished() {
  byte result = true;

  // Look for Any Remaining Energizers
  for (byte e = 0; e < ENERGIZERS; e++) {
    if (energizers[e].used == false) {
      result = false;
      break;  
    }
  }

  // Look for Any Remaining Dots
  if (result == true) {
    for (byte x = 0; x < ROWS; x++) {
        if (rows[x].dots[0] != 0 || rows[x].dots[1] != 0 || rows[x].dots[2] != 0) {
          result = false;
          break;
        }
    }
  }

  return result;
}

void displayWalls() {
  for (byte x = 0; x < 8; x++) {
    blueScene[x] |= currentWalls[x];
  }
}

void displayEnergizers() {
  if (millis() - lastEnergizerBlink > 600) {
    energizerBlinkOn = !energizerBlinkOn;
    lastEnergizerBlink = millis();
  }
  
  for (byte e = 0; e < ENERGIZERS; e++) {
    byte offsetY = (energizers[e].y - player.y);
    byte offsetX = (energizers[e].x - player.x);
    
    if (energizerBlinkOn && !energizers[e].used && energizers[e].x >= player.x && energizers[e].x < player.x + 8 && energizers[e].y >= player.y && energizers[e].y < player.y + 8) {
      redScene[offsetY] |= (1 << (7 - offsetX));
      greenScene[offsetY] |= (1 << (7 - offsetX));
    }
  }
}

void displayGhostDoor() {
  byte y = 12;
  byte x = 13;
  byte offsetY = y - player.y;
  byte offsetX = x - player.x;
  
  if (x >= player.x && x < player.x + 8 && y >= player.y && y < player.y + 8) {
    redScene[offsetY] &= ~(1 << (7 - offsetX));
    greenScene[offsetY] |= (1 << (7 - offsetX));
    blueScene[offsetY] |= (1 << (7 - offsetX));
  }
}

void displayDots() {
  blinkCount++;
  if (blinkCount > 3 * 5)
    blinkCount = 0;
 
  for (byte x = 0; x < 8; x++) {
    if (blinkCount == 0)
      redScene[x] |= currentDots[x];
      
    if (blinkCount == 1)
      greenScene[x] |= currentDots[x];
      
    if (blinkCount == 2)
      blueScene[x] |= currentDots[x];      
  }  
  
}

void displayPlayer() {
  byte localX = PLAYER_OFFSET_X;
  byte localY = PLAYER_OFFSET_Y;

  blueScene[localY] &= ~(1 << (7 - localX));
  redScene[localY] |= (1 << (7 - localX));
  greenScene[localY] |= (1 << (7 - localX));
}



void displayGhosts() {
  if (millis() - lastGhostBlink > 100) {
    ghostBlinkOn = !ghostBlinkOn;
    lastGhostBlink = millis();
  }
    
  for (byte g = 0; g < GHOSTS; g++) {
    byte offsetY = (ghosts[g].y - player.y);
    byte offsetX = (ghosts[g].x - player.x);

    // Test if Within Visible Screen
    if (ghosts[g].x >= player.x && ghosts[g].x < player.x + 8 && ghosts[g].y >= player.y && ghosts[g].y < player.y + 8) {
      if (player.energized && ghosts[g].released == true) {
        if (ghostBlinkOn) { // Blue
          redScene[offsetY] &= ~(1 << (7 - offsetX));
          blueScene[offsetY] |= (1 << (7 - offsetX));
          greenScene[offsetY] &= ~(1 << (7 - offsetX));
        } else { // White
          redScene[offsetY] |= (1 << (7 - offsetX));
          blueScene[offsetY] |= (1 << (7 - offsetX));
          greenScene[offsetY] |= (1 << (7 - offsetX));           
        }
      } else {
        switch (g) {
          case 0: // Red
            redScene[offsetY] |= (1 << (7 - offsetX));
            blueScene[offsetY] &= ~(1 << (7 - offsetX));
            greenScene[offsetY] &= ~(1 << (7 - offsetX));
            break;
          case 1: // Cyan
            redScene[offsetY] &= ~(1 << (7 - offsetX));
            blueScene[offsetY] |= (1 << (7 - offsetX));
            greenScene[offsetY] |= (1 << (7 - offsetX)); 
            break;
          case 2: // Pink
            redScene[offsetY] |= (1 << (7 - offsetX)); 
            blueScene[offsetY] |= (1 << (7 - offsetX));
            greenScene[offsetY] &= ~(1 << (7 - offsetX)); 
            break;
          case 3: // Green
            redScene[offsetY] &= ~(1 << (7 - offsetX));     
            blueScene[offsetY] &= ~(1 << (7 - offsetX));
            greenScene[offsetY] |= (1 << (7 - offsetX)); 
            break;          
        }
      }
    }
  }
}

bool collideWithEnergizer() {
  bool result = false;

  for (byte e = 0; e < ENERGIZERS; e++) {
    if (!energizers[e].used && energizers[e].x == (player.x + PLAYER_OFFSET_X) && energizers[e].y == (player.y + PLAYER_OFFSET_Y)) {
      energizers[e].used = true;

      result = true;
    }
  }

  return result;
}

bool collideWithGhost() {
  bool result = false;

  for (byte g = 0; g < GHOSTS; g++) {
    if (ghosts[g].x == (player.x + PLAYER_OFFSET_X) && ghosts[g].y == (player.y + PLAYER_OFFSET_Y)) {
      if (player.energized) {
        initGhostPosition(g);
        
        result = false;
      } else {
        result = true;  
      }
    }
  }

  return result;
}

void getGhostRows(byte ghost) {
  byte firstCol = ghosts[ghost].x - 1;
  byte firstRow = ghosts[ghost].y - 1;

  // Determine Chunk 0, 1 or 2 from Rows
  byte chunk = (firstCol / 8);

  for (byte y = firstRow; y < firstRow + 3; y++) {
    byte leftWalls = *(rows[y].walls + chunk);
    byte rightWalls = *(rows[y].walls + chunk + 1);

    // Nothing to the Right
    if (chunk == 2) {
      rightWalls = B00000000;
    }

    // Left Half
    byte left = firstCol % 8;
    leftWalls = leftWalls << left;

    // Right Half
    byte right = 8 - (firstCol % 8);
    rightWalls = rightWalls >> right;

    // Combine Halves
    currentGhostWalls[y - firstRow] = leftWalls | rightWalls;
  }
}

void moveGhosts() {
  for (byte g = 0; g < GHOSTS; g++) {
    if (millis() - ghosts[g].lastMovement > GHOST_MOVE_SPEED) {
      byte offsetX = 1;
      byte choices[4];
      byte found = 0;
  
      getGhostRows(g);

      // LEFT
      byte hitWall = currentGhostWalls[1] & (1 << (7 - offsetX + 1));
      if (hitWall == 0) {
        choices[found++] = 1;
      }
  
      // RIGHT
      hitWall = currentGhostWalls[1] & (1 << (7 - offsetX - 1));
      if (hitWall == 0) {
        choices[found++] = 2;
      }
  
      // UP
      hitWall = currentGhostWalls[0] & (1 << (7 - offsetX));
      if (hitWall == 0) {
        choices[found++] = 3;
      }
  
      // DOWN
      hitWall = currentGhostWalls[2] & (1 << (7 - offsetX));
      if (hitWall == 0) {
        choices[found++] = 4;
      }
  
      // No Valid Moves
      if (found == 0)
        break;
    
      // Choose a Random Location
      byte choice = (byte)random(found);

      // Attempt to Use Old Choice
      for (byte c = 0; c < found; c++) {
        if (choices[c] == ghosts[g].lastChoice) {
          byte flip = random(100);
          if (flip > 25)
            choice = c;
          break;
        }
      }
  
      switch (choices[choice]) {
        case 1: // LEFT
          ghosts[g].x--;
          if (ghosts[g].x == 3)
            ghosts[g].x = 22;
          break;
        case 2: // RIGHT
          ghosts[g].x++;
          if (ghosts[g].x == 23)
            ghosts[g].x = 4;          
          break;
        case 3: // UP
          ghosts[g].y--;
          break;
        case 4: // DOWN
          ghosts[g].y++;
          break;        
      }

      ghosts[g].lastChoice = choices[choice];
 
      ghosts[g].lastMovement = millis();
    }
  }
}

byte updatePlayerPosition() {
  byte result = 0;
  
  if (millis() - lastMove > PLAYER_MOVE_SPEED) {
    byte joystick = pollJoystick();
    
    if (joystick & MOVE_LEFT || joystick & MOVE_RIGHT || joystick & MOVE_UP || joystick & MOVE_DOWN) {
      
      byte hitWall = 0;
  
      if (joystick & MOVE_LEFT) {
        if (player.x > 0) {
            hitWall = currentWalls[PLAYER_OFFSET_Y] & (1 << (7 - PLAYER_OFFSET_X + 1));

            if (hitWall == 0)
              player.x--;
        } else {
          // Wrap Around
          player.x = 22 - PLAYER_OFFSET_X;
        }
      } else {
        if (joystick & MOVE_RIGHT) {
          if (player.x < (23 - PLAYER_OFFSET_X)) {
            hitWall = currentWalls[PLAYER_OFFSET_Y] & (1 << (7 - PLAYER_OFFSET_X - 1));
            
            if (hitWall == 0)
              player.x++;

            // Wrap Around
            if (player.x == (23 - PLAYER_OFFSET_X))
              player.x = 0;
          }
        } else {
          if (joystick & MOVE_UP) {
            if (player.y > 0) {
                hitWall = currentWalls[PLAYER_OFFSET_Y - 1] & (1 << (7 - PLAYER_OFFSET_X));
                
                if (hitWall == 0)
                  player.y--;
            }
          } else {
            if (joystick & MOVE_DOWN) {
                if (player.y < (23 - PLAYER_OFFSET_Y)) {
                  hitWall = currentWalls[PLAYER_OFFSET_Y + 1] & (1 << (7 - PLAYER_OFFSET_X));
                  
                  if (hitWall == 0)
                    player.y++;
                }
            }
          }
        }
      }
    }
    
    lastMove = millis();
  }

  return result;
}




void loadDisplayText(const char *textToDisplay, bool red, bool green, bool blue) {
  byte textLength = strlen(textToDisplay);
  
  for (byte x = 0; x < textLength; x++) {
    if (textToDisplay[x] == 32)
      displayText[x] = 36;
    else {
      if (textToDisplay[x] < 58)
        displayText[x] = textToDisplay[x] - 48;
      else
        displayText[x] = textToDisplay[x] - 55;
    }
  }
  displayText[textLength] = 0xff;

  displayTextRed = red;
  displayTextBlue = blue;
  displayTextGreen = green;

  scrollPos = 0;
  textPos = 0;

  state = STATE_DISPLAY_MESSAGE;
  lastScroll = millis();
}

void setupIntroText() {
  loadDisplayText("PACMAN\0", false, false, true);

  stateAfterMessage = STATE_RESTART;
}

void setupGameOverText() {
  loadDisplayText("GAME OVER\0", true, false, false);
  
  stateAfterMessage = STATE_RESTART;
}

void setupNextLevelText() {
  loadDisplayText("LEVEL \0", true, false, false);
  
  byte d1, d2, d3;
  byte value = currentLevel + 1;
  if (value > 9) {
    d1 = value / 10;
    d2 = value % 10;
    d3 = 0xff;
  } else {
    d1 = value;
    d2 = 0xff;
    d3 = 0xff;
  }
  
  displayText[6] = d1;
  displayText[7] = d2;
  displayText[8] = d3;
  
  stateAfterMessage = STATE_ADVANCE_LEVEL;
}

void scrollDisplayText() {
  clearScene();

  if (displayText[textPos] == 0xff) {
      scrollPos = 0;
      textPos = 0;
  }
      
  leftGlyph = displayText[textPos];
  rightGlyph = displayText[textPos + 1];
      
  for (byte x = 0; x < 8; x++) {
    byte *lp = font[leftGlyph].pixels + x;
    byte *rp = font[rightGlyph].pixels + x;
  
    if (scrollPos <= 7) {
      if (displayTextRed)
        redScene[x] = *lp >> (7-scrollPos);
      if (displayTextBlue)
        blueScene[x] = *lp >> (7-scrollPos);
      if (displayTextGreen)
        greenScene[x] = *lp >> (7-scrollPos);                
    } else {
      if (displayTextRed)
        redScene[x] = *lp << (scrollPos-7);
      if (displayTextBlue)
        blueScene[x] = *lp << (scrollPos-7);
      if (displayTextGreen)
        greenScene[x] = *lp << (scrollPos-7);
                      
      if (rightGlyph != 0xff) {
        if (displayTextRed)
          redScene[x] |= *rp >> (15-scrollPos);
        if (displayTextBlue)
          blueScene[x] |= *rp >> (15-scrollPos);
        if (displayTextGreen)
          greenScene[x] |= *rp >> (15-scrollPos);                    
      }
    }
  }
  
  scrollPos++;
  if (scrollPos > 15) {
    scrollPos = 8;
    textPos ++;
  }
}

void clearScene() {
  // Clear Scene
  for (byte x = 0; x < 8; x++) {
    blueScene[x] = B00000000;
    redScene[x] = B00000000;
    greenScene[x] = B00000000;
  }
}

void outputScene() {
  for (byte x = 0; x < 8; x++) {
    byte row = x;
    byte red = redScene[row];
    byte blue = blueScene[row];
    byte green = greenScene[row];
        
    // Disable Output
    digitalWrite(Pin_Latch, LOW);
    
    shiftOut(Pin_Data, Pin_Clock, LSBFIRST, ~(1 << (7-row)));
    shiftOut(Pin_Data, Pin_Clock, LSBFIRST, ~green);
    shiftOut(Pin_Data, Pin_Clock, LSBFIRST, ~blue);
    shiftOut(Pin_Data, Pin_Clock, LSBFIRST, ~red);
  
    // Latch Output
    digitalWrite(Pin_Latch, HIGH);
  }
}

byte pollJoystick() {
    int joyX = analogRead(joyXPin); 
    int joyY = analogRead(joyYPin);
    bool joyB = digitalRead(joyBPin);

    byte results = 0;
    
    if (joyX < 200) {
      results |= MOVE_LEFT;
    }
    
    if (joyX > 824) {
      results |= MOVE_RIGHT;
    }

    if (joyY < 200) {
      results |= MOVE_UP;
    }
    
    if (joyY > 824) {
      results |= MOVE_DOWN;
    }

    if (!joyB)
      results |= JOY_BUTTON;

    return results;
}

void initAnimations() {
  death[0].frames = &A00[0];
  death[1].frames = &A01[0];
  death[2].frames = &A02[0];
  death[3].frames = &A03[0];
  death[4].frames = &A04[0];
  death[5].frames = &A05[0];
  death[6].frames = &A06[0];
  death[7].frames = &A07[0];
  death[8].frames = &A08[0];
}

void initWalls() {
  rows[0].walls = &W00[0];
  rows[1].walls = &W01[0];
  rows[2].walls = &W02[0];
  rows[3].walls = &W03[0];
  rows[4].walls = &W04[0];
  rows[5].walls = &W05[0];
  rows[6].walls = &W06[0];
  rows[7].walls = &W07[0];
  rows[8].walls = &W08[0];
  rows[9].walls = &W09[0];
  rows[10].walls = &W10[0];
  rows[11].walls = &W11[0];
  rows[12].walls = &W12[0];
  rows[13].walls = &W13[0];
  rows[14].walls = &W14[0];
  rows[15].walls = &W15[0];
  rows[16].walls = &W16[0];
  rows[17].walls = &W17[0];
  rows[18].walls = &W18[0];
  rows[19].walls = &W19[0];
  rows[20].walls = &W20[0];
  rows[21].walls = &W21[0];
  rows[22].walls = &W22[0];
  rows[23].walls = &W23[0];
  rows[24].walls = &W24[0];
  rows[25].walls = &W25[0];
  rows[26].walls = &W26[0];
}

void initDots() {
  memcpy(rows[0].dots, D00, 3);
  memcpy(rows[1].dots, D01, 3);
  memcpy(rows[2].dots, D02, 3);
  memcpy(rows[3].dots, D03, 3);
  memcpy(rows[4].dots, D04, 3);
  memcpy(rows[5].dots, D05, 3);
  memcpy(rows[6].dots, D06, 3);
  memcpy(rows[7].dots, D07, 3);
  memcpy(rows[8].dots, D08, 3);
  memcpy(rows[9].dots, D09, 3);
  memcpy(rows[10].dots, D10, 3);
  memcpy(rows[11].dots, D11, 3);
  memcpy(rows[12].dots, D12, 3);
  memcpy(rows[13].dots, D13, 3);
  memcpy(rows[14].dots, D14, 3);
  memcpy(rows[15].dots, D15, 3);
  memcpy(rows[16].dots, D16, 3);
  memcpy(rows[17].dots, D17, 3);
  memcpy(rows[18].dots, D18, 3);
  memcpy(rows[19].dots, D19, 3);
  memcpy(rows[20].dots, D20, 3);
  memcpy(rows[21].dots, D21, 3);
  memcpy(rows[22].dots, D22, 3);
  memcpy(rows[23].dots, D23, 3);
  memcpy(rows[24].dots, D24, 3);
  memcpy(rows[25].dots, D25, 3);
  memcpy(rows[26].dots, D26, 3);
}

void initFont() {
  font[0].pixels = &F00[0];
  font[1].pixels = &F01[0];
  font[2].pixels = &F02[0];
  font[3].pixels = &F03[0];
  font[4].pixels = &F04[0];
  font[5].pixels = &F05[0];
  font[6].pixels = &F06[0];
  font[7].pixels = &F07[0];
  font[8].pixels = &F08[0];
  font[9].pixels = &F09[0];

  font[10].pixels = &F_A[0];
  font[11].pixels = &F_B[0];
  font[12].pixels = &F_C[0];
  font[13].pixels = &F_D[0];
  font[14].pixels = &F_E[0];
  font[15].pixels = &F_F[0];
  font[16].pixels = &F_G[0];
  font[17].pixels = &F_H[0];
  font[18].pixels = &F_I[0];
  font[19].pixels = &F_J[0];
  font[20].pixels = &F_K[0];
  font[21].pixels = &F_L[0];
  font[22].pixels = &F_M[0];
  font[23].pixels = &F_N[0];
  font[24].pixels = &F_O[0];
  font[25].pixels = &F_P[0];
  font[26].pixels = &F_Q[0];
  font[27].pixels = &F_R[0];
  font[28].pixels = &F_S[0];
  font[29].pixels = &F_T[0];
  font[30].pixels = &F_U[0];
  font[31].pixels = &F_V[0];
  font[32].pixels = &F_W[0];
  font[33].pixels = &F_X[0];
  font[34].pixels = &F_Y[0];
  font[35].pixels = &F_Z[0];
  font[36].pixels = &F__[0];
}



