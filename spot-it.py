P, S, C = 7, 8, 57                  # Prime, Symbols per card, Total cards
cards = [[0]*S for _ in range(C)]
cards[0] = [i+1 for i in range(S)]  # First card

for i in range(P):                  # Grid cards
    for j in range(P):
        cards[i*P+j+1] = [i+2] + [((i*k+j)%P)+P*k+P+2 for k in range(P)]

for i in range(P):                  # Infinity cards
    cards[P*P+1+i] = [1] + [P+2+j+i*P for j in range(P)]

for i, card in enumerate(cards):    # Print cards
    print(f"Card {i+1:2}:", *[f"{n:2}" for n in card])
