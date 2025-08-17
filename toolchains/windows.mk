CXX_WINDOWS := x86_64-w64-mingw32-g++
LD_FLAGS_WINDOWS := -lpthread
CXX_FLAGS_WINDOWS := --sysroot=/usr/x86_64-w64-mingw32 \
                     -I$(INCLUDE_DIR) \
                     -std=c++17 -Wall

windows: $(WINDOWS_BUILD_DIR)/$(PROJECT_NAME).exe

$(WINDOWS_BUILD_DIR)/$(PROJECT_NAME).exe: $(WINDOWS_OBJ) | $(WINDOWS_BUILD_DIR)
	$(CXX_WINDOWS) -static -o $@ $^ $(LD_FLAGS_WINDOWS)

$(WINDOWS_BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(WINDOWS_BUILD_DIR)
	@ mkdir -p $(dir $@)
	$(CXX_WINDOWS) $(CXX_FLAGS_WINDOWS) -c $< -o $@


$(WINDOWS_BUILD_DIR):
	mkdir -p $@
