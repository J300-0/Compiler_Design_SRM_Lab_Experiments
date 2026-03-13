def generate_ll1_parser(grammar,start_sym,terminals,non_terminals):
    first={n: set()for n in non_terminals}
    follow={n: set() for n in non_terminals}
    follow[start_sym].add('$')

    def get_first(seq):
        if not seq or seq[0] =='e': return {'e'}
        if seq[0] in terminals: return{seq[0]}
        f = set(first[seq[0]])
        if 'e' in f and len(seq) > 1: return (f-{'e'}) | get_first(seq[1:])
        return f
    changed = True
    while changed:
        changed = False
        for nt, prods in grammar.items():
            for prod in prods:
                f=get_first(prod)
                if not f.issubset(first[nt]):
                    first[nt] |= f
                    changed = True

    changed = True
    while changed:
        changed = False
        for nt, prods in grammar.items():
            for prod in prods:
                for i , sym in enumerate(prod):
                    if sym in non_terminals:
                        next_f = get_first(prod[i+1:]) if i+1 < len(prod) else {'e'}
                        new_follow = (next_f - {'e'}) | (follow[nt] if 'e' in next_f else set())
                        if not new_follow.issubset(follow[sym]):
                            follow[sym] |= new_follow
                            changed = True
    table = {n:{} for n  in non_terminals}
    for nt , prods in grammar.items():
        for prod in prods:
            f = get_first(prod)
            for t in f - {'e'}:
                table[nt][t] = f"{nt} -> {''.join(prod)}"
            if 'e' in f:
                for t in follow[nt]:
                    table[nt][t] = f"{nt} -> {''.join(prod)}"
    return first, follow, table

if __name__ == "__main__":
    grammar={
        'S': [['A', 'B', 'c']],
        'A': [['a'], ['e']],
        'B': [['b'], ['e']]
    }
    first,follow,table = generate_ll1_parser(
        grammar = grammar,
        start_sym = 'S',
        terminals = {'a','b','c'},
        non_terminals = {'S','A','B'}        
    )
    print("--- FIRST SETS ---")
    for nt, f in first.items(): print(f"{nt}: {f}")

    print("\n--- FOLLOW SETS ---")
    for nt, f in follow.items(): print(f"{nt}: {f}")

    print("\n--- PARSING TABLE ---")
    for nt, rules in table.items():
        for term, rule in rules.items():
            print(f"M[{nt}, {term}] = {rule}")
    
