def loose_change(cents):
    cents = max(cents, 0)
    return {'Nickels': ((int(cents)%25)%10)//5, 'Pennies': ((int(cents)%25)%10)%5, 'Dimes': (int(cents)%25)//10, 'Quarters': int(cents)//25}
