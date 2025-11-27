"""
Currency Converter Calculator
A simple tool to convert between different currencies using real-time exchange rates.
"""

import requests
from datetime import datetime

class CurrencyConverter:
    def __init__(self):
        # Using exchangerate-api.com for fetching exchange rates
        self.api_url = "https://api.exchangerate-api.com/v4/latest/"
        self.supported_currencies = []
        
    def get_exchange_rates(self, base_currency):
        """Fetch current exchange rates for a base currency"""
        try:
            response = requests.get(f"{self.api_url}{base_currency}")
            if response.status_code == 200:
                data = response.json()
                self.supported_currencies = list(data['rates'].keys())
                return data['rates']
            else:
                print(f"Error: Unable to fetch exchange rates (Status: {response.status_code})")
                return None
        except requests.exceptions.RequestException as e:
            print(f"Error: Connection failed - {e}")
            return None
    
    def convert(self, amount, from_currency, to_currency):
        """Convert amount from one currency to another"""
        from_currency = from_currency.upper()
        to_currency = to_currency.upper()
        
        # Get exchange rates with from_currency as base
        rates = self.get_exchange_rates(from_currency)
        
        if rates is None:
            return None
        
        if to_currency not in rates:
            print(f"Error: '{to_currency}' is not a supported currency")
            return None
        
        # Calculate converted amount
        converted_amount = amount * rates[to_currency]
        return converted_amount
    
    def display_supported_currencies(self):
        """Display all supported currencies"""
        if not self.supported_currencies:
            rates = self.get_exchange_rates("USD")
            if rates is None:
                return
        
        print("\n=== Supported Currencies ===")
        print(", ".join(sorted(self.supported_currencies)))
        print(f"\nTotal: {len(self.supported_currencies)} currencies")

def main():
    """Main function to run the currency converter"""
    converter = CurrencyConverter()
    
    print("=" * 50)
    print("💱 CURRENCY CONVERTER")
    print("=" * 50)
    
    while True:
        print("\nOptions:")
        print("1. Convert currency")
        print("2. View supported currencies")
        print("3. Exit")
        
        choice = input("\nEnter your choice (1-3): ").strip()
        
        if choice == "1":
            try:
                # Get input from user
                amount = float(input("\nEnter amount: "))
                from_curr = input("From currency (e.g., USD): ").strip().upper()
                to_curr = input("To currency (e.g., EUR): ").strip().upper()
                
                # Perform conversion
                result = converter.convert(amount, from_curr, to_curr)
                
                if result is not None:
                    print("\n" + "=" * 50)
                    print(f"{amount:.2f} {from_curr} = {result:.2f} {to_curr}")
                    print(f"Exchange rate as of: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
                    print("=" * 50)
                    
            except ValueError:
                print("\n Error: Please enter a valid number for amount")
            except Exception as e:
                print(f"\n Error: {e}")
        
        elif choice == "2":
            converter.display_supported_currencies()
        
        elif choice == "3":
            print("\nThank you for using Currency Converter!")
            break
        
        else:
            print("\n Invalid choice. Please select 1, 2, or 3.")

if __name__ == "__main__":
    main()