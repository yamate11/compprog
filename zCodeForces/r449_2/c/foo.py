#!/usr/bin/env python3

f0 = "What are you doing at the end of the world? Are you busy? Will you save us?"
f1 = f'What are you doing while sending "{f0}"? Are you busy? Will you send "{f0}"?'
print(len(f0));
print(len('What are you doing while sending "'))
print(len('"? Are you busy? Will you send "'))
print(len('"?'))

print('---')
print(f0[68])
print(f1[193])
print(f1[138])
print(f0[46])
