#include <stdio.h> 

#include <iostream> 

   

// libeventͷ�ļ� 

#include <event.h> 

using namespacestd; 

// ��ʱ�¼��ص����� 

void onTime(int sock, short event, void*arg) 

{ 

  cout << "Game Over!"<< endl; 

 

  structtimeval tv; 

  tv.tv_sec = 1; 

  tv.tv_usec = 0; 

  // �������Ӷ�ʱ�¼�����ʱ�¼�������Ĭ���Զ�ɾ���� 

  event_add((structevent*)arg, &tv); 

} 

intmain() 

{ 
	
	// ��ʼ�� 
	
	event_init(); 
	
	
	
	structevent evTime; 
	
	// ���ö�ʱ�¼� 
	
	evtimer_set(&evTime, onTime, &evTime); 
	
	
	
	structtimeval tv; 
	
	tv.tv_sec = 1; 
	
	tv.tv_usec = 0; 
	
	// ���Ӷ�ʱ�¼� 
	
	event_add(&evTime, &tv); 
	
	
	
	// �¼�ѭ�� 
	
	event_dispatch(); 
	
	
	
	return0; 
	
}