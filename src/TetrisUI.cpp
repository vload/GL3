#include "TetrisUI.h"

TetrisUI::TetrisUI(TetrisState& state) : state(state) {
    // Setup imgui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    // io.ConfigFlags |=
    //     ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
    io.ConfigFlags |=
        ImGuiConfigFlags_DockingEnable;  // IF using Docking Branch
    // io.ConfigDockingWithShift = true;    // IF using Docking Branch

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(
        state.window,
        true);  // Second param install_callback=true will install
                // GLFW callbacks and chain to existing ones.
    ImGui_ImplOpenGL3_Init();
}

TetrisUI::~TetrisUI() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void TetrisUI::loop() {
    // start the ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // imgui menu
    constexpr double ONE = 1.0;
    constexpr double ZERO = 0.0;
    if (ImGui::Button("New Game")) {
        state.should_start_new_game = true;
    }
    if (state.is_game_over) {
        ImGui::Text("Game Over!");
    }
    ImGui::Text("Score: %d", state.score);

    // render imgui
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}