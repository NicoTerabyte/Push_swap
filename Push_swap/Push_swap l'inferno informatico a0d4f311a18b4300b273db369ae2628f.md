# Push_swap l'inferno informatico

# La teoria dei vari file e come funzionano:

# File push_swap.c:

Principalmente il main eccolo qui in tutto il suo splendore:

```c
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac < 2)
		return (0);
	stack = init(ac, av);
	ft_sorter(stack);
	ft_exit(stack);
	return (0);
}
```

Molto semplice in realtà non c'è molto da spiegare oltre al fatto che viene utilizzato con av e ac, al suo interno dichiariamo la variabile t_stack stack variabile importante per gestire i due stack, infatti la variabile t_stack è dichiarata come struttura nella libreria push_swap.h ed è strutturato in questo modo:

```c
typedef struct s_stack
{
	int	*a;
	int	*b;
	int	last_a;
	int	last_b;
}		t_stack;
```

Dove le variabili sono gestite in questo modo:

a e b sono due array di interi i nostri stack insomma.

last_a e last_b sono l'indice di appartenenza dell'ultimo valore nei rispettivi stack.

**IMPORTANTE**:

*Perché settiamo una grandezza dei nostri stack sapendo che la loro memoria viene espansa di tot? beh è molto semplice perché rispetto ad array di stringhe (con cui abbiamo lavorato fino a mò) non puoi fare un ciclo while di questo tipo:
while(a[i]), e sapete perché beh perché C riconoscerebbe il valore 0 come nullo cioè fine dell'array e noi non vogliamo questo anche perché lo 0 potrebbe essere d'ovunque nello stack*. visto che è uno stack di numeri e non una stringa

detto questo ritornando al main, di base facciamo un controllo sul numero di argomenti con eventuale uscita nel caso di numero insufficente, in seguito riempiamo la nostra variabile con la funzione init che verrà spiegata dopo e infine liberiamo la memoria di tutti gli stack grazie alla funzione ft_exit che eseguirà dei free per non avere leaks.

## init.c

Il file che imposta il nostro codice, ciò che ci fornisce tutti i materiali per costruire i nostri stack il file init.c.

Andiamo in ordine con l'ordine effettivo delle funzioni:

### *void*    fill_stack(*int* *ac*, *char* ***av*, *int* *i*, t_stack **stack*):

```c
void	fill_stack(int ac, char **av, int i, t_stack *stack)
{
	int	j;

	stack->a = (int *)malloc(sizeof(int) * (ac - 1));
	stack->b = (int *)malloc(sizeof(int) * (ac - 1));
	j = 0;
	while (i < ac)
		stack->a[j++] = ft_atoi(av[i++], stack->a);
	find_dup(stack->a, j);
	stack->last_a = j;
	stack->last_b = 0;
}
```

