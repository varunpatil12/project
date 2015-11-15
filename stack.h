/*****************************************************************************
 * Copyright (C) VARUN PATIL varunpat75@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
void qinit(stack *s)
{
  s->i = 0;
}
void push(stack *s, nodestore* x)
{
  s->a[s->i++] = x;
}
nodestore* pop(stack *s)
{
  s->a[s->i--];
  return s->a[s->i];
}
int empty(stack *s)
{
  return s->i == 0;
}
void issueinit(issuestack *s)
{
  s->i = 0;
}
void issuepush(issuestack *s, issuestore* x)
{
  s->a[s->i++] = x;
}
issuestore* issuepop(issuestack *s)
{
  s->a[s->i--];
  return s->a[s->i];
}
int issueempty(issuestack *s)
{
  return s->i == 0;
}

