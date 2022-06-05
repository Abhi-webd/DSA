Node even=new Node(-1);

        Node temp=head;

        Node temp1=even;

        Node odd=new Node(-1);

        Node temp2=odd;

        while(temp!=null){

            if(temp.data%2==0){

                temp1.next=temp;

                temp1=temp1.next;

            }

            else{

                temp2.next=temp;

                temp2=temp2.next;

            }

            temp=temp.next;

    }

    temp2.next=null;

    temp1.next=odd.next;

    head=even.next;

    return head;

