def generate_ll1_parser(grammar,start_sym,terminals, non_terminals):
    first = {n:set() for n in non_terminals}
    follow = {n:set() for n in non_terminals}
    follow[start_sym].add('@')

    def get_first(seq):
        if not seq or seq[0] == 'e' :return{'e'}
        if seq[0] in terminals: return {seq[0]}
        f = set(first[seq[0]])
        if 'e' in f and len(seq) >1: return (f-{'e'}) | get_first(seq[1:])
        return f
    # FIRST
    changed = True
    while changed:
        changed = False
        for nt , prods in grammar.items():
            for prod in prods:
                f = get_first(prod)
                if not f.issubset(first[nt]):
                    first[nt] |= f
                    changed = True
    #FOLLOW

    changed = True 
    while changed:
        changed = False
        for nt, prods in grammar.items():
            for prods in prods:
                for i, sym in enumerate(prod):
                    next_f = 
 