from random import *
"""
Before creating a program, I had to first learn how genetic programming
works, because I was really not convinced with how the randomness in
selecting a gene will help. I still didn't understand exactly, until I 
reached step 7, which selects the top 50% from the combined population
of the previous and the current generation.
"""

'''
step 1: [a,b,c,d,e,f,g,h] where every character is a number from 0 to 7,
and rep[i]=j represents that there is a queen at column i and row j
'''

#Step 2
def initialise(pop_size):
    """
    This function will generate the required number of members of the
    very first generation. Further process of this algorithm will be
    applied to this generation and its descendants.
    """
    population = []
    for i in range(pop_size):
        member = [randint(0,7) for i in range(8)]
        population.append(member)
    return population

#Step 3
def fitness_evaluation(gene):
    """
    The fitness function used here will be dependent on the number of
    non-attacking pairs. For an 8x8 chess board, the maximum fitness
    value possible is 28 (i.e. 8*(8-1)/2). The minimum is, obviously,
    0.
    """
    attacking_pairs = 0
    # counting column wise attacks
    column_wise = {}
    for i in gene:
        column_wise[i] = column_wise.get(i,0) + 1
    for i in column_wise:
        k = column_wise[i]
        attacking_pairs += k*(k-1)//2
    # counting left-down-right-up diagonal attacks
    front_slash_diagonal = {}
    for i in range(8):
        k = gene[i] - i
        front_slash_diagonal[k] = front_slash_diagonal.get(k,0) + 1
    for i in front_slash_diagonal:
        k = front_slash_diagonal[i]
        attacking_pairs += k*(k-1)//2
    # count left-up-right-down diagonal attacks
    back_slash_diagonal = {}
    for i in range(8):
        k = gene[i] + i
        back_slash_diagonal[k] = back_slash_diagonal.get(k,0) + 1
    for i in back_slash_diagonal:
        k = back_slash_diagonal[i]
        attacking_pairs += k*(k-1)//2
    return 28 - attacking_pairs #non-attacking pairs

#Step 4
def selection(genes):
    '''
    This function will select genes to procreate for the next generation.
    The frequency of the genes will be random, but genes with higher
    fitness values will have a higher chance of being selected.
    '''
    parent_choices = []
    for i in genes:
        k = fitness_evaluation(i)
        parent_choices.extend([i]*k)
    shuffle(parent_choices) # to increase chance of normal distribution
    if not parent_choices:
        parent_choices = genes.copy()
    selected = []
    for i in genes:
        selected.append(choice(parent_choices))
    return genes, selected

#Step 5
def crossover(genes):
    '''
    This function will create members of the next generation, which are
    produced by procreation of members of the present generation.
    '''
    shuffle(genes) # because we still want randomness to play
    children = []
    for i in range(0, len(genes), 2):
        child1 = genes[i][:3] + genes[i+1][3:]
        child2 = genes[i+1][:3] + genes[i][3:]
        children.extend([child1, child2])
    return children

#Step 6
def mutation(genes):
    '''
    This function will account for the rare possibility of mutation in a
    member of the new generation. In this case, we have set the possibility
    at 10% or 0.1.
    '''
    size = len(genes)
    for i in range(size):
        if random() < 0.1:
            j = randint(0,7)
            k = randint(0,7)
            genes[i][j] = k
    return genes

#Step 7
def survival(old_genes, new_genes, pop_size):
    '''
    This function is intended to keep the top 50% of the population comprising
    the old generation and the new generation. This is the survival of the
    fittest.
    '''
    total_population = old_genes + new_genes
    total_population.sort(key=lambda x: -fitness_evaluation(x))
    return total_population[:pop_size]

#Step 8
def termination(genes, round, limit, pop_size):
    '''
    This function is where we check if we have reached a solution. If we have,
    we stop. If we have not, we generally repeat the algorithm from step 3. In
    this case, we set a limit of generations to stop somewhere even if we do not
    get a solution.
    '''
    
    k = fitness_evaluation(genes[0])
    fit = k
    for i in range(1, pop_size):
        fit += fitness_evaluation(genes[i])
    # print(f"Average fitness is {fit/pop_size}/28 in generation {round}")
    
    valid = False
    for i in range(1,pop_size):
        if genes[i] != genes[0]:
            valid = True
            break
    if not valid:
        return True
    
    if fitness_evaluation(genes[0]) == 28 or round == limit:
        return True
    return False

# Now, to where all of this begins

if __name__ == "__main__":
    max_generations = 2000
    population_size = 100
    current_gen = 1
    population = initialise(population_size)
    termination(population, 0, 0, population_size)
    while True:
        old, parents = selection(population)
        new = crossover(parents)
        new = mutation(new)
        population = survival(old, new, population_size)
        # print(f"Generation {current_gen}:\n{population}")
        if termination(population, current_gen, max_generations, population_size):
            print(f"Best case: {population[0]} with fitness value {fitness_evaluation(population[0])}/28 after {current_gen} generation(s)")
            break
        current_gen += 1