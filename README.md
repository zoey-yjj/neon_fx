# **NeonFX** - *Forex Trading Platform*


## **Overview**

NeonFX is a lightweight, high-performance EUR/USD forex trading platform built in C++. It simulates real-time market conditions, order execution, and portfolio management with a clean command-line interface.


## **Installation & Usage**

### Prerequisites

c++17 (or later) compiler

### Build & Run

```bash
# Clone the repository
git clone https://github.com/zoey-yjj/neon_fx.git 
cd neon_fx

# Install dependencies
chmod 777 install_dependencies.sh
./install_dependencies.sh

# Compile the project
make

# Run the executable
./bin/neon_fx

# Run the tests
make test

# Clean up
make clean
```


## **Develop Plans**

- support symbol:
    - start with EUR/USD, will support multiple currency pairs
- order type only market maker:
    - default post only


## **License**

NeonFX is open-source under the MIT License.
