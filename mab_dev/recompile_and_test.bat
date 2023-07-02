cd ../build
cmake ..
cmake --build . --config Release
cd ../python-package
pip install .
cd ../mab_dev
python test.py