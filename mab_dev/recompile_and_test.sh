cd ../build
cmake ..
cmake --build . --config Release
cd ../python-package
pip install .
cd ../mab_dev
python run_classifier.py