echo "Making create_tests.c..."
gcc -g test/create_tests.c -o create_tests

echo "Running create_tests..."
./create_tests test/test.c
rm create_tests
mv tests_main.c test/

echo "Making tests..."
make tests

echo "Running tests..."
./tests
