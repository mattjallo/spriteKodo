#include "Packing.h"

RP_Node::RP_Node()
{
    this->image = NULL;
    this->left_child = NULL;
    this->right_child = NULL;
}

RP_Node* RP_Node::Insert(CSourceImage* img)
{
    if(this->left_child!=NULL && this->right_child!=NULL)
    {
        RP_Node* newNode = this->left_child->Insert(img);
        if(newNode!=NULL)
            return newNode;
        return this->right_child->Insert(img);
    }
    else
    {
        if(this->image!=NULL)
            return NULL;
        
        //too small?
        if( (img->GetHeight() > this->height) || (img->GetWidth() > this->width))
            return NULL;
            
        //accept?
        if( (img->GetHeight() == this->height) && (img->GetWidth() == this->width))
        {
            this->image = img;
            return this;
        }
        
        //split
        this->left_child = new RP_Node();
        this->right_child = new RP_Node();
        
        int dw = this->width - img->GetWidth();
        int dh = this->height - img->GetHeight();
        
        if(dw > dh)
        {
            this->left_child->left = this->left;
            this->left_child->top = this->top;
            this->left_child->width = img->GetWidth();
            this->left_child->height = this->height;
            
            this->right_child->left = this->left + img->GetWidth() + 1;
            this->right_child->top = this->top;
            this->right_child->width = dw;
            this->right_child->height = this->height;
        }
        else
        {
            this->left_child->left = this->left;
            this->left_child->top = this->top;
            this->left_child->width = this->width;
            this->left_child->height = img->GetHeight();
            
            this->right_child->left = this->left;
            this->right_child->top = this->top + img->GetHeight() + 1;
            this->right_child->width = this->width;
            this->right_child->height = dh;
        }
        
        return left_child->Insert(img);
    }
}

bool RP_Node::Unwind()
{
    if(this->left_child == NULL || this->right_child == NULL)
    {
        if(this->image != NULL)
        {
            this->image->SetLeft(this->left);
            this->image->SetTop(this->top);
        }
        return true;
    }
    else
    {
        if(this->left_child->Unwind())
            delete left_child;
        if(this->right_child->Unwind())
            delete right_child;
        
        if(this->image != NULL)
        {
            this->image->SetLeft(this->left);
            this->image->SetTop(this->top);
        }
        return true;
    }
}