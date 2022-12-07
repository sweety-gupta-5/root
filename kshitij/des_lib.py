import importlib.util

# For illustrative purposes.
package_name = 'Crypto'

spec = importlib.util.find_spec(package_name)
if spec is None:
    print(package_name +" is not installed")