Questa funzione ci permette di riempire e completare lo stack inizializzando i due stack con la malloc e riempiendo lo stack_a con con i valori numerici ricavati da terminale e conservati in av grazie alla funzione ft_atoi (modificata per l'evenienza) .

Il segreto che si cela dietro all'inizializzazione sta nel malloccare con ac - 1 (non contiamo il nome del programma vero???????).

in seguito per sfizio controlliamo i numeri duplicati con la funzione find_dup (che spiegherò più avanti)

setterò poi come grandezza di stack_a l'indice dell'ultimo valore inserito (che in questo caso è j).

le variabili passate sono ac e av (non serve spiegare) lo stack che dev'essere riempito e un valore che i che parte da 1 (salta il nome del programma in av).

### t_stack **init(int ac, char **av):*

Questa funzione è il cuore dell'inizializzazione del nostro stack ed è fatta così:

```c
t_stack	*init(int ac, char **av)
{
	char	**tmp;
	int		len;
	t_stack	*stack;

	tmp = NULL;
	len = 0;
	if (ac == 2)
	{
		tmp = ft_split(av[1], ' ');
		while (tmp[len] != NULL)
			len++;
		stack = malloc(len * sizeof(t_stack));
		fill_stack(len, tmp, 0, stack);
		free(tmp);
	}
	else if (ac >= 3)
	{
		stack = malloc((ac - 1) * sizeof(t_stack));
		fill_stack(ac, av, 1, stack);
	}
	else
		return (NULL);
	return (stack);
}
```

cercherò di essere sintetico:

la variabile tmp ci serve per avere i valori presi da av (salvati solo su una riga ricordo nel caso i valori vengano inseriti tra “ ” nella linea di comando) e salvarli grazie all funzione ft_split all'interno della matrice tmp.

len (nel caso ci sia da splittare l'argomento tra “ “ bisognerà segnare quanto è grande per definire last_a e last_b.

t_stack *stack (non serve neanche dirlo).

il primo if si verifica se abbiamo due argomenti, che nel nostro caso saranno il nome del programma più i numeri tra “ “ (molto probabile).

in salsa viene preso l'argomento tra “ “ e viene splittato in modo tale da suddividere un numero alla volta definendo anche con la malloc la dimensione dello stack, poi di per sè verrà riempito con la funzione fill_stack.

il secondo if è nel caso ci siano più di due argomenti definiamo la dimensione dello stack e poi lo riempiamo, non dobbiamo fare nessuna operazione i numeri sono già suddivisi.

l'else è nel caso non ci siano abbastanza argomenti e quindi si concluderà ritornando NULL

Dopo le varie verifiche ritorneremo lo stack inizializzato.

### funzione void three_sorting(t_stack *stack)

io l'ho creata tramite la spiegazione al seguente link.

[Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

Non mi dilungherò sulle spegazioni visto che principalmente valutiamo ogni casistiche per impiegare meno mosse possibili con tre numeri ecco il codice comuque:

```c
void	three_sorting(t_stack *stack)
{
	if ((stack->a[0] < stack->a[1]) && (stack->a[0] < stack->a[2])
		&& (stack->a[1] > stack->a[2]))
	{
		ft_sa(stack);
		ft_ra(stack);
	}
	else if ((stack->a[0] > stack->a[1]) && (stack->a[0] > stack->a[2])
		&& (stack->a[1] > stack->a[2]))
	{
		ft_sa(stack);
		ft_rra(stack);
	}
	else if ((stack->a[0] < stack->a[1]) && (stack->a[0] > stack->a[2])
		&& (stack->a[1] > stack->a[2]))
		ft_rra(stack);
	else if ((stack->a[0] > stack->a[1]) && (stack->a[0] > stack->a[2])
		&& (stack->a[1] < stack->a[2]))
		ft_ra(stack);
	else if ((stack->a[0] > stack->a[1]) && (stack->a[0] < stack->a[2])
		&& (stack->a[1] < stack->a[2]))
		ft_sa(stack);
}
```

### *int* ft_sorter(t_stack **stack*):

Funzione molto semplice che sceglie quale algoritmo di ordinamento fare in base a quanti numeri ci sono nello stack:

```c
int	ft_sorter(t_stack *stack)
{
	if (!check_sorted_asc(stack->a, stack->last_a))
	{
		if (stack->last_a == 2)
			ft_sa(stack);
		else if (stack->last_a == 3)
			three_sorting(stack);
		else
			quick_sort_a(stack, stack->last_a, 0);
	}
	return (0);
}
```

Molto semplice, ah ovviamente se lo stack è già ordinato non ordinerà nulla e terminerò il programma. più di 3 argomenti daranno il via alla funzione cuore del programma quick_sort_a che spiegherò (visto che è un casino) per ultima.

# Checks.c

File che contine principalmente funzioni che eseguono vari check per vedere e controllare se il programma può essere eseguito o se comunque può continuare ad esserlo.

### *void*    print_error(*int* **stack*)

la funzione è molto semplice serve a inviare un messaggio di errore e a liberare lo stack che era stato precedentemente malloccato, in seguito il programma verrà chiuso

```c
void	print_error(int *stack)
{
	free(stack);
	write(2, "Error\n", 6);
	exit(0);
}
```

### *void*    find_dup(*int* **a*, *int* *dim*)

La funzione si presenta così:

```c
void	find_dup(int *a, int dim)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < dim)
	{
		while (j < dim)
		{
			if (a[i] == a[j])
				print_error(a);
			j++;
		}
		i++;
		j = i + 1;
	}
}
```

i e j hanno un ruolo preciso, praticamente i punta ad un numero e inizia il ciclo while finché non raggiunge la dimensione dell'array però perché dico puntare un numero? beh perché il secondo while quello dove scorro l'array con j serve appositamente per confrontare tutti i numeri successivi a quello puntato da i nell'array, questo controllo andrà avanti controllando ogni singolo numero puntato da i e partendo da i + 1 con j

### *void*    ft_exit(t_stack **stack*)

funzione per liberare gli stack e concludere il programma:

```c
void	ft_exit(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	exit(0);
}
```

### *int* ft_isdigit(*int* *c*)

vecchia conoscenza da libft, non sto nemmeno a spiegarla

```c
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
```

### *int* ft_atoi(*char* **str*, *int* **stack*)

Una variante dell'origine che fa controlli di overflow uscendo dal programma con numeri che superano il valore intero

ATTENZIONE

Questo significa che l'errore viene gestito di norma l'overflof della atoi originale veniva gestita come undefined behaviour ma nel nostro caso è un requisito controllare l'errore sopra INT_MAX e INT_MIN

```c
int	ft_atoi(char *str, int *stack)
{
	long int	r;
	int			s;
	int			i;

	r = 0;
	s = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			print_error(stack);
		r = r * 10 + str[i++] - '0';
	}
	if (r > 2147483647 || r < -2147483647)
		print_error(stack);
	return (r * s);
}
```

Allora come funziona: noi riceviamo la stringa da convertire in un intero e passiamo anche il nostro stack, questo perché nel caso ci sia overflow libereremo la memoria direttamente nella funzione atoi.

La conversione è praticamente uguale alla atoi classica, cotrollo degli spazi e di 1 segno se c'è ne fosse uno, con l'aggiunta di interruzione del programma  nel caso venga trovato un valore non numerico o nel caso di overflow

# Push_swap_utils.c

Prima di toccare effettivamente l'algoritmo spiegherò varie funzioni di supporto che mi hanno permesso di concludere il codice e che hanno aiutato molto per check durante l'esecuzione del quick_sort

### *void*    tmp_sort(*int* **tmp_stk*, *int* *dim*)

Questa funziona crea un array temporaneo che grazie al bubble_sort viene ordinato in ordine crescente, perché mi serve questo array temporaneo? beh serve per trovare il pivot e fa da supporto infatti alla funzione “partition” che spiegherò più avanti

```c
void	tmp_sort(int *tmp_stk, int dim)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < dim)
	{
		j = i + 1;
		while (j < dim)
		{
			if (tmp_stk[i] > tmp_stk[j])
			{
				tmp = tmp_stk[i];
				tmp_stk[i] = tmp_stk[j];
				tmp_stk[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
```

### *int*     check_sorted_desc(*int* **stack*, *int* *dim*)

Mi permette di verificare se il mio stack è ordinato in maniera decrescente (dal più grande al più piccolo) 

```c
int		check_sorted_desc(int *stack, int dim)
{
	int	i;

	i = 1;
	while (i < dim)
	{
		if (stack[i - 1] < stack[i])
			return (0);
		i++;
	}
	return (1);
}
```

La sintassi è molto semplice parto dal primo valore con i per confrontare sempre quello precedente e mi fermo una volta prima, ovvio è che in base al numero precedente verrà stabilito con un if se lo stack è in ordine decrescente o no.

### *int* check_sorted_asc(*int* **stack*, *int* *dim*)

Il contrario della funzione precedente

```c
int	check_sorted_asc(int *stack, int dim)
{
	int	i;

	i = 1;
	while (i < dim)
	{
		if (stack[i - 1] > stack[i])
			return (0);
		i++;
	}
	return (1);
}
```

### *int* when_push(t_stack **stack*, *int* *dim*, *int* *f*)

funzione creata solo a scopo di risparmiare linee di codice durante la creazione dell'algoritmo.

```c
int	when_push(t_stack *stack, int dim, int f)
{
	if (f == 1)
		ft_pb(stack);
	else if (f == 0)
		ft_pa(stack);
	dim--;
	return (dim);
}
```

 principalmente viene eseguita con la flag (f) che definisce quale push bisogna fare, scelto ovviamente in base all'esigenza, in seguito verrà alterata la dimensione che ATTENZIONE la possiamo definire sia per lo stack_a che lo stack_b ma questo verrà spiegato più avanti.

# Quick_sort.c

E qui vi voglio, file che contine il pezzo chiave per ordinare il mio stack

Rispetto a prima andrò in ordine di priorità e cioè che le funzioni non verranno elencate dal basso verso l'altro andrò con le funzioni che vengono chiamate prima:

### *int* quick_sort_a(t_stack **stack*, *int* *dim*, *int* *count_r*)

Una bella bestia, colui che inizia tutto permettetemi di inserire il codice:

```c
int	quick_sort_a(t_stack *stack, int dim, int count_r)
{
	int	pivot;
	int	numbers;
	//dim è un numero globale passato nei due quick_sort per gestire la manipolazione
	//degli stack
	if (check_sorted_asc(stack->a, dim) == 1)
		return (1);
	numbers = dim;
	//parte finale (l'ultimo sort insomma)
	//ordinamento dei primi numeri nello stack a alla fine del quick sort
	if (dim <= 3)
	{
		quick_sort_3_a_b(stack, dim);
		return (1);
	}
	if (!count_r && !partition(&pivot, stack->a, dim))
		return (0);
	//printf("dim %d e numbers/2 %d e numbers 2 %d\n", dim, numbers / 2, numbers % 2);
	while (dim != numbers / 2 + numbers % 2) //perché questo???
	{
		if (stack->a[0] < pivot && (dim--))
			ft_pb(stack);
		else if (++count_r)
			ft_ra(stack);
	}
	while (count_r--)
		ft_rra(stack);
	return (quick_sort_a(stack, numbers / 2 + numbers % 2, 0)
		&& quick_sort_b(stack, numbers / 2, 0));
	return (1);
}
```

Andiamo con ordine, le variabili che riceve: 

t_stack *stack, lo stack generico, insomma sia stack_a che b (lavoriamo con una struct ricordo).

int dim, la dimensione dello stack_a (in questo caso) verrà manipolata durante l'esecuzione della funzione essa sarà utilizzata in molti modi, è il cuore del programma 

int count_r, come suggerisce il nome questa variabile definisce il numero di rotate o reverse rotate da fare (in base alle circostanze.

Passiamo alle variabili:

int pivot, è il numero che in un ipotico stack ordinato si trova in mezzo ad esso (tipo uno stack di 1 3 7 9 11 21 avrà 7 come pivot).

int numbers, tiene conto del valore dim nel caso venga manipolato o cambiato nel corso del codice la si può trattare come una flag per la dimensione dei miei stack

Ok ora che abbiamo tolto la parte difficile è ora del codice, allora il primo if controlla se l'array è ordinato (in ordine crescente), ma perché questo? beh questa funzione è piuttosto particolare infatti è ricorsiva e questo controllo mi serve per terminarla.

Abbiamo il controllo della dimensione che serve a definire se fare o no un ordinamento da 3 numeri o meno (vengono coperte varie casistiche)

in seguito controlliamo che il pivot sia stato  trovato o che le mosse r siano ancora da fare e così allo stesso tempo troviamo il pivot.

questo controllo del while è piuttosto particolare ma appena ci si pensa ha senso

```c
while (dim != numbers / 2 + numbers % 2)
```

Praticamente sto controllo serve a determinare se il nostro stack ha raggiunto il valore per il quale i numeri inferiori al pivot siano stati pushati, ma perché il numbers % 2? beh nel caso il nostro stack sia di dimensione dispari non rischieremo di fare un giro a vuoto (molto intelligente colui che me l'ha detto).

nel while controlliamo esattamente tuti i numeri sotto al pivot e li pushiamo nello stack_b altrimenti incrementiamo, il numero di ra che eseguiamo finché appunto non troviamo il valore inferiore al pivot.

```c
if (stack->a[0] < pivot && (dim--))
			ft_pb(stack);
		else if (++count_r)
			ft_ra(stack);
```

subito dopo per questione di ordinamento ristemo lo stack con i reverse rotate in modo tale da non variare ulteriormente il numero delle mosse che verranno

```c
while (count_r--)
		ft_rra(stack);
```

Infine returno richiamando non una ma DUE funzioni ricorsivamente in modo tale che inizio anche ad eseguire la funzione che ordinarà lo stack_b (ovvio che per eseguire quick_sort_b la funzion quick_sort_a deve returnare almeno una volta senza ricorsione occhio che sta roba strapazza il cervello)

```c
return (quick_sort_a(stack, numbers / 2 + numbers % 2, 0)
		&& quick_sort_b(stack, numbers / 2, 0));
	return (1);
```

**Piccolo dettaglio**: notare che il sorting di b prende solo numbers / 2 e senza il % 2 questo perché, se nel caso precedente arrotondavamo, qui di sicuro non prendiamo un numero in più e quindi non serbe il % 2

### *int* quick_sort_b(t_stack **stack*, *int* *dim*, *int* *count_r*)

il funzionamento è simili con alcuni piccole differenze

```c
int	quick_sort_b(t_stack *stack, int dim, int count_r)
{
	int	pivot;
	int	numbers;

	if (!count_r && check_sorted_desc(stack->b, dim) == 1)
		while (dim--)
			ft_pa(stack);
	if (dim <= 3)
	{
		sort_3_b(stack, dim);
		return (1);
	}
	numbers = dim;
	if (!partition(&pivot, stack->b, dim))
		return (0);
	while (dim != numbers / 2)
	{
		if (stack->b[0] >= pivot && dim--)
			ft_pa(stack);
		else if (++count_r)
			ft_rb(stack);
	}
	while (numbers / 2 != stack->last_b && count_r--)
		ft_rrb(stack);
	return (quick_sort_a(stack, numbers / 2 + numbers % 2, 0)
		&& quick_sort_b(stack, numbers / 2, 0));
}
```

Possiamo dire che le differenze sono queste:

al contrario di quick_sort_a questo se è ordinato in modo DECRESCENTE non ritornerà nulla ma bensì pusherà tutto il suo contenuto in a, se la dimensione è minore o uguale a 3 avviene un ordinamento tale per cui lo stack_b venga ordinato in modo decrescente.

se SOLO la funzione partition non funziona returna. guarda per numbers /2 nel while per il motivo spiegato sopra. e il check è speculare allo stack_a io guardo i numeri PIÙ GRANDI del mio pivot trovato in stack_b e li ripusho indientro altrimenti rb, il return è uguale perché pure lo stack_b deve avvalersi della ricorsione per funzionare (però lei si fermerà solo quando non si potrà più calcolare un pivot e si alterna con lo stack_a chiamandolo prima, in modo tale che abbia sempre numeri a meno che lo stack_a non sia già ordinato) insomma i due creano una sinergia tale per cui a furia di fare una ricorsione l'ordinamento avverrà in blocchi che vengono suddivisi in continuazione grazie ad un calcolo continuo del pivot e al passarsi dei valori tra a e b.

### *int* sort_3_b(t_stack **stack*, *int* *dim*)

funzione particolare che lavora con la dimensione (che viene splittata e gestita da entrambi gli stack).

```c
int	sort_3_b(t_stack *stack, int dim)
{
	if (dim == 1)
		ft_pa(stack);
	else if (dim == 2)
	{
		if (stack->b[0] < stack->b[1])
			ft_sb(stack);
		while (dim--)
			ft_pa(stack);
	}
	else if (dim == 3)
	{
		while (dim || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (dim == 1 && stack->a[0] > stack->a[1])
				ft_sa(stack);
			else if (dim == 1
				|| (dim >= 2 && stack->b[0] > stack->b[1])
				|| (dim == 3 && stack->b[0] > stack->b[2]))
				dim = when_push(stack, dim, 0);
			else
				ft_sb(stack);

		}
	}
	return (0);
}
```

La funzione serve per gestire la particolarità nello stack_b di essere ordinato in modo decrescente guardando i numeri da pushare o ordinare in più casistiche:

caso dim 1 allora lo stack b verrà svuotato pushando l'ultimo numero nello stack_a

caso dim 2

guardo i valori più grandi e li swappo oppure li pusho

caso 3

nel primo if preparo lo stack_a a ricevere il valore ordinando i primi due valori (notare che il while non si fermerà finche la dimensione è 0 oppure finché i primi valori dello stack_a non sono ordinati).

se no controllo che i valori in b siano ordinati e li pusho oppure devo scambiare il primo con il secondo che sicuro è più grande.

### *int* partition(*int* **pivot*, *int* **stack*, *int* *dim*)

funzione per trovare il pivot cioè il numero che di grandezza si trova esattamente a metà del mio stack utilizza la funzione tmp_sort per capire il valore medio per nello stack e lo assegna alla variabile pivot

```c
int	partition(int *pivot, int *stack, int dim)
{
	int	*tmp;
	int	i;
	int	j;
	//la dim è globale vale per tutti e due gli stack
	tmp = (int *)malloc(sizeof(int) * dim);
	if (!tmp)
		return (0);
	i = 0;
	j = 0;
	while (i < dim)
		tmp[j++] = stack[i++];
	tmp_sort(tmp, dim);
	*pivot = tmp[dim / 2];
	free(tmp);
	return (1);
}
```

### *void*    quick_sort_3_a_b(t_stack **stack*, *int* *dim*)

Funzione che fa gli ultimi controlli nello stack_a e gestisce le varie casistiche di ordinamento dello stack_a è come un fratello alla lontana della funzione

i*nt* sort_3_b(t_stack **stack*, *int* *dim*).

```c
void	quick_sort_3_a_b(t_stack *stack, int dim)
{
	//check dimensione e gestione di stack_a con tre elementi
	if (dim == 3 && stack->last_a == 3)
		three_sorting(stack);
	//stessa cosa con due elementi
	else if (dim == 2)
	{
		if (stack->a[0] > stack->a[1])
			ft_sa(stack);
	}
	//gestione casi dei primi numeri in stack_a
	//ovvio che ci sono anche casisitiche dove
	//per sistemare lo stack_a viene ripushato il tutto
	else if (dim == 3)
	{
		while (dim != 3 || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (dim == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				ft_sa(stack);
			else if (dim == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				dim = when_push(stack, dim, 1);
			else if (stack->a[0] > stack->a[1])
				ft_sa(stack);
			else if (dim++)
				ft_pa(stack);
		}
	}
}
```

primo check semplice che ordina lo stack_a con tre numeri (fortificato da last_a attenzione a non confonderlo per dim), secondo check idem ma con due.

terzo check controllo dei numeri nello stack_a con dimensione 3, che continua con un ciclo finché i primi tre numeri non sono ordinati,

primo if

```c
if (dim == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				ft_sa(stack);
```

Il primo numero è più grande del secondo? swappati (e il terzo numero effettivamente c'è?)

else if

```c
else if (dim == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
```

la dimensione è tre ma i numeri non sono ordinati? pusho in b.

terzo if simile al primo ma occhio (noi guardiamo la dimensione qua no perché non è detto quanto sia grande lo stack occhio eh anche perché il while funzione anche finché dim è diverso da 3)

```c
else if (stack->a[0] > stack->a[1])
				ft_sa(stack);
```

Uiltimo else if gestisce la dimensione dello stack inviandogli i valori indietro avviene per ultimo perché significa che lo stack è pseudo ordinato.

# VOILÀ FINITO UN INFERNO STO PROGETTO UN CASINO CHE MI HA MESSO CON LE SPALLE AL MURO E MI HA FATTO DEPRIMERE

Non è ancora finita devo gestire i leaks:

Aggiustati alcuni leaks generali manca il caso con un argomento

fatto tutto pronto al push