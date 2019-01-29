public void Solution()
        {
            int[] test = new int[] { 2,2,6,6,1,1,10,1,0 };

            QuickSort(test);
        }


        private void QuickSort(int[] ipt)
        {
            _quickSort(ipt, 0, ipt.Length - 1);
        }

        private void _quickSort(int[] ipt, int start, int end)
        {
            int len = end - start + 1;
            if (len == 2 && ipt[start] > ipt[start + 1])
            {
                int _tmp = ipt[start];
                ipt[start] = ipt[start + 1];
                ipt[start + 1] = _tmp;
            }
            else if (len > 2)
            {
                int pivot = ipt[start];
                int lm = start + 1;
                int rm = end;

                while (lm < rm)
                {
                    if (ipt[lm] > pivot && ipt[rm] < pivot)
                    {
                        int _tmp = ipt[lm];
                        ipt[lm] = ipt[rm];
                        ipt[rm] = _tmp;
                    }
                    if (ipt[lm] <= pivot)
                    {
                        lm++;
                    }
                    if (ipt[rm] >= pivot)
                    {
                        rm--;
                    }
                }

                if (lm == rm)
                {
                    if (ipt[lm] > pivot)
                    {
                        for (int i = start + 1; i < lm; i++)
                        {
                            ipt[i - 1] = ipt[i];
                        }
                        ipt[lm - 1] = pivot;
                        _quickSort(ipt, start, lm - 2);
                        _quickSort(ipt, lm, end);
                    }
                    else
                    {
                        for (int i = start + 1; i < lm + 1; i++)
                        {
                            ipt[i - 1] = ipt[i];
                        }
                        ipt[lm] = pivot;
                        _quickSort(ipt, start, lm - 1);
                        _quickSort(ipt, lm + 1, end);
                    }
                }
                else
                {
                    for (int i = start + 1; i < lm; i++)
                    {
                        ipt[i - 1] = ipt[i];
                    }
                    ipt[lm - 1] = pivot;
                    _quickSort(ipt, start, lm - 2);
                    _quickSort(ipt, lm, end);
                }
            }
        }

        
        public void BinarySearch(int key, int[] ipt, out int idx, out bool exist)
        {

        }
