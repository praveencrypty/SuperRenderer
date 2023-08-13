#include "UI.h"

void setupUI(GLFWwindow* window) {
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(window, true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
	ImGui_ImplOpenGL3_Init();
}


void startIMGUIFrame()
{
// Start the Dear ImGui frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	
}


void endIMGUIFrame()
{
	ImGui::EndFrame();
}


void destroyIMGUI()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}


void UIComponents()
{
	//All UI Components Should be coded here
	ImGui::ShowDemoWindow(); // Show demo window! :)

	ImGui::SetNextWindowSize(ImVec2(400, 200), ImGuiCond_FirstUseEver);
	ImGui::Begin("My First Tool", NULL, ImGuiWindowFlags_NoTitleBar);
	{
		ImGui::Text("Hello, world %d", 123);
		if (ImGui::Button("Save")) { std::cout << "printed"; }
	}
	ImGui::End();
}


void UIRenderLoop(GLFWwindow* window)
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}


void FullUIRender(GLFWwindow* window)
{
	startIMGUIFrame();

	UIComponents();

	UIRenderLoop(window);

	endIMGUIFrame();

}


void ImGUI_Styling() {

}