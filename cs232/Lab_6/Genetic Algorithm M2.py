import random
def random_chromosome(n):
    return [random.randint(0,n-1)for _ in range(n)] #randomly generates chromosomes(will be used for first generation)
    

def fitness(current_chromosome,n):
    curr_attack = 0
    total_pairs = n*(n-1)//2
    for i in range(n):
        for j in range(i+1,n):
            if current_chromosome[i]==current_chromosome[j] or abs(current_chromosome[i]-current_chromosome[j])== abs(i-j):
                curr_attack+=1
    non_attack = total_pairs - curr_attack
    return non_attack #counts the number of non attacking pairs in the current chromosome(used to calculate fitness)

# def selection(current_population ,n):
#     fitness_score = [fitness(current_population[i],n)for i in range(0,len(current_population))] #calculate the fitness score for each chromosome in population
#     total_fitness = sum(fitness_score)
    
#     if total_fitness ==0:
#         return current_population
    
#     probabilities = [score/total_fitness for score in fitness_score] #calculate probability of each chromosome
    
#     ranges = [] # will store range of probability for each chromosome
    
#     cumulative = 0 # store cumulative sum of prob
#     for prob in probabilities:
#         ranges.append((cumulative,cumulative+prob))
#         cumulative+=prob
#     new_population = []
#     for _ in range(len(current_population)):
#         r = random.random()
#         for i ,(low,high) in enumerate(ranges):
#             if(low<=r<=high):
#                 new_population.append(current_population[i]) # if the selected random number lies in this probability range then append it to new population
#                 break
#     return new_population

# firstly i had used this selection function but since initially all had low fitness scores thus the solution was never converging
#thus i updated it to new selection function which selects 3 random population then finds best fit
def selection(population, n, k=3):
    selected = random.sample(population, k)
    return max(selected, key=lambda chrom: fitness(chrom, n))     
    
def crossover(chromosome1,chromosome2,n):
    crossover_point = random.randint(1,n-2) # select random index for crosover
    return chromosome1[:crossover_point]+chromosome2[crossover_point:] # return a new chromosome after crossover

def mutation(current_chromosome,n):
    mutated = current_chromosome[:]
    mutated[random.randint(0,n-1)] = random.randint(0,n-1)
    return mutated # helps mutate the current chromosome for adding ranfomistion



def genetic_algo(n, population_size=50, generations=100, best_preserve=5):
    population = [random_chromosome(n) for _ in range(population_size)] # step 2: initialisation 
    for _ in range(generations):
        population = sorted(population, key=lambda chrom: -fitness(chrom, n)) # step 3: fitness score
        if fitness(population[0], n) == n * (n - 1) // 2:
            return population[0] # solution found
        
        new_population = population[:best_preserve]  # Keep best solutions
        while len(new_population) < population_size:
            parent1, parent2 = selection(population, n), selection(population, n) # step 4:selection
            child = crossover(parent1, parent2, n) #step 5: crossover
            child = mutation(child, n) # step 6: mutation
            new_population.append(child)
        
        population = new_population# step 7:update generation
    
    return []


if __name__ == "__main__":
    no_queens = 8
    solution = genetic_algo(no_queens)
    if solution:
        print(solution)
    else:
        print("No solution found in provied no of generations try increasing generation or population size")
            
    
