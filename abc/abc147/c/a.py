print('Possible' if sum([input().count('#')-1 for i in range(int(input().split()[0])-1)]) == input().count('.') else 'Impossible')
