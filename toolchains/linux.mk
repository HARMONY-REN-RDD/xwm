CXX_LINUX := g++
LD_FLAGS_LINUX := -lcrypto -lpthread -lyaml-cpp
CXX_FLAGS_LINUX := -std=c++17 -Wall -I$(INCLUDE_DIR)


linux: $(LINUX_BUILD_DIR)/$(PROJECT_NAME)

$(LINUX_BUILD_DIR)/$(PROJECT_NAME): $(LINUX_OBJ) | $(LINUX_BUILD_DIR)
	$(CXX_LINUX) -o $@ $^ $(LD_FLAGS_LINUX)

$(LINUX_BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(LINUX_BUILD_DIR)
	@ mkdir -p $(dir $@)
	$(CXX_LINUX) $(CXX_FLAGS_LINUX) -c $< -o $@

$(LINUX_BUILD_DIR):
	mkdir -p $@
