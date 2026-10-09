CXX = g++
CXXFLAGS = -O3 -DNDEBUG -march=native

generate-data: generate-data.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
