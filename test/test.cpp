#include <stdio.h> 

#include <iostream> 

   

// libeventͷ�ļ� 

#include <event.h> 

using namespace std; 

// ��ʱ�¼��ص����� 

void onTime(int sock, short event, void*arg) 

{ 

  cout << "Game Over!"<< endl; 

 

  struct timeval tv; 

  tv.tv_sec = 1; 

  tv.tv_usec = 0; 

  // ������Ӷ�ʱ�¼�����ʱ�¼�������Ĭ���Զ�ɾ���� 

  event_add((event*)arg, &tv); 

} 

int main() 

{ 
	
	// ��ʼ�� 
	
	event_init(); 
	
	
	
	event evTime; 
	
	// ���ö�ʱ�¼� 
	
	evtimer_set(&evTime, onTime, &evTime); 
	
	
	
	timeval tv; 
	
	tv.tv_sec = 1; 
	
	tv.tv_usec = 0; 
	
	// ��Ӷ�ʱ�¼� 
	
	event_add(&evTime, &tv); 
	
	
	
	// �¼�ѭ�� 
	
	event_dispatch(); 
	
	
	
	return 0; 
	
}