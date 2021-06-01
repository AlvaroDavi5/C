#include <stdio.h>
#include <stdlib.h>


/* estados da maquina */
typedef enum
{
	Idle_State,
	Card_Inserted_State,
	Pin_Entered_State,
	Option_Selected_State,
	Amount_Entered_State,
	last_State
} eSystemState;

/* eventos possiveis */
typedef enum
{
	Card_Insert_Event,
	Pin_Enter_Event,
	Option_Selection_Event,
	Amount_Enter_Event,
	Amount_Dispatch_Event,
	GoAway_Event,
	last_Event
} eSystemEvent;

/* typedef de vetor 2d */
typedef eSystemState (*const afEventHandler[last_State][last_Event])(void);

/* typedef de ponteiro para funcao */
typedef eSystemState (*pfEventHandler)(void);


/* prototipo da funcao leitura */
eSystemEvent ReadEvent();

/* prototipo de manipuladores de eventos */
eSystemState AmountDispatchHandler(void)
{
	printf ("%s \n","Entregando o dinheiro!");
	return Idle_State;
}

eSystemState EnterAmountHandler(void)
{
	printf ("%s \n","Perguntando o valor do saque!");
	return Amount_Entered_State;
}

eSystemState OptionSelectionHandler(void)
{
	printf ("%s \n","Perguntado se saque ou deposito!");
	return Option_Selected_State;
}

eSystemState EnterPinHandler(void)
{
	printf ("%s \n","Perguntado a senha!");
	return Pin_Entered_State;
}

eSystemState InsertCardHandler(void)
{
	printf ("%s \n","Pedindo para inserir o cartão!");
	return Card_Inserted_State;
}

eSystemState GoAwayHandler(void)
{
	printf ("%s \n","Terminando...");
	exit(0);
}

int main(int argc, char *argv[])
{
	/* tabela para definir estados validos e eventos da maquina */
	static afEventHandler StateMachine =
	{
		[Idle_State] =
		{
			[Card_Insert_Event]= InsertCardHandler,
			[GoAway_Event]= GoAwayHandler 
		},
		[Card_Inserted_State] =
		{
			[Pin_Enter_Event] = EnterPinHandler 
		},
		[Pin_Entered_State] =
		{
			[Option_Selection_Event] = OptionSelectionHandler
		},
		[Option_Selected_State] =
		{
			[Amount_Enter_Event] = EnterAmountHandler
		},
		[Amount_Entered_State] =
		{
			[Amount_Dispatch_Event] = AmountDispatchHandler
		},
	};

	eSystemState eNextState = Idle_State;

	while(1)
	{
		// assume api to read the next event
		eSystemEvent eNewEvent = ReadEvent();
		//Check NULL pointer and array boundary
		if(( eNextState < last_State) && (eNewEvent < last_Event) && StateMachine[eNextState][eNewEvent]!= NULL)
		{
			// function call as per the state and event and return the next state of the finite state machine
			eNextState = (*StateMachine[eNextState][eNewEvent])();
		}
		else
		{
			//Invalid
		}
	}
	return 0;
}

eSystemEvent ReadEvent()
{   int opcao;
	printf("%s \n %s \n %s \n %s \n %s \n %s \n %s \n :",
		"Digite sua opção: ",
		" 1: Inserir Cartao",
		" 2: Entrar com senha",
		" 3: Selecionar Saque ",
		" 4: Digitar valor",
		" 5: Pegar o dinheiro",
		" 6: Ir embora");

	while (1)
	{   scanf ("%d", &opcao);
		switch (opcao)
		{
			case 1:
			{	return Card_Insert_Event;
				break;
			}
			case 2:
			{	return Pin_Enter_Event;
				break;
			}
			case 3:
			{	return Option_Selection_Event;
				break;
			}
			case 4:
			{	return Amount_Enter_Event;
				break;
			}
			case 5:
			{	return Amount_Dispatch_Event;
				break;
			}
			case 6:
			{	return GoAway_Event;
				break;
			}
		}
	}	
	
}
